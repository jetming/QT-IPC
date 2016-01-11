#include "signalforward.h"

SignalForward::SignalForward(QObject *parent) : QObject(parent)
{

}

void SignalForward::emitsignal()
{
    emit open();
}
