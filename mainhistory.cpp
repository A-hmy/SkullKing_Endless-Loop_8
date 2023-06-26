#include "mainhistory.h"
#include "ui_mainhistory.h"
#include <QVBoxLayout>
#include <QScrollArea>

MainHistory::MainHistory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainHistory)
{
    ui->setupUi(this);
    // Create a QVBoxLayout for the main widget
        QVBoxLayout *main_layout = new QVBoxLayout(this);
        // Create a QScrollArea
        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setWidgetResizable(true);
        // Create a QWidget that will contain dynamically added buttons
        QWidget *buttonsWidget = new QWidget();
        scrollArea->setWidget(buttonsWidget);
        buttonsWidget->setStyleSheet("background-color: red;");

        // Create a QVBoxLayout for the QWidget
        QVBoxLayout *buttonsLayout = new QVBoxLayout(buttonsWidget);
        // Add the QScrollArea to your main widget or layout
        main_layout->addWidget(scrollArea);
}

MainHistory::~MainHistory()
{
    delete ui;
}
