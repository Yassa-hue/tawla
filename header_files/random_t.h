//
// Created by yassatamer on 04/09/2021.
//

#ifndef main_pivot

#define main_pivot 1e4+7

#endif

#ifndef main_seed

#define main_seed 1007

#endif


#ifndef max_number

#define max_number 6

#endif


#ifndef TAWLA_RANDOM_T_H
#define TAWLA_RANDOM_T_H


#include <cstdlib>


class random_t {
private:

    int pivot, seed;

public:
    random_t();

    random_t(const int _pivot, const int _seed);

    int random_number ();

    void set_pivot(const int _pivot);

    void set_seed(const int _seed);
};


#endif //TAWLA_RANDOM_T_H
