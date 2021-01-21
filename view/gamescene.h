#ifndef VIEW_GAMESCENE_H_
#define VIEW_GAMESCENE_H_

#include <QGraphicsScene>

#include "model/gamemodel.h"
#include "view/hud/infobox.h"

using std::shared_ptr;

#define SP shared_ptr

namespace view {

class GameScene : public QGraphicsScene {
    Q_OBJECT

   private:
    SP<const model::GameModel> _model;

    InfoBox* creditsInfo;
    InfoBox* lifeInfo;

    void drawBackground();
    void createGameGrid();
    void createHUD();

   public:
    GameScene(const SP<const model::GameModel>& model);

    void tick();

   signals:
    void playPauseButtonPressed();
    void fastForwardButtonPressed();
    void addTurretSignal(model::Position position, model::TurretType turretType);
    void removeTurretSignal(model::Position position);
};

}  // namespace view

#endif