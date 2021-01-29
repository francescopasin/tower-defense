#ifndef CONTROLLER_SETMAPCONTROLLER_H_
#define CONTROLLER_SETMAPCONTROLLER_H_

#include "model/gamemodel.h"
#include "view/screens/gameScreen/gamescene.h"
#include "view/screens/setMapScreen/setmapscene.h"

namespace controller {

class SetMapController : public QObject {
    Q_OBJECT

   private:
    SP<view::SetMapScene> _viewSetMap;
    SP<view::GameScene> _viewGame;
    SP<model::GameModel> _model;
    vector<model::Position>
    createPath(model::Position start, const vector<view::SetMapCell*>* cells);

   public:
    SetMapController(const SP<model::GameModel>& model, const SP<view::SetMapScene>& viewSetMap, const SP<view::GameScene>& viewGame);

   public slots:
    void saveToFile(const vector<view::SetMapCell*>* cells);
    void uploadFromFile();
};

}  // namespace controller

#endif
