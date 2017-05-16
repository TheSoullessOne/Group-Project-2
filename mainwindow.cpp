#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QStyle>
#include <QSize>
#include <QApplication>
#include <QDesktopWidget>

//PAGES
//enums for the pages
enum MainMenPages{
    LOGIN,
    ADMIN,
    VIEW,
    REVIEWS,
    HELP,
    CONTACT,
    MAINTENANCE
};
enum AdminPages{
    ADMIN_MEN,
    ADD_SHAPE,
    REM_SHAPE,
    EDIT
};
enum HelpPages{
    HELP_MEN,
    HELP_ADD,
    HELP_REM,
    HELP_EDIT,
    HELP_VIEW
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->renderArea = new RenderArea();
    ui->addRender = new RenderArea();
    ui->setupUi(this);
    ui->Main_Menu->setCurrentIndex(LOGIN);
}

MainWindow::~MainWindow()
{
    OutputToFile();
    delete ui;
}

////-------------------------------------------------------
////Expands the window to 90% and centers it
////-------------------------------------------------------
//void MainWindow::centerAndResize() {
//   // get the dimensions available on this screen, depending on individ computer
//   QSize availableSize = qApp->desktop()->availableGeometry().size();
//   int width = availableSize.width();
//   int height = availableSize.height();
//   qDebug() << "Available dimensions " << width << "x" << height;
//   width = 100;                         // sets width to 90% of the screen size
//   height = 100;                        // sets height to 90% of the screen size
//   qDebug() << "The dimensions are " << width << "x" << height;
//   QSize newSize( width, height );
//   setGeometry(
//       QStyle::alignedRect(
//           Qt::LeftToRight,
//           Qt::AlignCenter,
//           newSize,
//           qApp->desktop()->availableGeometry()
//       )
//   );
//}

//-------------------------------------------------------
//Main Menu Stuff
//-------------------------------------------------------
void MainWindow::on_loginEnterButton_clicked()
{
    ui->Main_Menu->setCurrentIndex(ADMIN);
    ui->Admin_Pages->setCurrentIndex(ADMIN_MEN);
}

void MainWindow::on_loginConctButt_clicked()
{
    ui->Main_Menu->setCurrentIndex(CONTACT);
}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

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
//----------------------------------------
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
//----------------------------------------
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
//----------------------------------------------
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

