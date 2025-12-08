#include "ThemeManager.h"
#include <QJSEngine>
#include <QQmlEngine>

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

ThemeManager* ThemeManager::create(QQmlEngine*, QJSEngine*)
{
    static ThemeManager themeManager{};
    return &themeManager;
}

ThemeManager::ThemeManager(QObject* _parent) : QObject{_parent}
{
    std::invoke(&ThemeManager::connectSignal2Slot, this);
    std::invoke(&ThemeManager::init, this);
}

auto ThemeManager::init() noexcept -> void
{
    this->setCurrentTheme(Themes::lightTheme);
}

auto ThemeManager::connectSignal2Slot() noexcept -> void
{
}
