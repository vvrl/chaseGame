#pragma once

#include "Characters.h"


class Arena {
    
    int length, width;
    Prey* prey;
    Predator* predator;

public:

    Arena(int w, int l, Prey* prey, Predator* predator) {
        this->length = l;
        this->width = w;
        this->prey = prey;
        this->predator = predator;
    }
       
    //friend void Prey::AutoMove(const Arena& a, int z);
    //friend void Predator::AutoMove(const Arena& ar, int z);

    friend ostream& operator<<(ostream&, const Arena&);

};



ostream& operator<<(ostream& out, const Arena& a) {
    cout << "\033[2J\033[1;1H\n\n";
    

    cout << "\n\t  ";
    
    for (int i = 0; i < a.width; i++) cout << "——";
    cout << "\n";

    string fill = "";

    for (int i = 0; i < a.width; i++) fill += "  ";
 
    for (int i = 0; i < a.length; i++) cout <<"\t" << i + 1 << "|" << fill << "| \n";

    cout << "\t  ";
    for (int i = 0; i < a.width; i++) cout << "——";
    cout << "\n";

    cout << "\t  ";
    for (int i = 0; i < a.width; i++) cout << i + 1 << " ";
    cout << "\n\t";

 
    //for (int i = 0; i < a.l; i++) {
    //    if ((i + 1) / 10 == 0) cout << i + 1 << " |";
    //    else cout << i + 1 << "|";
    //    if (a.prey->location.y == i + 1 && a.predator->location.y == i + 1) {
    //        if (a.prey->location.x > a.predator->location.x) {
    //            for (int j = 1; j < a.predator->location.x; j++) {
    //                cout << "  ";
    //            }
    //            cout << "Х ";
    //            for (int j = a.predator->location.x + 1; j < a.prey->location.x; j++) {
    //                cout << "  ";
    //            }
    //            cout << "Ж ";
    //            for (int j = a.prey->location.x + 1; j <= a.w; j++) {
    //                cout << "  ";
    //            }
    //        }
    //        else if (a.predator->location.x > a.prey->location.x) {
    //            for (int j = 1; j < a.prey->location.x; j++) {
    //                cout << "  ";
    //            }
    //            cout << "Ж ";
    //            for (int j = a.prey->location.x + 1; j < a.predator->location.x; j++) {
    //                cout << "  ";
    //            }
    //            cout << "Х ";
    //            for (int j = a.predator->location.x + 1; j <= a.w; j++) {
    //                cout << "  ";
    //            }
    //        }
    //        else if (a.predator->location.x == a.prey->location.x) {
    //            for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
    //            cout << "Х ";
    //            for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
    //        }
    //    }
    //    else if (a.prey->location.y == i + 1) {
    //        for (int j = 1; j < a.prey->location.x; j++) cout << "  ";
    //        cout << "Ж ";
    //        for (int j = a.prey->location.x; j < a.w; j++) cout << "  ";
    //    }
    //    else if (a.predator->location.y == i + 1) {
    //        for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
    //        cout << "Х ";
    //        for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
    //    }
    //    else if (a.prey->location.y != i + 1 && a.predator->location.y != i + 1) {
    //        for (int j = 0; j < a.w; j++) cout << "  ";
    //    }
    //    cout << "|\n";
    //}
    //cout << "  ";
    //for (int i = 0; i < a.w + 1; i++) cout << "--";
    //cout << "\n";





    return out;
}




//bool check(const Prey& prey, const Predator& predator) {
//
//    if (prey.location.x == predator.location.x && abs(prey.location.y - predator.location.y) <= 5) {
//        return 1;
//    }
//    else if (prey.location.y == predator.location.y && abs(prey.location.x - predator.location.x) <= 5) {
//        return 1;
//    }
//    else return 0;
//}
//
//
//bool check1(const Prey& prey, const Predator& predator) {
//    if ((prey.location.x == predator.location.x) && (prey.location.y == predator.location.y)) return 1;
//    else return 0;
//}