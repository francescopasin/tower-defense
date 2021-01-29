#include "view/screens/setMapScreen/setmapcell.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

SetMapCell::SetMapCell(
    QGraphicsItem *parent,
    qreal size,
    model::Position pos,
    Type type)
    : QGraphicsItem(parent),
      _size(size),
      _gridPos(pos),
      _type(type),
      _selected(false) {
    if (type == Type::Free) {
        setAcceptHoverEvents(true);

        QPixmap pixmap;
        if (type == Type::Free) {
            pixmap = QPixmap(":/assets/images/pointer-turret-place.png");
        } else {
            pixmap = QPixmap(":/assets/images/pointer-turret-remove.png");
        }
        setCursor(QCursor(pixmap.scaled(32, 32)));
    }
}

QRectF SetMapCell::boundingRect() const {
    return QRectF(0, 0, _size, _size);
}

SetMapCell::Type SetMapCell::getType() const {
    return _type;
}

model::Position SetMapCell::getPos() const {
    return _gridPos;
}

void SetMapCell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    emit pressed(this);
}

void SetMapCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QString imagePath;

    switch (_type) {
        case Type::Free:
            imagePath = ":/assets/images/free-tile.png";

            if (option->state & QStyle::State_MouseOver || _selected) {
                imagePath = ":/assets/images/free-tile-pressed.png";
            }
            break;
        case Type::Start:
            imagePath = ":/assets/images/left-start-tile.png";
            break;
        case Type::Finish:
            imagePath = ":/assets/images/right-end-tile.png";
            break;
        case Type::Vert:
            imagePath = ":/assets/images/vertical-tile.png";
            break;
        case Type::Orizz:
            imagePath = ":/assets/images/horizontal-tile.png";
            break;
        case Type::SxUp:
            imagePath = ":/assets/images/top-left-tile.png";
            break;
        case Type::DxUp:
            imagePath = ":/assets/images/top-right-tile.png";
            break;
        case Type::SxDw:
            imagePath = ":/assets/images/bottom-left-tile.png";
            break;
        case Type::DxDw:
            imagePath = ":/assets/images/bottom-right-tile.png";
            break;
        case Type::Blocked:
            imagePath = ":/assets/images/blocked-tile.png";
            break;
    }
    QPixmap pixmap = QPixmap(imagePath);
    painter->drawPixmap(QRect(0, 0, _size, _size), pixmap);

}  // namespace view

void SetMapCell::setType(Type type) {
    _type = type;
    update();
}

void SetMapCell::setTile(const QString &path) {
    _imagePath = path;
}

bool SetMapCell::isSelected() const {
    return _selected;
}

void SetMapCell::setSelected(bool selected) {
    _selected = selected;
    update();
}

}  // namespace view
