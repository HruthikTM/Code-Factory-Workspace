#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QTabBar>
#include <QLabel>

// Subclass QTabWidget
class MyTabWidget : public QTabWidget
{
public:
    explicit MyTabWidget(QWidget *parent = nullptr)
        : QTabWidget(parent)
    {
        QTabBar *customTabBar = new QTabBar(this);
        customTabBar->setExpanding(false);

        // LEGAL: protected member accessed from subclass
        setTabBar(customTabBar);
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;

    MyTabWidget *tabs = new MyTabWidget(&mainWindow);

    tabs->addTab(new QLabel("Tab 1"), "One");
    tabs->addTab(new QLabel("Tab 2"), "Two");

    mainWindow.setCentralWidget(tabs);
    mainWindow.resize(400, 200);
    mainWindow.show();

    return app.exec();
}
