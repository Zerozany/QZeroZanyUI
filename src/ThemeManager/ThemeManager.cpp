#include "ThemeManager.h"
#include <QJSEngine>
#include <QQmlEngine>
#include <QDir>

QVariantMap ThemeManager::currentTheme() const
{
    return m_currentTheme;
}

void ThemeManager::setCurrentTheme(const QVariantMap& _currentTheme)
{
    if (m_currentTheme == _currentTheme)
    {
        return;
    }
    m_currentTheme = _currentTheme;
    Q_EMIT this->currentThemeChanged();
}

QVariantMap ThemeManager::fontSize() const
{
    return m_fontSize;
}

void ThemeManager::setFontSize(const QVariantMap& _fontSize)
{
    if (m_fontSize == _fontSize)
    {
        return;
    }
    m_fontSize = _fontSize;
    Q_EMIT this->fontSizeChanged();
}

QVariantMap ThemeManager::styleSize() const
{
    return m_styleSize;
}

void ThemeManager::setStyleSize(const QVariantMap& _styleSize)
{
    if (m_styleSize == _styleSize)
    {
        return;
    }
    m_styleSize = _styleSize;
    Q_EMIT this->styleSizeChanged();
}

ThemeManager* ThemeManager::create(QQmlEngine*, QJSEngine*)
{
    static ThemeManager* themeManager{new ThemeManager{}};
    return themeManager;
}

ThemeManager::ThemeManager(QObject* _parent) : QObject{_parent}
{
    std::invoke(&ThemeManager::connectSignal2Slot, this);
    std::invoke(&ThemeManager::init, this);
}

auto ThemeManager::init() noexcept -> void
{
    this->setCurrentTheme(Themes::lightTheme);
    this->setFontSize(Themes::fontSize);
    this->setStyleSize(Themes::styleSize);
}

auto ThemeManager::connectSignal2Slot() noexcept -> void
{
}
