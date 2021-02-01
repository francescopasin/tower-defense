#include <QApplication>
#include <QException>
#include <memory>

#include "model/exception.h"
#include "view/mainwindow.h"

using std::make_shared;
using std::vector;

int main(int argc, char *argv[]) {
    QString error = "";
    int cod_res = 9999;
    while (cod_res == 9999) {
        QApplication a(argc, argv);

        // Model
        // ========================================================================
        auto model = make_shared<model::GameModel>();

        view::MainWindow window(model, error);

        try {
            // Start application
            window.show();
            cod_res = a.exec();
        } catch (const std::exception *e) {
            error = e->what();
        } catch (const std::exception &e) {
            error = e.what();
        } catch (const QException &e) {
            error = e.what();
        } catch (const QException *e) {
            error = e->what();
        } catch (...) {
            error = "FATAL ERROR";
        }

        model.reset();
    }
    return cod_res;
}
