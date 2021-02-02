#include "controller/tutorialscreencontroller.h"

#include "app/routes.h"
#include "view/screens/tutorialScreen/tutorialview.h"

namespace controller {

TutorialScreenController::TutorialScreenController(const SP<model::GameModel>& model) : Controller(model) {
    _scene = new view::TutorialScene();
    _view = new view::TutorialView(_scene);

    connect(
        _scene,
        &view::TutorialScene::startGame,
        this,
        [=]() { emit navigateTo(app::Routes::GameScreen); });

    connect(
        _scene,
        &view::TutorialScene::returnToMenu,
        this,
        [=]() { emit navigateTo(app::Routes::InitialScreen); });
}

}  // namespace controller
