#ifndef VIEW_TUTORIALSCENE_H_
#define VIEW_TUTORIALSCENE_H_

#include <QGraphicsScene>

namespace view {

class TutorialScene : public QGraphicsScene {
   private:
    void drawBackground();

   public:
    TutorialScene();
};

}  // namespace view

#endif