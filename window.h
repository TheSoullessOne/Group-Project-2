#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE
class RenderArea;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();


private:
    RenderArea *renderArea;
<<<<<<< HEAD
    QLabel     *shapeLabel;
    QLabel     *penWidthLabel;
    QLabel     *penStyleLabel;
    QLabel     *penCapLabel;
    QLabel     *penJoinLabel;
    QLabel     *brushStyleLabel;
    QLabel     *otherOptionsLabel;
    QComboBox  *shapeComboBox;
    QSpinBox   *penWidthSpinBox;
    QComboBox  *penStyleComboBox;
    QComboBox  *penCapComboBox;
    QComboBox  *penJoinComboBox;
    QComboBox  *brushStyleComboBox;
    QCheckBox  *antialiasingCheckBox;
    QCheckBox  *transformationCheckBox;
=======
>>>>>>> 4cc6752cbd00fe11930da0c8bb4a521dfadcb5f9
};

#endif // WINDOW_H
