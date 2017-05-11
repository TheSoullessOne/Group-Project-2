#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
enum MainMenPages{
    LOGIN,
    ADMIN,
    VIEW,
    REVIEWS,
    HELP,
    CONTACT
};
enum AdminPages{
    ADMIN_MEN,
    ADD_SHAPE,
    REM_SHAPE,
    EDIT
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Main_Menu->setCurrentIndex(LOGIN);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//-------------------------------------------------------
//Main Menu Stuff
//-------------------------------------------------------
void MainWindow::on_loginEnterButton_clicked()
{
    ui->Main_Menu->setCurrentIndex(ADMIN);
    ui->Admin_Pages->setCurrentIndex(ADMIN_MEN);
}
void MainWindow::on_loginHelpButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(HELP);
}
void MainWindow::on_loginRevButt_clicked()
{
 ui->Main_Menu->setCurrentIndex(REVIEWS);
}

//-------------------------------------------------------
//ADMIN EDIT PAGES STUFF
//-------------------------------------------------------
//BUTTON TO GO TO ADD SHAPE PAGE
void MainWindow::on_addShapeButt_clicked()
{
    ui->Admin_Pages->setCurrentIndex(ADD_SHAPE);
}
//BUTTON TO DELETE SHAPE PAGE
void MainWindow::on_remShapeButt_clicked()
{
    ui->Admin_Pages->setCurrentIndex(REM_SHAPE);
}
//BUTTON TO EDIT SHAPE PAGE
void MainWindow::on_editShapeButt_clicked()
{
    ui->Admin_Pages->setCurrentIndex(EDIT);
}
//BUTTON TO VIEW PAGE
void MainWindow::on_viewShapeButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(VIEW);
}
//BUTTON TO GO TO CONTACT PAGE FROM ADMIN PAGE
void MainWindow::on_adminContButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(CONTACT);
}
//BUTTON TO HELP PAGE FROM ADMIN PAGE
void MainWindow::on_adminHelpButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(HELP);
}
//BUTTON TO GO TO ADMIN MAIN FROM ADMIN PAGES
//BACK BUTTON FROM ADD PAGE
void MainWindow::on_back2AdminButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(ADMIN);
    ui->Admin_Pages->setCurrentIndex(ADMIN_MEN);
}
//BACK BUTTON FROM REM PAGE
void MainWindow::on_back2AdminButt_2_clicked()
{
    ui->Main_Menu->setCurrentIndex(ADMIN);
    ui->Admin_Pages->setCurrentIndex(ADMIN_MEN);
}
//BACK BUTTON FROM EDIT PAGE
void MainWindow::on_back2AdminButt_3_clicked()
{
    ui->Main_Menu->setCurrentIndex(ADMIN);
    ui->Admin_Pages->setCurrentIndex(ADMIN_MEN);
}
//BUTTONN TO GO BACK TO MAIN MENU LOGIN PAGE FROM ADMIN PAGES
void MainWindow::on_adminPageBackButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(LOGIN);
}
//BACK TO REGULAR MAIN MENU PAGES
//   basic view pages
//----------------------------------------
//GO TO CONTACT PAGE FROM VIEW BASIC PAGE
void MainWindow::on_viewContButt_clicked()
{
 ui->Main_Menu->setCurrentIndex(CONTACT);
}
//GO BACK TO MAIN LOG IN PAGE FROM VIEW BASIC PAGE
void MainWindow::on_basicPagebackButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(LOGIN);
}
//GO TO HELP PAGE FROM BASIC VIEW PAGE
void MainWindow::on_viewHelpButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(HELP);
}
//  REVIEW PAGES
//----------------------------------------
//GO TO CONTACT PAGE FROM REV PAGE
void MainWindow::on_reviewContButt_clicked()
{
 ui->Main_Menu->setCurrentIndex(CONTACT);
}
//GO TO HELP PAGE FROM THE REVIEW PAGE
void MainWindow::on_reviewHelpButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(HELP);
}
//GO BACK TO THE MAIN LOGIN PAGE FROM THE REV PAGE
void MainWindow::on_reviewPageBackButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(LOGIN);
}

//HELP PAGES
//----------------------------------------------
//GO TO THE CONTACT PAGE FROM THE HELP PAGE
void MainWindow::on_helpContButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(CONTACT);
}
//GO BACK TO THE MAIN LOGIN WINDOW FROM THE HELP PAGE
void MainWindow::on_helpBackButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(LOGIN);
}

//CONTACT PAGES
//--------------------------------------------------
//GO TO THE HELP PAGE FROM CONTACT PAGE
void MainWindow::on_contactHelpButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(HELP);
}
//GO BACK TO THE MAIN MENU FROM THE CONTACT PAGE
void MainWindow::on_contactBackButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(LOGIN);
}

void MainWindow::on_addFromFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Text File (*.txt)");

    qDebug() << fileName;
}
