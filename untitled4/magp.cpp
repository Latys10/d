#include "magp.h"

QList<QString> MagP::craft() const {
    return {
        "Маг", name, element, QString::number(mana),
        QString::number(health),
        QString::number(armor.helmet),
        QString::number(armor.chestplate),
        QString::number(armor.boots)
    };
}
