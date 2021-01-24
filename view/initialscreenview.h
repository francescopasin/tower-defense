#ifndef VIEW_INITIALSCREENVIEW_H_
#define VIEW_INITIALSCREENVIEW_H_

#include <QGraphicsView>
#include <memory>

#include "view/initialscreenscene.h"

using std::shared_ptr;

#define SP shared_ptr

namespace view {

class InitialScreenView : public QGraphicsView {
   private:
    SP<InitialScreenScene> _scene;

   public:
    InitialScreenView(const SP<InitialScreenScene>& scene);

   protected:
    void resizeEvent(QResizeEvent* event) override;
};

}  // namespace view

#endif