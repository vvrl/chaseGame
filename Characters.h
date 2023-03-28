#pragma once

#include "Point2D.h"

class Character {

private:

    string name;        // имя персонажа
    Point2D location;   // текущее положение персонажа
    bool npc;           // признак NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : name(name), location(location), npc(npcFlag){   }

    //0 - вверх 1 - вправо 2 - вниз 3 - влево 4 - вверх-влево 
    //5 - вверх-вправо 6 - вниз-вправо 7 - вниз-влево
    void moveTo(int direction, int steps) {
        
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

    virtual void autoMove() = 0; 

    //ostream& operator<<(ostream& out, const Character& p) {
    //    out << "Имя персонажа - " << p.name << "Координаты персонажа - " << p.location << endl;
    //    return out;
    //}
};

class Prey : public Character {

private:

    //friend ostream& operator<<(ostream&, const Arena&);
    //friend Predator;
    //friend class Arena;

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0) : Character(name, location, npcFlag) {   }

    int askDirection() {

        do {

            int direction(0);
            cout << "Куда идти?" << endl;
            cout << "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево," << endl;
            cout << "4 - вверх - влево, 5 - вверх-вправо, 6 - вниз-вправо, 7 - вниз-влево" << endl;
            cin >> direction;

            if (direction <= 7 && direction>=0) {
                return direction;
            }
            else cout << "Некорректный ввод, попробуй ещё раз " << endl;

        } while (true);

    }

    void autoMove() override {

        int direction = 0;

        if (isNPC()) {
            direction = rand() % 8;
        }
        else {
            direction = askDirection();
        }

        moveTo(direction, maxRange);
    }

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);

};

class Predator : public Character{
private:
    //friend Prey;
    //friend class Arena;
    //friend ostream& operator<<(ostream&, const Arena&);

    const int maxRange = 5;
 
public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0) 
        : Character(name, location, npcFlag) {   }

    int askRange() {

        do {
            int range;
            cout << "На сколько? (1-5)" << endl;
            cin >> range;

            if (range >= 1 && range <= maxRange) {
                return range;     
            }
            else cout << "Некорректный ввод, попробуй ещё раз " << endl;

        } while (true);
    }

    int askDirection() {
        do {

            int direction(0);
            cout << "Куда идти?" << endl;
            cout << "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево," << endl;
            cin >> direction;

            if (direction <= 3 && direction >= 0) {
                return direction;
            }
            else cout << "Некорректный ввод, попробуй ещё раз " << endl;

        } while (true);       

    }

    void autoMove() override {

        int direction = 0;
        int range = 0;

        if (isNPC()) {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else {
            direction = askDirection();
            range = askRange();
        }

        moveTo(direction, range);
    }

    //friend ostream& operator<<(ostream&, const Predator&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
};