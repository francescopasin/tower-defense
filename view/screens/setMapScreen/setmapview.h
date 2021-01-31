#ifndef VIEW_SETMAPVIEW_H_
#define VIEW_SETMAPVIEW_H_

#include <QGraphicsView>

#include "view/screens/setMapScreen/setmapscene.h"

namespace view {

class SetMapView : public QGraphicsView {
   private:
    SetMapScene* _scene;

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    SetMapView(SetMapScene* scene);
};

}  // namespace view

#endif
