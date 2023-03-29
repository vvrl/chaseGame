#pragma once

#include <array>
#include "Characters.h"


class Arena {
    
    int length, width;
    Prey* prey;
    Predator* predator;
    
    char** field;

public:

    Arena(int l, int w, Prey* prey, Predator* predator) {
        //TODO: Проверка диапазона l w от (1 до 99)       
        
        // увеличение размера поля для постоянных символов (границы, координаты)
        int shift_l = 3; 
        int shift_w = 4; 

        w = w * 2;       // удвоим ширину поля (для симметрии клеток при отображении)
        
        length = l + shift_l;
        width = w + shift_w;
        this->prey = prey;
        this->predator = predator;
        
        // Выделение памяти под массив field размером length x width
        field = new char* [l];

        for (int i = 0; i < length ; i++) {
            
            field[i] = new char [width];

            for (int j = 0; j < width; j++)
            {
                field[i][j] = '.';
            }
        }

        // Заполнение массива декоративными символами

        // Верхняя и нижняя грань поля
        for (int j = 2; j < width; j++) {
            field[0][j] = '-';
            field[length - 2][j] = '-';

            // Нумерация снизу
            int cell_num = (j / 2);

            if (j >= width - 2) continue;

            if (cell_num > 9) {
                
                if ((j + 1) % 2 == 0) {
                    field[length - 1][j+1] = (cell_num % 10) + '0';
                }
                else field[length - 1][j+1] = (cell_num / 10) + '0';
                
            }
            else {
                if ( (j+1) % 2 == 0) {
                    field[length - 1][j+1] = cell_num + '0';
                }
                else field[length - 1][j+1] = ' ';
            }
        }

        // Левая и правая грань поля
        for (int i = 1; i < length - 2; i++) {
                       
            field[i][2] = '|';
            field[i][width - 1] = '|';
        
            // Нумерации слева            
            int y_coords = length - shift_l + 1;
            
            if (y_coords - i > 9) {
                int tmp = ((y_coords - i) / 10);
                field[i][0] = ((y_coords - i) / 10) + '0';
                field[i][1] = ((y_coords - i) % 10) + '0';
            }
            else field[i][1] = y_coords - i + '0';
        }
    }

    void clearStep() {
        // Удаление жертвы
        int preyX = (prey->getLocation().getX() * 2) + 2;
        int preyY = prey->getLocation().getY() + 2;

        field[length - preyY][preyX] = ' ';
        field[length - preyY][preyX - 1] = ' ';

        // Удаление хищника
        int predX = (predator->getLocation().getX() * 2) + 2;
        int predY = predator->getLocation().getY() + 2;

        field[length - predY][predX] = ' ';
        field[length - predY][predX - 1] = ' ';
    }
    
    ~Arena() {
        
        //TODO: Проверить правильность освобождения памяти
        for (int i = 0; i < length; i++) {

            delete[] field[i];
        }
    }

    //friend void Prey::AutoMove(const Arena& a, int z);
    //friend void Predator::AutoMove(const Arena& ar, int z);

    friend ostream& operator<<(ostream&, const Arena&);

};



ostream& operator<<(ostream& out, const Arena& a) {
    
    // Размещение жертвы
    int preyX = (a.prey->getLocation().getX()*2)+2;
    int preyY = a.prey->getLocation().getY()+2;

    a.field[a.length - preyY][preyX] = ')';
    a.field[a.length - preyY][preyX-1] = '(';

    // Размещение хищника
    int predX = (a.predator->getLocation().getX() * 2) + 2;
    int predY = a.predator->getLocation().getY() + 2;

    a.field[a.length - predY][predX] = '*';
    a.field[a.length - predY][predX - 1] = '*';


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