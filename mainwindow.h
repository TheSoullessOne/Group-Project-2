#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QMainWindow>
#include "renderarea.h"
#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>

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
//    void shapeChanged();
//    void penChanged();
//    void brushChanged();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
};

#endif // MAINWINDOW_H
