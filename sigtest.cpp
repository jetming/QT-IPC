#include "sigtest.h"

SigTest::SigTest(QObject *parent) : QObject(parent)
{

}

void SigTest::test()
{
    printf("recieve signal.\n\n");
}
