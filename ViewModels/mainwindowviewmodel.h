#ifndef MAINWINDOWVIEWMODEL_H
#define MAINWINDOWVIEWMODEL_H

#include "Models/model.h"
#include <QObject>

class MainWindowViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowViewModel(Model* model, QObject *parent = nullptr);
    void init();

signals:
    void valueChangedSignal(int);
    void textChangedSignal(QString);

public slots:
    void onClickSlot();
    void onClearSlot();
    void onValueChangedFromModelSlot(int value);

private:
    Model* model_;
    int value_;
    QString text_;

private:
    void setValue(int value);
    void setText(int value);
    void setText(QString text);
};

#endif // MAINWINDOWVIEWMODEL_H
