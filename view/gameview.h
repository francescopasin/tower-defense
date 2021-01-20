#ifndef VIEW_GAMEVIEW_H_
#define VIEW_GAMEVIEW_H_

#include <QGraphicsView>
#include <memory>

#include "model/gamemodel.h"
#include "view/gamescene.h"

using std::shared_ptr;

#define SP shared_ptr

namespace view {

class GameView : public QGraphicsView {
   private:
    SP<GameScene> _scene;

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    GameView(const SP<GameScene>& scene);
};

}  // namespace view

#endif