//OPENS A NEW FILE IN THE ADD FILE PAGE FROM THE ADMIN PAGES
void MainWindow::on_addFromFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QCoreApplication::applicationDirPath(), "Text File (*.txt)");
    QFile file(fileName);
    QTextStream inFile(&file);
    QStringList stringParser;
    QString line;

    QString key;
    QString value;
    int tempId;
    QString shapeType;
    QStringList points;
    Qt::GlobalColor penColor;
    QString penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::GlobalColor brushColor;
    Qt::BrushStyle brushStyle;
    QString textString;
    QColor textColor;
    Qt::AlignmentFlag textAlignment;
    int textPointSize;
    QString textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    while(!inFile.atEnd())  {
        line = inFile.readLine();
        if(line != "")
        {
            stringParser = line.split(":");
            key = stringParser[0];
            value = stringParser[1];
            if(key == "ShapeId")
            {
                value = value.trimmed();
                tempId = value.toInt();
            }
            else if(key == "ShapeType")
            {
                value = value.trimmed();
                shapeType = value;
            }
            else if(key == "ShapeDimensions")
            {
                value = value.trimmed();
                points = value.split(",");
            }
            else if(key == "PenColor")
            {
                value = value.trimmed();
                penColor = this->convertColor(value);
            }
            else if(key == "PenWidth")
            {
                value = value.trimmed();
                penWidth = value;
            }
            else if(key == "PenStyle")
            {
                value = value.trimmed();
                penStyle = this->convertPenStyle(value);
            }
            else if(key == "PenCapStyle")
            {
                value = value.trimmed();
                penCapStyle = this->convertPenCapStyle(value);
            }
            else if(key == "PenJoinStyle")
            {
                value = value.trimmed();
                penJoinStyle = this->convertPenJoinStyle(value);
            }
            else if(key == "BrushColor")
            {
                value = value.trimmed();
                brushColor = this->convertColor(value);
            }
            else if(key == "BrushStyle")
            {
                value = value.trimmed();
                brushStyle = this->convertBrushStyle(value);
            }
            else if(key == "TextString")
            {
                value = value.trimmed();
                textString = value;
            }
            else if(key == "TextColor")
            {
                value = value.trimmed();
                textColor = this->convertColor(value);
            }
            else if(key == "TextAlignment")
            {
                value = value.trimmed();
                textAlignment = this->convertAlignmentFlag(value);
            }
            else if(key == "TextPointSize")
            {
                value = value.trimmed();
                textPointSize = value.toInt();
            }
            else if(key == "TextFontFamily")
            {
                textFontFamily = value;
            }
            else if(key == "TextFontStyle")
            {
                value = value.trimmed();
                textFontStyle = this->convertTextFontStyle(value);
            }
            else if(key == "TextFontWeight")
            {
                value = value.trimmed();
                textFontWeight = this->convertTextFontWeight(value);
            }
        }
        else
        {
            if(shapeType == "Line")
            {
                Line *temp = new Line(points[0].toInt(),
                                     points[1].toInt(),
                                     points[2].toInt(),
                                     points[3].toInt());
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->addThisShape(temp);
            }
            else if(shapeType == "Polyline")
            {
                int indexTwo = 0;
                vector<QPoint> myPoints;
                for(int i = 0; i < points.size() / 2; ++i)
                {
                    myPoints[indexTwo].setX(points[i].trimmed().toInt());
                    ++i;
                    myPoints[indexTwo].setY(points[i].trimmed().toInt());
                    ++indexTwo;
                }
                Polyline *temp = new Polyline(myPoints);
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->getShapeManager()->addShape(temp);
            }
            else if(shapeType == "Polygon")
            {
                int indexTwo = 0;
                vector<QPoint> myPoints;
                for(int i = 0; i < points.size() / 2; ++i)
                {
                    myPoints[indexTwo].setX(points[i].trimmed().toInt());
                    ++i;
                    myPoints[indexTwo].setY(points[i].trimmed().toInt());
                    ++indexTwo;
                }
                Polygon *temp = new Polygon(myPoints);
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->getShapeManager()->addShape(temp);
            }
            else if(shapeType == "Rectangle")
            {
                Rectangle *temp = new Rectangle(points[0].toInt(),
                                               points[1].toInt(),
                                               points[2].toInt(),
                                               points[3].toInt());
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->getShapeManager()->addShape(temp);
            }
            else if(shapeType == "Square")
            {
                Square *temp = new Square(points[0].toInt(),
                                         points[1].toInt(),
                                         points[2].toInt());
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->getShapeManager()->addShape(temp);
            }
            else if(shapeType == "Ellipse")
            {
                Ellipse *temp = new Ellipse(points[0].toInt(),
                                           points[1].toInt(),
                                           points[2].toInt(),
                                           points[3].toInt());
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->getShapeManager()->addShape(temp);
            }
            else if(shapeType == "Circle")
            {
                Circle *temp = new Circle(points[0].toInt(),
                                         points[1].toInt(),
                                         points[2].toInt());
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setPen(penColor,
                            penWidth.toInt(),
                            penStyle,
                            penCapStyle,
                            penJoinStyle);
                temp->setBrush(brushColor, brushStyle);
                this->renderArea->getShapeManager()->addShape(temp);
            }
            else if(shapeType == "Text")
            {
                Text *temp = new Text(points[0].toInt(),
                                     points[1].toInt(),
                                     points[2].toInt(),
                                     points[3].toInt());
                temp->setDimensions(points);
                temp->setShape(shapeType);
                temp->setId(tempId);
                temp->setAlignFlag(textAlignment);
                temp->setTextPointSize(textPointSize);
                temp->setText(textString);
                temp->setTextColor(textColor);
                temp->setFontStyle(textFontStyle);
                temp->setFontWeight(textFontWeight);
                temp->setFontFamily(textFontFamily);
                this->renderArea->getShapeManager()->addShape(temp);
            }
        }
        this->renderArea->update();
    }
}

