//
// Created by yassatamer on 04/09/2021.
//

#include "../header_files/random_t.h"


random_t::random_t() : pivot(main_pivot), seed(main_seed) {

}


random_t::random_t(const int _pivot, const int _seed) : random_t() {
    set_pivot(_pivot);
    set_seed(_seed);
}

int random_t::random_number () {
    return rand();
}

void random_t::set_pivot(const int _pivot) {
//    if (_pivot <= main_pivot && _pivot > 1)
//        pivot = _pivot;

    srand(_pivot);
}


void random_t::set_seed(const int _seed) {
    if (_seed <= main_seed && _seed > 1)
        seed = _seed;
}