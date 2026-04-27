#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QWidget>

static void setupTable(QTableView *table, QStandardItemModel *model)
{
    model->setRowCount(5);
    model->setColumnCount(3);

    for (int r = 0; r < 5; ++r)
        for (int c = 0; c < 3; ++c)
            model->setData(model->index(r, c), QString("R%1 C%2").arg(r).arg(c));

    table->setModel(model);

    // To make selection clear
    table->setSelectionBehavior(QAbstractItemView::SelectColumns);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

    table->horizontalHeader()->setSectionsClickable(true);

    // Select one column so UI clearly shows behavior immediately
    table->selectColumn(1);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("highlightSections Visual Proof");
    window.resize(900, 300);

    auto *layout = new QHBoxLayout(&window);

    // -------- Left table: highlightSections OFF (No header highlight) --------
    auto *tableOff = new QTableView;
    auto *modelOff = new QStandardItemModel;

    setupTable(tableOff, modelOff);
    tableOff->setWindowTitle("highlightSections = false (UI)");
    tableOff->horizontalHeader()->setHighlightSections(false);

    // -------- Right table: highlightSections ON (Header highlight visible) --------
    auto *tableOn = new QTableView;
    auto *modelOn = new QStandardItemModel;

    setupTable(tableOn, modelOn);
    tableOn->setWindowTitle("highlightSections = true (UI)");
    tableOn->horizontalHeader()->setHighlightSections(true);

    layout->addWidget(tableOff);
    layout->addWidget(tableOn);

    window.show();
    return app.exec();
}
