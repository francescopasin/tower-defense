#ifndef VIEW_SETMAPCELL_H_
#define VIEW_SETMAPCELL_H_

#include <QGraphicsItem>

#include "model/position.h"
#include "view/screens/gameScreen/map/gridcelltype.h"

namespace view {

class SetMapCell : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   public:
    enum class Type {
        Start,
        Finish,
        Orizz,
        Vert,
        SxUp,
        DxUp,
        SxDw,
        DxDw,
        Blocked,
        Free
    };

   private:
    qreal _size;
    Type _type;
    model::Position _gridPos;
    bool _selected;
    QString _imagePath;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    SetMapCell(QGraphicsItem *parent, qreal size, model::Position pos, Type type = Type::Free);
    void setType(Type type);
    QRectF boundingRect() const override;
    model::Position getPos() const;

    bool isSelected() const;
    void setSelected(bool selected);
    void setTile(const QString &path);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Type getType() const;

   signals:
    void pressed(SetMapCell *cell);
};

}  // namespace view

#endif
