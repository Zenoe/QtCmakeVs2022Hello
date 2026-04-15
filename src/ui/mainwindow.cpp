#include "mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QSplitter>
#include "leftpanel.h"
#include "config_manager.h"
#include "logger.h"

/*MainWindow
©¸©¤©¤ centralWidget
©¸©¤©¤ QVBoxLayout
©À©¤©¤ TopBar(buttons / actions)
©À©¤©¤ Splitter(MAIN CONTENT)
©¦     ©À©¤©¤ LeftPanel(navigation)
©¦     ©¸©¤©¤ RightPanel(main view)
©¸©¤©¤ StatusBar(optional or Qt built - in)
*/
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    auto* central = new QWidget;
    auto* mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // ===== Top Bar (optional, cleaner than mixing in main area) =====
    auto* topBar = new QWidget;
    auto* topLayout = new QHBoxLayout(topBar);
    topLayout->setContentsMargins(8, 8, 8, 8);

    testButton = new QPushButton("Test Config + Log");
    topLayout->addWidget(testButton);
    topLayout->addStretch();  // push button to left

    mainLayout->addWidget(topBar);

    // ===== Main Splitter =====
    auto* splitter = new QSplitter;

    // Left panel (navigation)
    auto* left = new LeftPanel;

    // Right panel (main content container)
    auto* right = new QWidget;
    auto* rightLayout = new QVBoxLayout(right);
    rightLayout->setContentsMargins(10, 10, 10, 10);

    statusLabel = new QLabel("Ready");
    rightLayout->addWidget(statusLabel);
    rightLayout->addStretch();

    splitter->addWidget(left);
    splitter->addWidget(right);

    // Set proportions (important!)
    splitter->setStretchFactor(0, 0); // left fixed-ish
    splitter->setStretchFactor(1, 1); // right expands

    splitter->setSizes({ 250, 800 }); // initial width

    mainLayout->addWidget(splitter);

    resize(1200, 800);

    splitter->setStretchFactor(1, 1);
    splitter->setSizes({ 250, 800 });

    // ===== Final =====
    setCentralWidget(central);
    setWindowTitle("WireGuardQt");

    connect(left, &LeftPanel::button1Clicked, this, [this]() {
        onLeftButton1Clicked();
    });
    connect(testButton, &QPushButton::clicked, this, [this]() {
        onTestClicked();
    });
}

void MainWindow::onLeftButton1Clicked()
{
    LOG_INFO("Left panel button 1 clicked");
    statusLabel->setText("Left Button 1 Clicked");
}
void MainWindow::onTestClicked()
{
    auto& cfg = ConfigManager::instance();

    QString value = cfg.get("example_key", "default_value").toString();

    LOG_INFO("Button clicked, config value: {}", value.toStdString());

    statusLabel->setText("Config: " + value);
}
