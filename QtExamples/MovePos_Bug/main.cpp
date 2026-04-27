#include <QApplication>
#include <QTextEdit>
#include <QTextCursor>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextEdit editor;
    editor.setPlainText("abcdef");
    editor.resize(400,200);

    QTextCursor cursor = editor.textCursor();

    // Select first 3 characters
    cursor.movePosition(QTextCursor::NextCharacter,
                        QTextCursor::KeepAnchor,
                        3);

    editor.setTextCursor(cursor);

    qDebug() << "Before move:";
    qDebug() << "Position:" << cursor.position();
    qDebug() << "Selected:" << cursor.selectedText();

    //Move cursor forward
    cursor.movePosition(QTextCursor::NextCharacter,
                        QTextCursor::MoveAnchor);

    editor.setTextCursor(cursor);

    qDebug() << "After move:";
    qDebug() << "Position:" << cursor.position();
    qDebug() << "Selected:" << cursor.selectedText();

    editor.show();

    return app.exec();
}
