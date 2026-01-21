#include "ThemesSetting.h"
#include <QSettings>

auto ThemesSetting::instance() noexcept -> ThemesSetting*
{
    ThemesSetting* themesSetting{new ThemesSetting{}};
    return themesSetting;
}

ThemesSetting::ThemesSetting(QObject* _parent) : QObject{_parent}
{
    std::invoke(&ThemesSetting::init, this);
    std::invoke(&ThemesSetting::connectSignal2Slot, this);
}

auto ThemesSetting::init() noexcept -> void
{
    std::invoke(&ThemesSetting::setLightTheme, this);
    std::invoke(&ThemesSetting::setDarkTheme, this);
}

auto ThemesSetting::getThemesList() noexcept -> QStringList
{
    m_themesList.clear();
    for (const QFileInfo& info : m_themesDir.entryInfoList({"*.ini"}, QDir::Files | QDir::NoDotAndDotDot))
    {
        m_themesList << info.baseName();
    }
    return m_themesList;
}

auto ThemesSetting::connectSignal2Slot() noexcept -> void
{
    connect(this, &ThemesSetting::currentThemeNameChanged, this, &ThemesSetting::onCurrentThemeChanged, Qt::AutoConnection);
}

void ThemesSetting::onCurrentThemeChanged()
{
    m_currentTheme.clear();
    QSettings settings{m_themesDir.filePath(QString("%1.ini").arg(this->m_currentThemeName)), QSettings::IniFormat};
    settings.beginGroup("Colors");
    m_currentTheme["BackgroundColor"] = settings.value("BackgroundColor", m_lightTheme["BackgroundColor"]);
    m_currentTheme["TextColor"]       = settings.value("TextColor", m_lightTheme["TextColor"]);
    m_currentTheme["ButtonColor"]     = settings.value("ButtonColor", m_lightTheme["ButtonColor"]);
    m_currentTheme["ElementColor"]    = settings.value("ElementColor", m_lightTheme["ElementColor"]);
    m_currentTheme["LabelColor"]      = settings.value("LabelColor", m_lightTheme["LabelColor"]);
    settings.endGroup();
}

void ThemesSetting::onCurrentThemeNameChanged()
{
}

auto ThemesSetting::setLightTheme() noexcept -> void
{
    QSettings settings{m_themesDir.filePath(QString("%1.ini").arg("Light")), QSettings::IniFormat};
    settings.beginGroup("Colors");
    if (!settings.contains("BackgroundColor"))
    {
        settings.setValue("BackgroundColor", m_lightTheme["BackgroundColor"]);
    }
    if (!settings.contains("TextColor"))
    {
        settings.setValue("TextColor", m_lightTheme["TextColor"]);
    }
    if (!settings.contains("ButtonColor"))
    {
        settings.setValue("ButtonColor", m_lightTheme["ButtonColor"]);
    }
    if (!settings.contains("ElementColor"))
    {
        settings.setValue("ElementColor", m_lightTheme["ElementColor"]);
    }
    if (!settings.contains("LabelColor"))
    {
        settings.setValue("LabelColor", m_lightTheme["LabelColor"]);
    }
    settings.endGroup();
    settings.sync();
}

auto ThemesSetting::setDarkTheme() noexcept -> void
{
    QSettings settings{m_themesDir.filePath(QString("%1.ini").arg("Dark")), QSettings::IniFormat};
    settings.beginGroup("Colors");
    if (!settings.contains("BackgroundColor"))
    {
        settings.setValue("BackgroundColor", m_darkTheme["BackgroundColor"]);
    }
    if (!settings.contains("TextColor"))
    {
        settings.setValue("TextColor", m_darkTheme["TextColor"]);
    }
    if (!settings.contains("ButtonColor"))
    {
        settings.setValue("ButtonColor", m_darkTheme["ButtonColor"]);
    }
    if (!settings.contains("ElementColor"))
    {
        settings.setValue("ElementColor", m_darkTheme["ElementColor"]);
    }
    if (!settings.contains("LabelColor"))
    {
        settings.setValue("LabelColor", m_darkTheme["LabelColor"]);
    }
    settings.endGroup();
    settings.sync();
}

QVariantMap ThemesSetting::currentTheme() const
{
    return this->m_currentTheme;
}

void ThemesSetting::setCurrentTheme(const QVariantMap& _currentTheme)
{
    if (m_currentTheme == _currentTheme)
    {
        return;
    }
    m_currentTheme = _currentTheme;
    Q_EMIT this->currentThemeChanged();
}

QString ThemesSetting::currentThemeName() const
{
    return this->m_currentThemeName;
}

void ThemesSetting::setCurrentThemeName(const QString& _currentThemeName)
{
    if (m_currentThemeName == _currentThemeName)
    {
        return;
    }
    m_currentThemeName = _currentThemeName;
    Q_EMIT this->currentThemeNameChanged();
}
