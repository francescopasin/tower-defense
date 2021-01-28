#ifndef CONTROLLER_SETMAPCONTROLLER_H_
#define CONTROLLER_SETMAPCONTROLLER_H_

#include "model/gamemodel.h"
#include "view/screens/setMapScreen/setmapscene.h"

namespace controller {

class SetMapController : public QObject {
    Q_OBJECT

   private:
    SP<view::SetMapScene> _view;
    SP<model::GameModel> _model;
    vector<model::Position>
    createPath(model::Position start, const vector<view::SetMapCell*>* cells);

   public:
    SetMapController(const SP<model::GameModel>& model, const SP<view::SetMapScene>& view);

   public slots:
    void saveToFile(const vector<view::SetMapCell*>* cells);
    void uploadFromFile();

   signals:
    void saved();
    void mapChanged();
};

}  // namespace controller

#endif
