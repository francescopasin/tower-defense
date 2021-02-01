#ifndef CONTROLLER_SETMAPCONTROLLER_H_
#define CONTROLLER_SETMAPCONTROLLER_H_

#include <memory>

#include "controller/controller.h"
#include "view/screens/setMapScreen/setmapscene.h"

using std::shared_ptr;
#define SP shared_ptr

namespace controller {

class SetMapScreenController : public Controller {
    Q_OBJECT

   private:
    view::SetMapScene* _scene;

    vector<model::Position> createPath(model::Position start, const vector<view::SetMapCell*>* cells);

   public:
    SetMapScreenController(const SP<model::GameModel>& model);
    virtual ~SetMapScreenController() = default;

   public slots:
    void saveToFile(const vector<view::SetMapCell*>* cells);
};

}  // namespace controller

#endif