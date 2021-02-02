#include "controller/tutorialscreencontroller.h"

#include "view/screens/tutorialScreen/tutorialview.h"

namespace controller {

TutorialScreenController::TutorialScreenController(const SP<model::GameModel>& model) : Controller(model) {
    _scene = new view::TutorialScene();
    _view = new view::TutorialView(_scene);
}

}  // namespace controller
