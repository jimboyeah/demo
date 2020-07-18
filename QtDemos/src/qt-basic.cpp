#include <QApplication>
#include <QFont>
#include <QPushButton>
// https://doc-snapshots.qt.io/qt5-5.9/all-examples.html
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Quit");

    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    quit.show();

    return app.exec();
}
