#pragma once

#include "Characters.h"


class Arena {
    
    int l, w;
    Prey* prey;
    Predator* predator;

public:

    Arena(int w, int l, Prey* prey, Predator* predator) {
        this->l = l;
        this->w = w;
        this->prey = prey;
        this->predator = predator;
    }


    
    //friend void Prey::AutoMove(const Arena& a, int z);
    //friend void Predator::AutoMove(const Arena& ar, int z);

    friend ostream& operator<<(ostream&, const Arena&);

};