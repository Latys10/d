#ifndef VRAGP_H
#define VRAGP_H

#include "person.h"

class VragP : public Person {
private:
    QString rarity;
    int damage;
public:
    VragP(const QString& name = "", const QString& rarity = "", int damage = 0,
          int health = 0, const Armor& armor = Armor())
        : Person(name, health, armor), rarity(rarity), damage(damage) {}
    QString getRarity() const { return rarity; }
    int getDamage() const { return damage; }
    QList<QString> craft() const override;
};

#endif // VRAGP_H
