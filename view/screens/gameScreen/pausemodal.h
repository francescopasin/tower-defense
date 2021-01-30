#ifndef VIEW_PauseModal_H_
#define VIEW_PauseModal_H_

#include "view/hud/modal.h"

namespace view {

class PauseModal : public Modal {
   protected:
    virtual void paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   public:
    PauseModal(qreal width, qreal height);

   signals:
    void returnToMenu();
};

}  // namespace view

#endif