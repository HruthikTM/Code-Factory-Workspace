#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QHeaderView plainHeader(Qt::Horizontal);
    qDebug() << "Plain QHeaderView highlightSections =" << plainHeader.highlightSections();


    QTableView table;

    qDebug() << "QTableView horizontalHeader highlightSections & sectionClick ="
             << table.horizontalHeader()->highlightSections() << ","
             << table.horizontalHeader()->sectionsClickable();

    qDebug() << "QTableView verticalHeader highlightSections & sectionClick ="
             << table.verticalHeader()->highlightSections() << ","
             << table.verticalHeader()->sectionsClickable();


    QStandardItemModel model(3, 3);
    table.setModel(&model);
    table.show();

    return app.exec();
}




// #include <QApplication>
// #include <QTableView>
// #include <QHeaderView>
// #include <QStandardItemModel>
// #include <QDebug>
// #include <QItemSelection>

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     QTableView table;


//     qDebug() << "[Before click]"
//              << "horizontal highlightSections ="
//              << table.horizontalHeader()->highlightSections()
//              << ", sectionsClickable ="
//              << table.horizontalHeader()->sectionsClickable();

//     qDebug() << "[Before click]"
//              << "vertical highlightSections ="
//              << table.verticalHeader()->highlightSections()
//              << ", sectionsClickable ="
//              << table.verticalHeader()->sectionsClickable();


//     QStandardItemModel model(5, 3);
//     for (int r = 0; r < 5; ++r) {
//         for (int c = 0; c < 3; ++c) {
//             model.setData(model.index(r, c),
//                           QString("R%1 C%2").arg(r).arg(c));
//         }
//     }

//     table.setModel(&model);

//     table.setSelectionBehavior(QAbstractItemView::SelectColumns);
//     table.setSelectionMode(QAbstractItemView::SingleSelection);

//     QObject::connect(table.horizontalHeader(),
//                      &QHeaderView::sectionClicked,
//                      [&](int logicalIndex) {
//                          qDebug() << "[Header clicked] Column =" << logicalIndex
//                                   << "Header text ="
//                                   << model.headerData(logicalIndex, Qt::Horizontal).toString();
//                      });

//     QObject::connect(table.verticalHeader(),
//                      &QHeaderView::sectionClicked,
//                      [&](int logicalIndex) {
//                          qDebug() << "[Header clicked] Row =" << logicalIndex
//                                   << "Header text ="
//                                   << model.headerData(logicalIndex, Qt::Vertical).toString();
//                      });


//     QObject::connect(table.selectionModel(),
//                      &QItemSelectionModel::selectionChanged,
//                      [&](const QItemSelection &selected,
//                          const QItemSelection &) {

//                          // PROOF: highlightSections does NOT change
//                          qDebug() << "[After click]"
//                                   << "horizontal highlightSections ="
//                                   << table.horizontalHeader()->highlightSections()
//                                   << ", vertical highlightSections ="
//                                   << table.verticalHeader()->highlightSections();

//                          for (const QItemSelectionRange &range : selected) {
//                              qDebug() << "[Selection]"
//                                       << "Rows:" << range.top() << "to" << range.bottom()
//                                       << "Columns:" << range.left() << "to" << range.right();

//                              for (int r = range.top(); r <= range.bottom(); ++r) {
//                                  for (int c = range.left(); c <= range.right(); ++c) {
//                                      QModelIndex idx = model.index(r, c);
//                                      qDebug() << "   Cell[" << r << "," << c << "] ="
//                                               << model.data(idx).toString();
//                                  }
//                              }
//                          }
//                      });

//     table.show();
//     return app.exec();
// }
