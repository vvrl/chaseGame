#pragma once

#include <array>
#include "Characters.h"


class Arena {
    
    int length, width;
    Prey* prey;
    Predator* predator;
    
    char** field;

public:

    Arena(int w, int l, Prey* prey, Predator* predator) {
        //TODO: Проверка диапазона l w от (1 до 99)       
        this->length = l;

        w = w * 2;

        this->width = w;
        this->prey = prey;
        this->predator = predator;
        field = new char* [l];

        for (int i = 0; i < l ; i++)
        {
            field[i] = new char[w];

            for (int j = 0; j < w; j++)
            {
                field[i][j] = ' ';
            }
        }

        
        for (int i = l-1; i >= 0; i--) {          
            
            if (l - i > 9) {
                int tmp = ((l - i) / 10);
                field[i][0] = ((l - i) / 10) + '0';
                field[i][1] = ((l - i) % 10) + '0';
            }
            else field[i][1] = l - i + '0';       

            field[i][2] = '|';
        }





        for (int i = 0; i < w; i++)
        {
            int cell_num = 1 + (i / 2);

            if (cell_num > 9) {
                
                if ((i + 1) % 2 == 0) {
                    field[l - 1][i] = (cell_num % 10) + '0';
                }
                else field[l - 1][i] = (cell_num / 10) + '0';
                
            }
            else {
                if ( (i+1) % 2 == 0) {
                    field[l - 1][i] = cell_num + '0';
                }
                else field[l - 1][i] = ' ';
            }

        }

        for (int i = 3; i < w; i++)
        {
            field[l - 2][i] = '_';
        }

    }
    
    ~Arena() {
        delete [] field;
    }

    //friend void Prey::AutoMove(const Arena& a, int z);
    //friend void Predator::AutoMove(const Arena& ar, int z);

    friend ostream& operator<<(ostream&, const Arena&);

};



ostream& operator<<(ostream& out, const Arena& a) {
    
    int preyX = (a.prey->getLocation().getX()*2)+3;

    int preyY = a.prey->getLocation().getY()+2;

    a.field[a.length - preyY][preyX] = '^';

    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a.width; j++) {
            cout << a.field[i][j];
        }
        cout << "\n";
    }
   
    int aaqaa = 0;
    
    //cout << "\033[2J\033[1;1H\n\n";
    //

    //cout << "\n\t  ";
    //
    //for (int i = 0; i < a.width; i++) cout << "——";
    //cout << "\n";

    //string fill = "";

    //for (int i = 0; i < a.width; i++) fill += "  ";
 
    //for (int i = 0; i < a.length; i++) cout <<"\t" << i + 1 << "|" << fill << "| \n";

    //cout << "\t  ";
    //for (int i = 0; i < a.width; i++) cout << "——";
    //cout << "\n";

    //cout << "\t  ";
    //for (int i = 0; i < a.width; i++) cout << i + 1 << " ";
    //cout << "\n\t";

 
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