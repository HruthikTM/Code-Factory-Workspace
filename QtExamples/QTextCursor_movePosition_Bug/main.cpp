#include <QApplication>
#include <QDebug>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit w;
    w.setPlainText("abcdef");
    QTextCursor tc = w.textCursor();

    // Setup: Create selection at positions 0-3
    tc.setPosition(0);
    tc.setPosition(3, QTextCursor::KeepAnchor);
    qDebug() << "Setup: position=3, selected=" << tc.selectedText();

    // Test: MoveAnchor only
    qDebug() << "\n--- Testing MoveAnchor ---";
    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qDebug() << "MoveAnchor:" << tc.position();

    w.setTextCursor(tc);
    w.show();
    return a.exec();
}
