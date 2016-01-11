/*
 * 信号转发类，负责统一转发所有的信号
 */

#ifndef SIGNALFORWARD_H
#define SIGNALFORWARD_H

#include <QObject>

class SignalForward : public QObject
{
    Q_OBJECT
public:
    explicit SignalForward(QObject *parent = 0);
    void emitsignal();
signals:
    void open();
public slots:
};

#endif // SIGNALFORWARD_H
