#ifndef VIEW_SETMAPSCENE_H_
#define VIEW_SETMAPSCENE_H_

#include <QGraphicsScene>
#include <vector>

using std::shared_ptr;
using std::vector;

#define SP shared_ptr

namespace view {

class SetMapScene : public QGraphicsScene {
    Q_OBJECT

   private:
    void drawBackground();
    void createHUD();

   public:
    SetMapScene();

   signals:
    void saveButtonPressed();
    void clearButtonPressed();
};

}  // namespace view

#endif
