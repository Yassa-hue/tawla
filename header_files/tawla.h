//
// Created by yassatamer on 04/09/2021.
//

#include "../header_files/main_header.h"

#ifndef TAWLA_TAWLA_H
#define TAWLA_TAWLA_H

#include "../header_files/random_t.h"



class tawla {
private:
    vector <vector<bool>> place;
    int dice1, dice2, home1, home2, pieces1, pieces2;
    bool current_player;
    random_t random_class;

    bool play_with_distance(const int _start, const int _end);
    bool eat_dice(int _dice);

    void throw_dice();

    void print() const;
public:
    tawla();
};


#endif //TAWLA_TAWLA_H
