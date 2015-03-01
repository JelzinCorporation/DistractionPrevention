#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qicon.h>
#include <qfile.h>
#include <qmenu.h>
#include <iostream>

constexpr size_t preventionUnpreventionMenuItemIndex = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    systemTray = QSharedPointer<QSystemTrayIcon>::create(QIcon("://images/distrprev.png"));
    systemTray->setVisible(true);

    systemTrayMenu = QSharedPointer<QMenu>::create(this);
    systemTray->setContextMenu(&(*systemTrayMenu));

    addMenuItem("Let's Go!", &MainWindow::preventUnprevent);
    addMenuItem("Settings", &MainWindow::showSettings);

    for (auto website : predefinedWebsites) {
        blockListItems.push_back(QSharedPointer<QListWidgetItem>::create(website, ui->listWidget));
    }

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addBlockListItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::preventUnprevent() {
    if (preventing) {
        std::cout << "Stop preventing!";
        systemTrayMenuActions[preventionUnpreventionMenuItemIndex]->setText("Let's Go!");
        preventing = false;
    } else {
        std::cout << "Start preventing!";
        systemTrayMenuActions[preventionUnpreventionMenuItemIndex]->setText("Okay, enough!");
        preventing = true;
    }
    //QFile::rename("/etc/hosts", "/etc/hostsOriginalSecure");
}

void MainWindow::showSettings() {
    std::cout << "Show settings dialog here" << std::endl;
    this->show();
}

void MainWindow::addBlockListItem() {
    blockListItems.push_back(QSharedPointer<QListWidgetItem>::create(ui->lineEdit->text(), ui->listWidget));
}

void MainWindow::addMenuItem(QString caption, void (MainWindow::*slot)()) {
    auto menuItem = QSharedPointer<QAction>::create(caption, this);
    systemTrayMenu->addAction(&(*menuItem));
    QObject::connect(&(*menuItem), &QAction::triggered, this, slot);

    systemTrayMenuActions.push_back(menuItem);
}
