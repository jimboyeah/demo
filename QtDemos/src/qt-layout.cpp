#include <QtWidgets/QApplication> 
#include <QtWidgets>
#include <QtWidgets/QWidget> 
#include <QtWidgets/QSpinBox> 
#include <QtWidgets/QSlider> 
#include <QtWidgets/QHBoxLayout> 
#include <QtWidgets/QVBoxLayout> 
#include <QtWidgets/QGridLayout> 
// https://doc.qt.io/qt-5/layout.html

int main(int argc, char *argv[]) 
{ 
        QApplication app(argc, argv); 
        QWidget *window = new QWidget; 
        window->setWindowTitle("Enter your age"); 

        QSpinBox *spinBox = new QSpinBox; 
        QSlider *slider = new QSlider(Qt::Horizontal); 
        spinBox->setRange(0, 130); 
        slider->setRange(0, 130); 

        QPushButton *button1 = new QPushButton("One");
        QPushButton *button2 = new QPushButton("Two");
        QPushButton *button3 = new QPushButton("Three");
        QPushButton *button4 = new QPushButton("Four");
        QPushButton *button5 = new QPushButton("Five");

        QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int))); 
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int))); 
        spinBox->setValue(35); 

        // QHBoxLayout *layout = new QHBoxLayout; 
        // QVBoxLayout *layout = new QVBoxLayout; 
        QGridLayout *layout = new QGridLayout; 

        layout->addWidget(spinBox); 
        layout->addWidget(slider); 

        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->addWidget(button4, 0, 1);
        layout->addWidget(button5, 1, 0, 1, 2);

        window->setLayout(layout); 

        window->show(); 

        return app.exec(); 
}