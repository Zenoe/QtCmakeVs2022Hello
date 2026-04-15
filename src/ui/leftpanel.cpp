#include "leftpanel.h"
#include "ui_left.h"

LeftPanel::LeftPanel(QWidget* parent)
    : QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    // Connect buttons to signals (recommended pattern)
    connect(ui->pushButton, &QPushButton::clicked,
        this, &LeftPanel::button1Clicked);

    connect(ui->pushButton_2, &QPushButton::clicked,
        this, &LeftPanel::button2Clicked);
}

LeftPanel::~LeftPanel()
{
    delete ui;
}