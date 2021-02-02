#ifndef CONTROLLER_TUTORIALSCREENCONTROLLER_H_
#define CONTROLLER_TUTORIALSCREENCONTROLLER_H_

#include <memory>

#include "controller/controller.h"
#include "model/gamemodel.h"
#include "view/screens/tutorialScreen/tutorialscene.h"

using std::shared_ptr;
#define SP shared_ptr

namespace controller {

class TutorialScreenController : public Controller {
   private:
    view::TutorialScene* _scene;

   public:
    TutorialScreenController(const SP<model::GameModel>& model);
    virtual ~TutorialScreenController() = default;
};

}  // namespace controller

#endif