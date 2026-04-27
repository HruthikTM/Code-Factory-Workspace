#include <QApplication>
#include <QDebug>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit w;
    w.setPlainText("abcdef");

    QTextCursor tc = w.textCursor();

    // ===== SCENARIO 1: Forward Selection =====
    qInfo() << "===== FORWARD SELECTION =====";
    tc.setPosition(0);                  // Move to start
    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, 3);  // Select "abc" forward

    qInfo() << "Before movePosition:";
    qInfo() << "  anchor=" << tc.anchor() << ", position=" << tc.position();
    qInfo() << "  selected=" << tc.selectedText();

    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qInfo() << "After movePosition:";
    qInfo() << "  position=" << tc.position();

    // ===== SCENARIO 2: Backward Selection =====
    qInfo() << "\n===== BACKWARD SELECTION =====";
    tc.setPosition(3);                  // Move to position 3
    tc.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor, 3);  // Select "abc" backward

    qInfo() << "Before movePosition:";
    qInfo() << "  anchor=" << tc.anchor() << ", position=" << tc.position();
    qInfo() << "  selected=" << tc.selectedText();

    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qInfo() << "After movePosition:";
    qInfo() << "  position=" << tc.position();

    w.show();
    return a.exec();
}
