#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"
#include <QWidget>
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "text.h"
#include <QTextStream>
#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void centerAndResize();

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

    void on_addFromFileButton_clicked();
    void on_loginConctButt_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    Qt::GlobalColor convertColor(QString);

    Qt::PenStyle convertPenStyle(QString);

    Qt::PenCapStyle convertPenCapStyle(QString);

    Qt::PenJoinStyle convertPenJoinStyle(QString);

    Qt::BrushStyle convertBrushStyle(QString);

    Qt::AlignmentFlag convertAlignmentFlag(QString);

    QFont::Style convertTextFontStyle(QString);

    QFont::Weight convertTextFontWeight(QString);

    void on_maintenanceBackButt_clicked();

    void on_maintenanceButt_clicked();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
};

#endif // MAINWINDOW_H
