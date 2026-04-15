#pragma once

#include <QMainWindow>

class QLabel;
class QPushButton;
class CanvasView;
class LeftPanel;
class RightPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override = default;

private:
    QLabel* statusLabel;
    QPushButton* testButton;

	void onLeftButton1Clicked();
    void onTestClicked();
};
