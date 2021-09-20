#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QRunnable>
#include <QProgressBar>
//#include <QObject>

class runnable : public QRunnable
{
//    Q_OBJECT
public:
    runnable(QProgressBar *progressBar);
    virtual ~runnable();
    void run();

private:
    QProgressBar *m_ProgressBar;
};

#endif // RUNNABLE_H
