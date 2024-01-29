#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    void incrementValue();
    int getValue() const;
    void setValue(int value);

signals:
    void valueChangedSignal(int);

private:
    int value_;
};

#endif // MODEL_H
