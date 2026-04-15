#include "config_manager.h"

#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>

ConfigManager& ConfigManager::instance()
{
    static ConfigManager inst;
    return inst;
}

ConfigManager::ConfigManager()
{
    configPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(configPath);

    configPath += "/config.json";

    load();
}

void ConfigManager::load()
{
    QFile f(configPath);
    if (!f.exists()) {
        data["example_key"] = "hello";
        save();
        return;
    }

    if (f.open(QIODevice::ReadOnly)) {
        data = QJsonDocument::fromJson(f.readAll()).object();
    }
}

void ConfigManager::save()
{
    QFile f(configPath);
    if (f.open(QIODevice::WriteOnly)) {
        f.write(QJsonDocument(data).toJson());
    }
}

QJsonValue ConfigManager::get(const QString& key, const QJsonValue& def) const
{
    return data.contains(key) ? data[key] : def;
}

void ConfigManager::set(const QString& key, const QJsonValue& value)
{
    data[key] = value;
    save();
}
