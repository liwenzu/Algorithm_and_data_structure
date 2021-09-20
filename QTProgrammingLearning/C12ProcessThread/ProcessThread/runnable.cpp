#include "runnable.h"

runnable::runnable(QProgressBar *progressBar):
    QRunnable(), m_ProgressBar(progressBar)
{
    for(int i=0;i<100000;i++)
    {
        m_ProgressBar->setValue(i);
    }
}

runnable::~runnable() {}
void runnable::run() {}
