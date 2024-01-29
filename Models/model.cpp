#include "model.h"

Model::Model(QObject *parent)
    : QObject{parent}
    , value_ (50)
{

}

void Model::incrementValue()
{
    setValue(value_ + 1);
}

int Model::getValue() const
{
    return value_;
}

void Model::setValue(int value)
{
    value_ = value;
    emit valueChangedSignal(value_);
}
