#ifndef VIEW_GAMEVIEW_H_
#define VIEW_GAMEVIEW_H_

#include <QGraphicsView>

#include "view/gamescene.h"

namespace view {

class GameView : public QGraphicsView {
   private:
    GameScene* scene;

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    GameView();
};

}  // namespace view

#endif