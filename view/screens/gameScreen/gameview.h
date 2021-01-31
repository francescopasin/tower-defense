#ifndef VIEW_GAMEVIEW_H_
#define VIEW_GAMEVIEW_H_

#include <QGraphicsView>

#include "view/screens/gameScreen/gamescene.h"

namespace view {

class GameView : public QGraphicsView {
   private:
    GameScene* _scene;

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    GameView(GameScene* scene);
};

}  // namespace view

#endif