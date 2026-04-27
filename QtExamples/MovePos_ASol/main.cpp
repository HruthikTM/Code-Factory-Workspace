#include <QApplication>
#include <QDebug>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit w;
    w.setPlainText("abcdef");

    QTextCursor tc = w.textCursor();

    // ===== SCENARIO 1: FORWARD SELECTION =====
    qInfo() << "===== FORWARD SELECTION =====";
    qInfo() << "Text: 'abcdef'";
    qInfo() << "       012345";

    tc.setPosition(0);  // Start at position 0
    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, 3);  // Select "abc"

    qInfo() << "\nBefore movePosition:";
    qInfo() << "  anchor=" << tc.anchor() << ", position=" << tc.position();
    qInfo() << "  selected text='" << tc.selectedText() << "'";
    qInfo() << "  selection range: [" << tc.anchor() << "-" << tc.position() << "]";

    // // ===== WITH PROPER FIX =====
    // qInfo() << "\nWith PROPER FIX:";
    // qInfo() << "  Step 1: Check condition (MoveAnchor && 0 != 3) = TRUE";
    // qInfo() << "  Step 2: newPosition = qMax(3, 0) = 3";
    // qInfo() << "  Step 3: newPosition = nextCursorPosition(3) = 4";

    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qInfo() << "  After movePosition:";
    qInfo() << "    position=" << tc.position() ;
    qInfo() << "    selected text='" << tc.selectedText() << "' (cleared)";

    // ===== SCENARIO 2: BACKWARD SELECTION =====
    qInfo() << "\n\n===== BACKWARD SELECTION =====";
    qInfo() << "Text: 'abcdef'";
    qInfo() << "       012345";

    tc.setPosition(3);  // Start at position 3
    tc.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor, 3);  // Select "abc" backward

    qInfo() << "\nBefore movePosition:";
    qInfo() << "  anchor=" << tc.anchor() << ", position=" << tc.position();
    qInfo() << "  selected text='" << tc.selectedText() << "'";
    qInfo() << "  selection range: [" << tc.position() << "-" << tc.anchor() << "]";

    // // ===== WITH PROPER FIX =====
    // qInfo() << "\nWith PROPER FIX:";
    // qInfo() << "  Step 1: Check condition (MoveAnchor && 0 != 3) = TRUE";
    // qInfo() << "  Step 2: newPosition = qMax(0, 3) = 3";
    // qInfo() << "  Step 3: newPosition = nextCursorPosition(3) = 4";

    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qInfo() << "  After movePosition:";
    qInfo() << "    position=" << tc.position() ;
    qInfo() << "    selected text='" << tc.selectedText() << "' (cleared)";

    // ===== SCENARIO 3: NO SELECTION =====
    qInfo() << "\n\n===== NO SELECTION =====";
    qInfo() << "Text: 'abcdef'";
    qInfo() << "       012345";

    tc.setPosition(2);  // Place cursor at position 2 (no selection)

    qInfo() << "\nBefore movePosition:";
    qInfo() << "  anchor=" << tc.anchor() << ", position=" << tc.position();
    qInfo() << "  selected text='" << tc.selectedText() << "'";

    // qInfo() << "\nWith PROPER FIX:";
    // qInfo() << "  Step 1: Check condition (MoveAnchor && 2 != 2) = FALSE";
    // qInfo() << "  Step 2: newPosition = position = 2";
    // qInfo() << "  Step 3: newPosition = nextCursorPosition(2) = 3";

    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qInfo() << "  After movePosition:";
    qInfo() << "    position=" << tc.position();

    w.show();
    return a.exec();
}
