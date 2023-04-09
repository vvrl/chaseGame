#pragma once

#include <iostream>
#include "Point2D.h"

class Character {

private:

    std::string name;        // имя персонажа
    Point2D location;   // текущее положение персонажа
    bool npc;           // признак NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0);

    void moveTo(Point2D point);

    //0 - вверх 1 - вправо 2 - вниз 3 - влево 4 - вверх-влево 
    //5 - вверх-вправо 6 - вниз-вправо 7 - вниз-влево
    void moveTo(int direction, int steps);

    Point2D getLocation();

    bool isNPC();

    virtual void autoMove() = 0;

    std::string getName() { return name; }
};



class Prey : public Character {

private:

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0);

    int askDirection();

    void autoMove() override;



};



class Predator : public Character{
private:

    const int maxRange = 5;
 
public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0) 
        : Character(name, location, npcFlag) {   }

    int askRange();

    int askDirection();

    void autoMove() override;
};