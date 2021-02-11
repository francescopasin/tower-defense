#ifndef VIEW_GAMESCENE_H_
#define VIEW_GAMESCENE_H_

#include <QGraphicsScene>
#include <vector>

#include "app/shortcuts.h"
#include "model/gamemodel.h"
#include "model/position.h"
#include "model/sharedptr.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"
#include "view/hud/infobox.h"
#include "view/screens/gameScreen/enemyitem.h"
#include "view/screens/gameScreen/gridcelltype.h"
#include "view/screens/gameScreen/gridfield.h"
#include "view/screens/gameScreen/turretselector.h"

using std::vector;

namespace view {

class GameScene : public QGraphicsScene {
    Q_OBJECT

   private:
    const SP<model::GameModel> _model;

    GridField* gridField;
    InfoBox* creditsInfo;
    InfoBox* lifeInfo;
    TurretSelector* turretSelector;

    vector<EnemyItem*> enemies;

    void drawBackground();
    void createHUD();

   public:
    GameScene(const SP<model::GameModel>& model);

    void tick();
    void spawnEnemy(const SP<model::Enemy>& enemy);
    void turretsAttack(const vector<SP<model::Turret>>& attackingTurrets);
    void addTurretItem(const SP<model::Turret>& turret, model::TurretType turretType);

   public slots:
    void gridCellPressed(GridCellType cellType, model::Position cellPosition);
    void closeTurretSelector();
    void showTurretInfos(model::TurretType turretType);
    void addTurret(model::TurretType turretType);
    void pauseButtonPressed();
    void showModal(model::Game::State stato);

   signals:
    void playPauseGame();
    void restart();
    void fastForwardGame();
    void addTurretSignal(model::Position position, model::TurretType turretType);
    void removeTurretSignal(model::Position position);
    void returnToMenu();
};

}  // namespace view

#endif
