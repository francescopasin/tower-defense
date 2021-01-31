#ifndef VIEW_INITIALSCREENVIEW_H_
#define VIEW_INITIALSCREENVIEW_H_

#include <QGraphicsView>

#include "view/screens/initialScreen/initialscreenscene.h"

namespace view {

class InitialScreenView : public QGraphicsView {
   private:
    InitialScreenScene* _scene;

   public:
    InitialScreenView(InitialScreenScene* scene);

   protected:
    void resizeEvent(QResizeEvent* event) override;
};

}  // namespace view

#endif