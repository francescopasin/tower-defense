#include "controller/initialscreencontroller.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

#include "view/screens/initialScreen/initialscreenview.h"

namespace controller {

InitialScreenController::InitialScreenController(const SP<model::GameModel>& model) : Controller(model) {
    _scene = new view::InitialScreenScene();
    _view = new view::InitialScreenView(_scene);

    connect(
        _scene,
        &view::InitialScreenScene::startButtonPressed,
        this,
        [=]() { emit navigateTo(app::Routes::GameScreen); });

    connect(
        _scene,
        &view::InitialScreenScene::setMapButtonPressed,
        this,
        [=]() { emit navigateTo(app::Routes::SetMapScreen); });

    connect(
        _scene,
        &view::InitialScreenScene::uploadMapButtonPressed,
        this,
        &controller::InitialScreenController::uploadFromFile);
}

void InitialScreenController::uploadFromFile() {
    // TODO: create level selector screen

    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Load a Game Path"), "", tr("CPP Game Path(*.cppmap)"));
    vector<model::Position> pathPosition;
    vector<model::Position> blockedPosition;

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(nullptr, tr("Unable to open file"), file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);

        QJsonObject json;

        in >> json;

        if (json.isEmpty()) {
            QMessageBox::information(nullptr, tr("No positions in file"), tr("The file you are attempting to open contains no position."));
        } else {
            QJsonArray pathJson = json["pathPosition"].toArray();
            for (auto i : pathJson) {
                pathPosition.push_back(model::Position{static_cast<U_INT>((i.toObject())["x"].toInt()), static_cast<U_INT>((i.toObject())["y"].toInt())});
            }
            QJsonArray blockedJson = json["blockedPosition"].toArray();
            for (auto i : blockedJson) {
                blockedPosition.push_back(model::Position{static_cast<U_INT>((i.toObject())["x"].toInt()), static_cast<U_INT>((i.toObject())["y"].toInt())});
            }

            try {
                _model->setMap(pathPosition, model::Direction::Left);
                _model->setBlocked(blockedPosition);
            } catch (std::exception* e) {
                QMessageBox::information(nullptr, tr("Path Error"), e->what());  // TODO: ERROR MODAL
            }
        }
    }
}

}  // namespace controller