_Pragma("once");
#include <QObject>
#include <QStandardPaths>
#include <QDir>
#include <QVariantMap>

#if defined(Q_OS_WINDOWS) && defined(_MSC_VER)
    #ifdef QZeroZanyUI
        #define QZERO_API Q_DECL_EXPORT
    #else
        #define QZERO_API Q_DECL_IMPORT
    #endif
#else
    #define QZERO_API
#endif

class QZERO_API ThemesSetting : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentThemeName READ currentThemeName WRITE setCurrentThemeName NOTIFY currentThemeNameChanged);
    Q_PROPERTY(QVariantMap currentTheme READ currentTheme WRITE setCurrentTheme NOTIFY currentThemeChanged);

public:
    auto instance() noexcept -> ThemesSetting*;

    ~ThemesSetting() noexcept = default;

    Q_INVOKABLE QVariantMap currentTheme() const;
    Q_INVOKABLE void        setCurrentTheme(const QVariantMap& _currentTheme);

    Q_INVOKABLE QString currentThemeName() const;
    Q_INVOKABLE void    setCurrentThemeName(const QString& _currentThemeName);

private:
    explicit(true) ThemesSetting(QObject* _parent = nullptr);

    auto init() noexcept -> void;

    auto getThemesList() noexcept -> QStringList;

    auto setLightTheme() noexcept -> void;

    auto setDarkTheme() noexcept -> void;

    auto connectSignal2Slot() noexcept -> void;

Q_SIGNALS:
    void currentThemeNameChanged();

    void currentThemeChanged();

private Q_SLOTS:
    void onCurrentThemeNameChanged();

    void onCurrentThemeChanged();

private:
    QDir        m_themesDir{QDir{QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)}.filePath("Themes")};
    QStringList m_themesList{};
    QVariantMap m_currentTheme{};
    QString     m_currentThemeName{};

private:
    QVariantMap m_lightTheme{
        {"BackgroundColor", "#f0efee"},
        {"TextColor", "#0e0d0d"},
        {"ButtonColor", "#FFFFFF"},
        {"ElementColor", "#FFFFFF"},
        {"LabelColor", "transparent"},
    };

    QVariantMap m_darkTheme{
        {"BackgroundColor", "#f0efee"},
        {"TextColor", "#0e0d0d"},
        {"ButtonColor", "#FFFFFF"},
        {"ElementColor", "#FFFFFF"},
        {"LabelColor", "transparent"},
    };
};
