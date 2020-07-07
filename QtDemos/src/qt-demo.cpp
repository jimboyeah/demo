#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QBoxLayout>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QFrame>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Quit");

    quit.resize(275, 230);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    QTextEdit editor;

    QFrame* f = new QFrame(&editor);
    f->setFrameStyle( QFrame::Sunken | QFrame::Panel );
    f->setLineWidth( 2 );

    QMenu *file = new QMenu();
    file->addAction("Exit", qApp, SLOT(quit())/*, CTRL+Key_Q*/);
    QMenuBar *m = new QMenuBar();
    m->addMenu(file)->setText("&File");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(5);
    // layout->addWidget(f,1);
    layout->addWidget(&quit);
    layout->addWidget(&editor);
    layout->setMenuBar(m);

    quit.show();
    editor.show();

    return app.exec();
}
