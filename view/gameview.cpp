#include "view/gameview.h"

#include <QResizeEvent>

namespace view {

GameView::GameView(qreal width, qreal height) : scene(new GameScene(width, height)) {
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setBaseSize(width, height);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);
}
/*
void GameView::resizeEvent(QResizeEvent *event) {
    GameView::resizeEvent(event);

    // Resize the game view
    scene->setSceneRect(0, 0, event->size().width(), event->size().height());
}*/

}  // namespace view
