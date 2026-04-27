#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QHeaderView standalone(Qt::Horizontal);
    qDebug() << "[Standalone QHeaderView] highlightSections ="
             << standalone.highlightSections();

    QTableView table;

    qDebug() << "[QTableView horizontalHeader] highlightSections ="
             << table.horizontalHeader()->highlightSections();
    qDebug() << "[QTableView verticalHeader] highlightSections ="
             << table.verticalHeader()->highlightSections();

    //table.horizontalHeader()->setHighlightSections(false);
    table.horizontalHeader()->setSectionsClickable(false);

    //table.verticalHeader()->setHighlightSections(false);
    table.verticalHeader()->setSectionsClickable(false);

    qDebug() << "[After manual override] horizontalHeader highlightSections ="
             << table.horizontalHeader()->highlightSections()
             << table.horizontalHeader()->sectionsClickable();
    qDebug() << "[After manual override] verticalHeader highlightSections ="
             << table.verticalHeader()->highlightSections()
             << table.verticalHeader()->sectionsClickable();

    QStandardItemModel model(3, 3);
    table.setModel(&model);
    table.show();

    return app.exec();
}
