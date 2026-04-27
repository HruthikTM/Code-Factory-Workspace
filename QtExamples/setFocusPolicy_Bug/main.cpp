#include <QApplication>
#include <QToolBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QPushButton *beforeBtn = new QPushButton("Before ToolBox");
    layout->addWidget(beforeBtn);

    QToolBox *toolBox = new QToolBox;

    toolBox->addItem(new QLabel("Page 1 content"), "Page One");
    toolBox->addItem(new QLabel("Page 2 content"), "Page Two");
    toolBox->addItem(new QLabel("Page 3 content"), "Page Three");

    layout->addWidget(toolBox);

    QPushButton *afterBtn = new QPushButton("After ToolBox");
    layout->addWidget(afterBtn);

    window.resize(400, 300);
    window.show();

    return app.exec();
}



