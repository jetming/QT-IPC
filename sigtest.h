/*
 * 接收信号类，汇集统一处理所有的信号的槽函数
 */

#ifndef SIGTEST_H
#define SIGTEST_H

#include <QObject>

class SigTest : public QObject
{
    Q_OBJECT
public:
    explicit SigTest(QObject *parent = 0);

signals:

public slots:
    void test();
};

#endif // SIGTEST_H
