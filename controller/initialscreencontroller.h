#ifndef CONTROLLER_INITIALSCREENCONTROLLER_H_
#define CONTROLLER_INITIALSCREENCONTROLLER_H_

#include <QGraphicsScene>
#include <memory>

#include "controller/controller.h"
#include "model/position.h"
#include "model/turrets/turrettype.h"
#include "view/screens/initialScreen/initialscreenscene.h"

using std::shared_ptr;
#define SP shared_ptr

namespace controller {

class InitialScreenController : public Controller {
    Q_OBJECT

   private:
    view::InitialScreenScene* _scene;

   public:
    InitialScreenController(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const override;

   public slots:
    void uploadFromFile();
};

}  // namespace controller

#endif