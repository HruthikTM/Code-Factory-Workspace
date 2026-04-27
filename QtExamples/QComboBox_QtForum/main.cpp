#include <QApplication>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QStringList wordList;
    wordList << "a1" << "a2" << "a3" << "a4";

    QComboBox *combobox = new QComboBox();
    combobox->setEditable(true);
    combobox->addItems(wordList);

    // Completer using a separate model
    QCompleter *completer = new QCompleter(wordList);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    combobox->setCompleter(completer);

    layout->addWidget(combobox);

    window.resize(300,100);
    window.show();

    return app.exec();
}
