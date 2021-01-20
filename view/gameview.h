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
    Q_OBJECT

   private:
    SP<model::GameModel> _model;
    GameScene* scene;

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    GameView(const SP<model::GameModel>& model);

   signals:
    void playPauseButtonPressed();
    void fastForwardButtonPressed();
    void addTurretSignal(model::Position position, model::TurretType turretType);
    void removeTurretSignal(model::Position position);
};

}  // namespace view

#endif