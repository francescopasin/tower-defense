#ifndef CONTROLLER_GAMECONTROLLER_H_
#define CONTROLLER_GAMECONTROLLER_H_

#include <QGraphicsScene>
#include <QTimer>
#include <memory>

#include "controller/controller.h"
#include "model/position.h"
#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/gamescene.h"

using std::shared_ptr;
#define SP shared_ptr

namespace controller {

class GameScreenController : public Controller {
    Q_OBJECT

   private:
    view::GameScene* _scene;

    QTimer* gameTimer;
    QTimer* renderTimer;
    bool isRunning;
    bool isFastForward;

    void start();

   public:
    GameScreenController(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const override;

   public slots:
    void returnToMenu();

    void gameTick();
    void viewTick();

    void playPause();
    void fastForward();

    void addTurret(model::Position position, model::TurretType turretType);
    void removeTurret(model::Position position);
};

}  // namespace controller

#endif