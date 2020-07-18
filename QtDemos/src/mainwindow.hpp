#include <QMainWindow>


class QProcess;  

class MainWindow : public QMainWindow  
{  
    Q_OBJECT  

public:  
    MainWindow(QWidget *parent = 0);  
    ~MainWindow();  

private slots:  
    void openProcess();  
    void readResult(int exitCode);  

private:  
    QProcess *p;  
};  
