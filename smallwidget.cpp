#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

smallwidget::smallwidget(QWidget *parent)
    : QWidget{parent}
{
    QSpinBox *spin = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(spin);
    hlayout->addWidget(slider);

    setLayout(hlayout);


    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), slider, &QSlider::setValue);

    connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);
}
