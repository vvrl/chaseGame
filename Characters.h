#pragma once

#include "Point2D.h"

class Character {

private:

    string name;
    Point2D location;
    bool npc;

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : name(name), location(location), npc(npcFlag){   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    Point2D getLocation() {
        return location;
    }

    bool isNPC() { return npc; }

    //ostream& operator<<(ostream& out, const Character& p) {
    //    out << "Имя персонажа - " << p.name << "Координаты персонажа - " << p.location << endl;
    //    return out;
    //}
};


class Prey : Character {

private:

    //friend ostream& operator<<(ostream&, const Arena&);
    //friend Predator;
    //friend class Arena;

public:
    Prey(const std::string& name, const Point2D& location) : Character(name, location) {   }

    //void AutoMove(const Arena&, int z);

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);

};



class Predator : Character{
private:
    //friend Prey;
    //friend class Arena;
    //friend ostream& operator<<(ostream&, const Arena&);

public:
    Predator(const std::string& name, const Point2D& location) : Character(name, location) {   }


    //void AutoMove(const Arena&, int z);

    //friend ostream& operator<<(ostream&, const Predator&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
};