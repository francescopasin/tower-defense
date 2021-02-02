#include "view/screens/tutorialScreen/tutorialcontent.h"

#include <QGraphicsScene>
#include <QPainter>

#include "model/turrets/turrettype.h"

using model::TurretStats;
using model::TurretType;
using model::turretTypes;

namespace view {

TutorialContent::TutorialContent(const QSizeF &size) : _size(size), currentStep(1) {
    nextStepButton = new StandardButton("NEXT", 200, this);
    nextStepButton->setPos(_size.width() / 2 - 100, _size.height() - 250);

    connect(nextStepButton, &StandardButton::pressed, this, &TutorialContent::nextStep);
}

QRectF TutorialContent::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void TutorialContent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QFont font = painter->font();
    font.setPixelSize(30);
    font.setFamily("Press Start 2P");
    painter->setFont(font);
    painter->setPen(Qt::white);

    QPixmap pixmap;
    TurretStats stats;

    switch (currentStep) {
        case 1:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, _size.height() / 6, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Welcome to CPP - Crush Poor Programmers");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 6, _size.height() / 6 + 50, _size.width() * 2 / 3, _size.height() * 2 / 3),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Your objective is to destroy all students, preventing them to reach 30 in the exam.\n"
                "You can achieve this by using some complex c++ concepts that they can't understand");
            break;
        case 2:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "The game rules");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, _size.height() * 3 / 4),
                Qt::AlignHCenter | Qt::TextWordWrap,
                "When the game starts students begin to spawn, trying to reach the end of the path.\n"
                "There are different students waves during a match, each one with different statistics.\n"
                "If a student reaches the end of the path you loose life. When your life reaches 0 it's game over.\n\n"
                "You have some initial game credits. Use them to strategically place turrets in order to defeat students.\n"
                "When a student dies you earn some credit.\n\n"
                "If you manage to destroy all students you win!");
            break;
        case 3:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "The game field");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, 100),
                Qt::AlignCenter | Qt::TextWordWrap,
                "The game map consists of three different cells:");

            pixmap = QPixmap(":/assets/images/horizontal-tile.png");
            painter->drawPixmap(QRect(_size.width() / 8, 350, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Path cells:\n"
                "the cells where the students will walk");

            pixmap = QPixmap(":/assets/images/free-tile.png");
            painter->drawPixmap(QRect(_size.width() / 8, 500, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Free cells:\n"
                "the cells where you can place the turrets");

            pixmap = QPixmap(":/assets/images/blocked-tile.png");
            painter->drawPixmap(QRect(_size.width() / 8, 650, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 650, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Blocked cells:\n"
                "the cells where you can't place any turret");
            break;
        case 4:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Turrets - Part 1");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, 100),
                Qt::AlignCenter | Qt::TextWordWrap,
                "The are 5 types of turrets in the game:");

            // WEAK
            // ================================================================

            // TODO: refactor list items to external class. add icons

            pixmap = QPixmap(":/assets/images/missing-image.png");
            painter->drawPixmap(QRect(_size.width() / 8, 350, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Weak Turret");

            font.setPixelSize(20);
            painter->setFont(font);

            stats = turretTypes.at(TurretType::WeakTurret);

            painter->drawText(
                QRectF(_size.width() / 8 + 700, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Cost: %1"
                        "\n"
                        "Max targets: %2"
                        "\n"
                        "Radius: %3")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius));

            painter->drawText(
                QRectF(_size.width() / 8 + 1200, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Damage: %1"
                        "\n"
                        "Cooldown: %2")
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));

            // MITRA
            // ================================================================

            pixmap = QPixmap(":/assets/images/missing-image.png");
            painter->drawPixmap(QRect(_size.width() / 8, 500, 128, 128), pixmap);

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Mitra Turret");

            font.setPixelSize(20);
            painter->setFont(font);

            stats = turretTypes.at(TurretType::MitraTurret);

            painter->drawText(
                QRectF(_size.width() / 8 + 700, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Cost: %1"
                        "\n"
                        "Max targets: %2"
                        "\n"
                        "Radius: %3")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius));

            painter->drawText(
                QRectF(_size.width() / 8 + 1200, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Damage: %1"
                        "\n"
                        "Cooldown: %2")
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));

            // GRANADE
            // ================================================================

            pixmap = QPixmap(":/assets/images/missing-image.png");
            painter->drawPixmap(QRect(_size.width() / 8, 650, 128, 128), pixmap);

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 650, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Granade Turret");

            font.setPixelSize(20);
            painter->setFont(font);

            stats = turretTypes.at(TurretType::GranadeTurret);

            painter->drawText(
                QRectF(_size.width() / 8 + 700, 650, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Cost: %1"
                        "\n"
                        "Max targets: %2"
                        "\n"
                        "Radius: %3")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius));

            painter->drawText(
                QRectF(_size.width() / 8 + 1200, 650, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Damage: %1"
                        "\n"
                        "Cooldown: %2")
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));

            break;
        case 5:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Turrets - Part 2");

            font.setPixelSize(30);
            painter->setFont(font);

            // COMBO
            // ================================================================

            pixmap = QPixmap(":/assets/images/missing-image.png");
            painter->drawPixmap(QRect(_size.width() / 8, 350, 128, 128), pixmap);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Combo Turret");

            font.setPixelSize(20);
            painter->setFont(font);

            stats = turretTypes.at(TurretType::ComboTurret);

            painter->drawText(
                QRectF(_size.width() / 8 + 700, 350, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Cost: %1"
                        "\n"
                        "Max targets: %2"
                        "\n"
                        "Radius: %3")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius));

            painter->drawText(
                QRectF(_size.width() / 8 + 1200, 350, 400, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Damage: %1"
                        "\n"
                        "Cooldown: %2")
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));

            // SPLIT
            // ================================================================

            pixmap = QPixmap(":/assets/images/missing-image.png");
            painter->drawPixmap(QRect(_size.width() / 8, 500, 128, 128), pixmap);

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8 + 200, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                "Split Turret");

            font.setPixelSize(20);
            painter->setFont(font);

            stats = turretTypes.at(TurretType::SplitTurret);

            painter->drawText(
                QRectF(_size.width() / 8 + 700, 500, _size.width() * 3 / 4, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Cost: %1"
                        "\n"
                        "Max targets: %2"
                        "\n"
                        "Radius: %3")
                    .arg(stats.cost)
                    .arg(stats.maxTargets == -1 ? "infinite" : QString::number(stats.maxTargets))
                    .arg(stats.attackRadius));

            painter->drawText(
                QRectF(_size.width() / 8 + 1200, 500, 400, 128),
                Qt::AlignVCenter | Qt::TextWordWrap,
                QString("Damage: %1"
                        "\n"
                        "Cooldown: %2")
                    .arg(stats.initialAttackDamage)
                    .arg(stats.initialAttackCooldown));

            break;
        case 6:
            font.setPixelSize(50);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 50, _size.width() * 3 / 4, 150),
                Qt::AlignCenter | Qt::TextWordWrap,
                "Additional infos");

            font.setPixelSize(30);
            painter->setFont(font);

            painter->drawText(
                QRectF(_size.width() / 8, 200, _size.width() * 3 / 4, _size.height() * 3 / 4),
                Qt::AlignHCenter | Qt::TextWordWrap,
                "You can remove a turret by clicking on it.\n"
                "Removing a turret will restore half of its cost.\n\n"
                "If the game is too slow for you you can speed it up by clicking the fast forward button on the top right corner.\n\n"
                "Now you are ready to start playing.\n\n"
                "Go destroy some students!!!");
            break;
        default:
            // Nothing to do
            break;
    }
}

void TutorialContent::nextStep() {
    currentStep++;

    if (currentStep == 6) {
        scene()->removeItem(nextStepButton);
        delete nextStepButton;

        StandardButton *startGameButton = new StandardButton("START PLAYING", 500, this);
        startGameButton->setPos(_size.width() / 2 - 700, _size.height() - 250);

        connect(startGameButton, &StandardButton::pressed, this, &TutorialContent::startPlayPressed);

        StandardButton *mainMenuButton = new StandardButton("RETURN TO MENU", 500, this);
        mainMenuButton->setPos(_size.width() / 2 + 200, _size.height() - 250);

        connect(mainMenuButton, &StandardButton::pressed, this, &TutorialContent::returnToMenuPressed);
    }

    update();
}

}  // namespace view
