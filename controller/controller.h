#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <QGraphicsScene>
#include <memory>

#include "app/routes.h"
#include "model/gamemodel.h"

using std::shared_ptr;
#define SP shared_ptr

namespace controller {

class Controller : public QObject {
    Q_OBJECT

   protected:
    SP<model::GameModel> _model;

   public:
    Controller(const SP<model::GameModel>& model);

    virtual QGraphicsScene* getScene() const = 0;

   signals:
    void navigateTo(app::Routes route);
};

}  // namespace controller

#endif