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

    //0 - вверх 1 - вправо 2 - вниз 3 - влево 4 - вверх-влево 
    //5 - вверх-вправо 6 - вниз-вправо 7 - вниз-влево
    void MoveTo(int direction, int steps) {
        
        int deltaX(0), deltaY(0);

        switch (direction)
        {
        case 0:
            deltaY = 1;
            break;
        case 1:
            deltaX = 1;
            break;
        case 2:
            deltaY = -1;
            break;
        case 3:
            deltaX = -1;
            break;
        case 4:
            deltaX = -1;
            deltaY = 1;            
            break;
        case 5:
            deltaX = 1;
            deltaY = 1;
            break;
        case 6:
            deltaX = 1;
            deltaY = -1;            
            break;
        case 7:
            deltaX = -1;
            deltaY = -1;            
            break;
        default:
            break;
        }

        location.setPoint(location.getX() + deltaX*steps, location.getY() + deltaY*steps);
    }

    Point2D getLocation() {
        return location;
    }

    bool isNPC() { return npc; }

    virtual void AutoMove() = 0;

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

    const int range = 1;

public:
    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0) : Character(name, location, npcFlag) {   }

    void AutoMove() override;

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);

};



class Predator : Character{
private:
    //friend Prey;
    //friend class Arena;
    //friend ostream& operator<<(ostream&, const Arena&);

    int range;

public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0) 
        : Character(name, location, npcFlag), range(0) {   }


    void AskRange() {
        do {
            cout << "На сколько? (1-5)" << endl;
            cin >> range;
            if (1 <= range && range <= 5) break;
        } while (true);
    }

    void AutoMove();

    //friend ostream& operator<<(ostream&, const Predator&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
};




void Prey::AutoMove() {
    
    int direction;

    if (isNPC()) {
        direction = rand() % 8;        
    }
    else {
        cout << "Куда идти?\n0-вверх-влево 1-вверх 2-вверх-вправо 3-влево 4-вправо 5-вниз-влево 6-вниз 7-вниз-вправо" << endl;
        cin >> direction;
    }
    
    MoveTo(direction, range);   
}



void Predator::AutoMove() {
    
    int direction;

    if (isNPC()) {
        direction = rand() % 4;
        SetRange(rand() % 5 + 1);
    }
    else {
        int s = 0;
        cout << "Куда идти?\n0-вверх 1-вправо 2-вниз 3-влево" << endl;
        cin >> direction;
    }

    switch (q) {
    case 0:
        if (location.y >= (a)) {
            location.y -= a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 1:
        if (location.x <= (ar.w - a)) {
            location.x += a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 2:
        if (location.y <= (ar.l - a)) {
            location.y += a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 3:
        if (location.x >= (a)) {
            location.x -= a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    }
}