Qt::GlobalColor MainWindow::convertColor(QString penColor)
{
    Qt::GlobalColor color;

    if(penColor == "white"){
        color = Qt::GlobalColor::white;
    }
    else if(penColor == "black")
    {
        color = Qt::GlobalColor::black;
    }
    else if(penColor == "red")
    {
        color = Qt::GlobalColor::red;
    }
    else if(penColor == "green")
    {
        color = Qt::GlobalColor::green;
    }
    else if(penColor == "blue")
    {
        color = Qt::GlobalColor::blue;
    }
    else if(penColor == "cyan")
    {
        color = Qt::GlobalColor::cyan;
    }
    else if(penColor == "magenta")
    {
        color = Qt::GlobalColor::magenta;
    }
    else if(penColor == "yellow")
    {
        color = Qt::GlobalColor::yellow;
    }
    else
    {
        color = Qt::GlobalColor::gray;
    }
    return color;
}

Qt::PenStyle MainWindow::convertPenStyle(QString penStyle)
{
    Qt::PenStyle style;

    if(penStyle == "NoPen")
    {
        style = Qt::PenStyle::NoPen;
    }
    else if(penStyle == "SolidLine")
    {
        style = Qt::PenStyle::SolidLine;
    }
    else if(penStyle == "DashLine")
    {
        style = Qt::PenStyle::DashLine;
    }
    else if(penStyle == "DotLine")
    {
        style = Qt::PenStyle::DotLine;
    }
    else if(penStyle == "DashDotLine")
    {
        style = Qt::PenStyle::DashDotLine;
    }
    else
    {
        style = Qt::PenStyle::DashDotDotLine;
    }
    return style;
}

Qt::PenCapStyle MainWindow::convertPenCapStyle(QString penCapStyle)
{
    Qt::PenCapStyle style;

    if(penCapStyle == "FlatCap")
    {
        style = Qt::PenCapStyle::FlatCap;
    }
    else if(penCapStyle == "SquareCap")
    {
        style = Qt::PenCapStyle::SquareCap;
    }
    else
    {
        style = Qt::PenCapStyle::RoundCap;
    }

    return style;
}
//-------------------------------------------------------
//HELP PAGES
//-------------------------------------------------------

//BUTTON TO GO TO THE HELP ADD PAGE FROM MAIN HELP PAGE
void MainWindow::on_pushButton_4_clicked()
{
    ui->help_pages->setCurrentIndex(HELP_ADD);
}

//BUTTON TO GO TO HELP REM PAGE FROM MAIN HELP PAGE
void MainWindow::on_pushButton_3_clicked()
{
    ui->help_pages->setCurrentIndex(HELP_REM);
}

//BUTTON TO GO TO THE HELP EDIT MAIN HELP PAGE
void MainWindow::on_pushButton_2_clicked()
{
    ui->help_pages->setCurrentIndex(HELP_EDIT);
}

//BUTTON TO GO TO THE HELP VIEW PAGE FROM THE MAIN HELP PAGE
void MainWindow::on_pushButton_clicked()
{
    ui->help_pages->setCurrentIndex(HELP_VIEW);
}

//BACK BUTTONS FROM THE HELP PAGES BACK TO MAIN HELP PAGE
//-----------------------------------------------------------
//------------------------------------------------------------


//erics sttuff added to input file
//---------------------------------------------------------------
Qt::PenJoinStyle MainWindow::convertPenJoinStyle(QString penJoinStyle)
{
    Qt::PenJoinStyle style;

    if(penJoinStyle == "MiterJoin")
    {
        style = Qt::PenJoinStyle::MiterJoin;
    }
    else if(penJoinStyle == "BevelJoin")
    {
        style = Qt::PenJoinStyle::BevelJoin;
    }
    else
    {
        style = Qt::PenJoinStyle::RoundJoin;
    }

    return style;
}

Qt::BrushStyle MainWindow::convertBrushStyle(QString brushStyle)
{
    Qt::BrushStyle style;

    if(brushStyle == "SolidPattern")
    {
        style = Qt::BrushStyle::SolidPattern;
    }
    else if(brushStyle == "HorPattern")
    {
        style = Qt::BrushStyle::HorPattern;
    }
    else if(brushStyle == "VerBattern")
    {
        style = Qt::BrushStyle::VerPattern;
    }
    else
    {
        style = Qt::BrushStyle::NoBrush;
    }

    return style;
}

