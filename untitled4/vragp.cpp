#include "vragp.h"

QList<QString> VragP::craft() const {
    return {
        "Враг", name, rarity, QString::number(damage),
        QString::number(health),
        QString::number(armor.helmet),
        QString::number(armor.chestplate),
        QString::number(armor.boots)
    };
}
