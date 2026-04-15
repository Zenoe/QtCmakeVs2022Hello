#pragma once

#include <QJsonObject>
#include <QString>

class ConfigManager
{
public:
    static ConfigManager& instance();

    void load();
    void save();

    QJsonValue get(const QString& key, const QJsonValue& def = {}) const;
    void set(const QString& key, const QJsonValue& value);

private:
    ConfigManager();
    QString configPath;
    QJsonObject data;
};
