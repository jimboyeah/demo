#include <QApplication>
#include <QProcess>
#include <QPushButton>
#include <QMessageBox>
#include <QTextCodec>

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{  
    p = new QProcess(this);  
    QPushButton *bt = new QPushButton("display", this);  
    connect(bt, SIGNAL(clicked()), this, SLOT(openProcess()));  
}  

MainWindow::~MainWindow()  
{  
    // ...
}  


void MainWindow::openProcess()  
{  
#if defined(Q_OS_WIN32)  
    p->start("cmd.exe", QStringList() << "/c" << "dir");  
#elif defined(Q_OS_LINUX)  
    p->start("ls", QStringList() << "/home/usr_name");  
#endif  
    connect(p, SIGNAL(finished(int)), this, SLOT(readResult(int)));  
}  


void MainWindow::readResult(int exitCode)  
{  
    if(exitCode == 0) {  
#if defined(Q_OS_WIN32)  
        QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");  
        QString result = gbkCodec->toUnicode(p->readAll());  
#elif defined(Q_OS_LINUX)  
        QTextCodec* utfCodec = QTextCodec::codecForName("UTF-8");  
        QString result = utfCodec->toUnicode(p->readAll());  
#endif  
        QMessageBox::information(this, "dir", result);  
    }  
} 
