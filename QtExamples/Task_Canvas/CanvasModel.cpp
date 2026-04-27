#include "CanvasModel.h"

CanvasModel::CanvasModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int CanvasModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_data.size();
}

QVariant CanvasModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const CanvasData &data = m_data.at(index.row());

    switch(role)
    {
    case IdRole:
        return data.getId();

    case ImageRole:
        return data.getImagePath();

    case FreeDrawRole:
        return QVariant::fromValue(data.getFreeHandPoints());

    case DotRole:
        return QVariant::fromValue(data.getDotPoints());

    case UploadRole:
        return data.getUploadImage();

    case ButtonRole:
        return data.getButtonEnabled();
    }

    return QVariant();
}

QHash<int, QByteArray> CanvasModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[IdRole] = "id";
    roles[ImageRole] = "imagePath";
    roles[FreeDrawRole] = "freeHandPoints";
    roles[DotRole] = "dotPoints";
    roles[UploadRole] = "uploadedImage";
    roles[ButtonRole] = "buttonEnabled";

    return roles;
}

void CanvasModel::insertData(const CanvasData &data)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());

    m_data.append(data);

    endInsertRows();
}