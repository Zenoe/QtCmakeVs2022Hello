#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class LeftPanel : public QWidget
{
    Q_OBJECT

public:
    explicit LeftPanel(QWidget* parent = nullptr);
    ~LeftPanel();

signals:
    void button1Clicked();
    void button2Clicked();

private:
    Ui::Form* ui;
};