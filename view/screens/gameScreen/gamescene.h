#ifndef VIEW_GAMESCENE_H_
#define VIEW_GAMESCENE_H_

#include <QGraphicsScene>
#include <vector>

#include "model/gamemodel.h"
#include "model/sharedptr.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"
#include "view/hud/infobox.h"
#include "view/screens/gameScreen/enemyitem.h"
#include "view/screens/gameScreen/gridcelltype.h"
#include "view/screens/gameScreen/gridfield.h"
#include "view/screens/gameScreen/turretselector.h"

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
    TurretSelector* turretSelector;

    vector<EnemyItem*> enemies;

    void drawBackground();
    void createHUD();

   public:
    GameScene(const SP<const model::GameModel>& model);

    void tick();
    void spawnEnemy(const SP<model::Enemy>& enemy);
    void addTurretItem(const model::SharedPtr<model::Turret>& turret, model::TurretType turretType);

   public slots:
    void gridCellPressed(GridCellType cellType, const QPointF& coordinates);
    void closeTurretSelector();
    void addTurret(model::TurretType turretType);

   signals:
    void playPauseButtonPressed();
    void fastForwardButtonPressed();
    void addTurretSignal(model::Position position, model::TurretType turretType);
    void removeTurretSignal(model::Position position);
};

}  // namespace view

#endif