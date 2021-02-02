#ifndef VIEW_TUTORIALVIEW_H_
#define VIEW_TUTORIALVIEW_H_

#include <QGraphicsView>

#include "view/screens/tutorialScreen/tutorialscene.h"

namespace view {

class TutorialView : public QGraphicsView {
   private:
    TutorialScene* _scene;

   public:
    TutorialView(TutorialScene* scene);

   protected:
    void resizeEvent(QResizeEvent* event) override;
};

}  // namespace view

#endif