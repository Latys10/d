#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QList>

struct Armor {
    int helmet;
    int chestplate;
    int boots;
    Armor(int h = 0, int c = 0, int b = 0) : helmet(h), chestplate(c), boots(b) {}
};

class Person {
protected:
    QString name;
    int health;
    Armor armor;
public:
    Person(const QString& name = "", int health = 0, const Armor& armor = Armor())
        : name(name), health(health), armor(armor) {}
    virtual ~Person() {}
    QString getName() const { return name; }
    int getHealth() const { return health; }
    Armor getArmor() const { return armor; }
    virtual QList<QString> craft() const = 0;
};

#endif // PERSON_H
