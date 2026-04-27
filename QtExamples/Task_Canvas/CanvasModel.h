#ifndef CANVASMODEL_H
#define CANVASMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "CanvasData.h"

class CanvasModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CanvasModel(QObject *parent = nullptr);

    enum DataRoles
    {
        IdRole = Qt::UserRole + 1,
        ImageRole,
        FreeDrawRole,
        DotRole,
        UploadRole,
        ButtonRole
    };


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    void insertData(const CanvasData &data);

private:
    QList<CanvasData> m_data;
};

#endif // CANVASMODEL_H