Qt::AlignmentFlag MainWindow::convertAlignmentFlag(QString alignmentFlag)
{
    Qt::AlignmentFlag flag;

    if(alignmentFlag == "AlignLeft")
    {
        flag = Qt::AlignmentFlag::AlignLeft;
    }
    else if(alignmentFlag == "AlignRight")
    {
        flag = Qt::AlignmentFlag::AlignRight;
    }
    else if(alignmentFlag == "AlignTop")
    {
        flag = Qt::AlignmentFlag::AlignTop;
    }
    else if(alignmentFlag == "AlignBottom")
    {
        flag = Qt::AlignmentFlag::AlignBottom;
    }
    else
    {
        flag = Qt::AlignmentFlag::AlignCenter;
    }
    return flag;
}

QFont::Style MainWindow::convertTextFontStyle(QString textFontStyle)
{
    QFont::Style style;

    if(textFontStyle == "StyleNormal")
    {
        style = QFont::Style::StyleNormal;
    }
    else if(textFontStyle == "StyleItalic")
    {
        style = QFont::Style::StyleItalic;
    }
    else
    {
        style = QFont::Style::StyleOblique;
    }
    return style;
}

QFont::Weight MainWindow::convertTextFontWeight(QString textFontWeight)
{
    QFont::Weight weight;

    if(textFontWeight == "Thin")
    {
        weight = QFont::Weight::Thin;
    }
    else if(textFontWeight == "Light")
    {
        weight = QFont::Weight::Light;
    }
    else if(textFontWeight == "Bold")
    {
        weight =  QFont::Weight::Bold;
    }
    else
    {
        weight = QFont::Weight::Normal;
    }
    return weight;
}

void MainWindow::OutputToFile()
{
    QString filename = "Save.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream output( &file );

        for(int i = 0; i < this->renderArea->getShapeManager()->size(); ++i)
        {
            if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Line")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Line";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Polyline")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Polyline";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Polygon")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Polygon";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
                this->renderArea->getShapeManager()->getVector()[i]->printBrush(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Rectangle")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Rectangle";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
                this->renderArea->getShapeManager()->getVector()[i]->printBrush(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Square")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Square";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
                this->renderArea->getShapeManager()->getVector()[i]->printBrush(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Ellipse")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Ellipse";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
                this->renderArea->getShapeManager()->getVector()[i]->printBrush(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Circle")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Circle";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                this->renderArea->getShapeManager()->getVector()[i]->printPen(output);
                this->renderArea->getShapeManager()->getVector()[i]->printBrush(output);
            }
            else if(this->renderArea->getShapeManager()->getVector()[i]->getShape() == "Text")
            {
                output << endl;
                output << "ShapeId: ";
                output << this->renderArea->getShapeManager()->getVector()[i]->getId();
                output << endl;
                output << "ShapeType: ";
                output << "Text";
                output << endl;
                output << "ShapeDimensions: ";
                this->renderArea->getShapeManager()->getVector()[i]->printDimensions(output);
                output << endl;
                Text::printTextStuff(output, (static_cast<Text*>(this->renderArea->getShapeManager()->getVector()[i])));
            }
        }
        output << endl;
    }
}


void MainWindow::on_delIndexLineEdit_returnPressed()
{
    int indexToDel = ui->delIndexLineEdit->text().toInt();

    if(!this->renderArea->getShapeManager()->isEmpty())
    {
        vector<Shape*>::iterator it = this->renderArea->getShapeManager()->getVector().begin() + indexToDel;
        qDebug() << "before deletion";
        this->renderArea->getShapeManager()->getVector().erase(it);
        qDebug() << "removed shape";
        update();
    }
    else
    {

        QMessageBox::critical(this, "Error", "No objects to draw.");
    }
}


void MainWindow::on_maintenanceBackButt_clicked()
{
        ui->Main_Menu->setCurrentIndex(HELP);
}


void MainWindow::on_maintenanceButt_clicked()
{
        ui->Main_Menu->setCurrentIndex(MAINTENANCE);
}
