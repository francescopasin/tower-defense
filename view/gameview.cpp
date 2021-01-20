#include "view/gameview.h"

#include <QResizeEvent>

namespace view {

GameView::GameView(const SP<model::GameModel>& model) : _model(model), scene(new GameScene()) {
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);
}

void GameView::resizeEvent(QResizeEvent* event) {
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}

}  // namespace view
