_Pragma("once");
#include <QObject>
#include <QtQml>
#include <QVariantMap>

#include "Themes.hpp"

#if defined(Q_OS_WINDOWS) && defined(_MSC_VER)
    #ifdef QZeroZanyUI
        #define QZERO_API Q_DECL_EXPORT
    #else
        #define QZERO_API Q_DECL_IMPORT
    #endif
#else
    #define QZERO_API
#endif

class QJSEngine;
class QQmlEngine;

class QZERO_API ThemeManager : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT
    Q_PROPERTY(QVariantMap currentTheme READ currentTheme WRITE setCurrentTheme NOTIFY currentThemeChanged);

public:
    static ThemeManager* create(QQmlEngine*, QJSEngine*);

    ~ThemeManager() noexcept = default;

    Q_INVOKABLE QVariantMap currentTheme() const;
    Q_INVOKABLE void        setCurrentTheme(const QVariantMap& _currentTheme);

private:
    explicit(true) ThemeManager(QObject* _parent = nullptr);

    auto init() noexcept -> void;

    auto connectSignal2Slot() noexcept -> void;

Q_SIGNALS:

    void currentThemeChanged();

private Q_SLOTS:

private:
    QVariantMap m_currentTheme{};
};
