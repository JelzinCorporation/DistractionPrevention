#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QSystemTrayIcon>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void addMenuItem(QString caption, void (MainWindow::*slot)());
    void addBlockListItem();

    QSharedPointer<QSystemTrayIcon> systemTray;
    QSystemTrayIcon systemTray2;
    QSharedPointer<QMenu> systemTrayMenu;

    QVector<QSharedPointer<QAction> > systemTrayMenuActions;

    bool preventing = false;

    const QVector<QString> predefinedWebsites = {"www.facebook.de", "www.9gag.com"};
    QVector<QSharedPointer<QListWidgetItem> > blockListItems;

private slots:
    void preventUnprevent();
    void showSettings();
};

#endif // MAINWINDOW_H
