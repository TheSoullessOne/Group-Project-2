#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loginEnterButton_clicked();

    void on_loginHelpButt_clicked();

    void on_addShapeButt_clicked();

    void on_remShapeButt_clicked();

    void on_editShapeButt_clicked();

    void on_viewShapeButt_clicked();

    void on_adminContButt_clicked();

    void on_adminHelpButt_clicked();

    void on_back2AdminButt_clicked();

    void on_back2AdminButt_2_clicked();

    void on_back2AdminButt_3_clicked();

    void on_loginRevButt_clicked();

    void on_adminPageBackButt_clicked();

    void on_viewContButt_clicked();

    void on_basicPagebackButt_clicked();

    void on_viewHelpButt_clicked();

    void on_reviewContButt_clicked();

    void on_reviewHelpButt_clicked();

    void on_reviewPageBackButt_clicked();

    void on_helpContButt_clicked();

    void on_helpBackButt_clicked();

    void on_contactHelpButt_clicked();

    void on_contactBackButt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
