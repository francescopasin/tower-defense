#ifndef VIEW_SETMAPVIEW_H_
#define VIEW_SETMAPVIEW_H_

#include <QGraphicsView>
#include <memory>

#include "model/gamemodel.h"
#include "view/screens/setMapScreen/setmapscene.h"

using std::shared_ptr;

#define SP shared_ptr

namespace view {

class SetMapView : public QGraphicsView {
   private:
    SP<SetMapScene> _scene;

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    SetMapView(const SP<SetMapScene>& scene);
};

}  // namespace view

#endif
