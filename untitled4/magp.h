#ifndef MAGP_H
#define MAGP_H

#include "person.h"

class MagP : public Person {
private:
    QString element;
    int mana;
public:
    MagP(const QString& name = "", const QString& element = "", int mana = 0,
         int health = 0, const Armor& armor = Armor())
        : Person(name, health, armor), element(element), mana(mana) {}
    QString getElement() const { return element; }
    int getMana() const { return mana; }
    QList<QString> craft() const override;
};

#endif // MAGP_H
