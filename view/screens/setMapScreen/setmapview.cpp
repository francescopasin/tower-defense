#include "view/screens/setMapScreen/setmapview.h"

#include <QResizeEvent>

namespace view {

SetMapView::SetMapView(const SP<SetMapScene>& scene) : _scene(scene) {
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(_scene.get());

    QPixmap pixmap = QPixmap(":/assets/images/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

void SetMapView::resizeEvent(QResizeEvent* event) {
    fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}

}  // namespace view
