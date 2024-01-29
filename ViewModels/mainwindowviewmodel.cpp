#include "mainwindowviewmodel.h"

MainWindowViewModel::MainWindowViewModel(Model* model, QObject *parent)
    : QObject{parent}
    , model_(model)
{
    connect(model_, SIGNAL(valueChangedSignal(int)),
            this, SLOT(onValueChangedFromModelSlot(int)));
}

void MainWindowViewModel::init()
{
    int value = model_->getValue();
    setValue(value);
    setText(value);
}

void MainWindowViewModel::onClickSlot()
{
    model_->incrementValue();
}

void MainWindowViewModel::onClearSlot()
{
    model_->setValue(0);
}

void MainWindowViewModel::onValueChangedFromModelSlot(int value)
{
    setValue(value);
    setText(value);
}

void MainWindowViewModel::setValue(int value)
{
    value_ = value;
    emit valueChangedSignal(value_);
}

void MainWindowViewModel::setText(int value)
{
    setText(QString("Текущее значение %1 величин").arg(value));
}

void MainWindowViewModel::setText(QString text)
{
    text_ = std::move(text);
    emit textChangedSignal(text_);
}
