#ifndef VIEW_GAMESCENE_H_
#define VIEW_GAMESCENE_H_

#include <QGraphicsScene>
#include <vector>

#include "model/gamemodel.h"
#include "view/hud/infobox.h"
#include "view/screens/gameScreen/enemyitem.h"
#include "view/screens/gameScreen/gridfield.h"

using std::shared_ptr;
using std::vector;

#define SP shared_ptr

namespace view {

class GameScene : public QGraphicsScene {
    Q_OBJECT

   private:
    SP<const model::GameModel> _model;

    GridField* gridField;
    InfoBox* creditsInfo;
    InfoBox* lifeInfo;

    vector<EnemyItem*> enemies;

    void drawBackground();
    void createHUD();

   public:
    GameScene(const SP<const model::GameModel>& model);

    void tick();
    void spawnEnemy(const SP<model::Enemy>& enemy);

   signals:
    void playPauseButtonPressed();
    void fastForwardButtonPressed();
    void addTurretSignal(model::Position position, model::TurretType turretType);
    void removeTurretSignal(model::Position position);
};

}  // namespace view

#endif