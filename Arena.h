#pragma once

#include <iostream>
#include "Characters.h"


class Arena {
    
    int length, width;
    Prey* prey;
    Predator* predator;

    int view_length, view_width;   
    char** field;

public:

    Arena(int l, int w, Prey* prey, Predator* predator);

    void clearStep();
    bool checkOverRun();
    bool checkPosition();
    ~Arena();

    friend std::ostream& operator<<(std::ostream&, const Arena&);

};