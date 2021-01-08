#ifndef VIEW_GAMESCENE_H_
#define VIEW_GAMESCENE_H_

#include <QGraphicsScene>

namespace view {

class GameScene : public QGraphicsScene {
   private:
    void drawBackground();
    void createGameGrid();

   public:
    GameScene(qreal width, qreal height);
};

}  // namespace view

#endif