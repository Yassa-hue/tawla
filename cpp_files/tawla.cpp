//
// Created by yassatamer on 04/09/2021.
//

#include "../header_files/tawla.h"

#include "../header_files/random_t.h"

tawla::tawla() : place(vector<vector<bool>> (27)), dice1(-1), dice2(-1), current_player(white), home1(0), home2(0),
    random_class(), pieces1(num_of_pieces), pieces2(num_of_pieces) {


    for (int i = 0; i < num_of_pieces; ++i) {
        place[1].push_back(white);
    }

    for (int i = 0; i < num_of_pieces; ++i) {
        place[24].push_back(black);
    }

    while (true) {
        if (pieces1 == 0) {
            cout << "player 1 win the game" << endl;
            break;
        }

        if (pieces2 == 0) {
            cout << "player 2 win the game" << endl;
            break;
        }

        throw_dice();

        print();


        int _start, _end, _eat, _mode;
        cout << "1 for move\n";
        if ((current_player == white && home1 == num_of_pieces) || (current_player == black && home2 == num_of_pieces))
            cout << "2 for eat\n";
        cout << " ==>> ";
        cin >> _mode;

        if (_mode == 1) {
            cout << "1 for dice 1 & 2\n2 for the sum\n";
            cin >> _mode;

            if (_mode == 1) {
                for (int dice = 1; dice <= 2; ++dice) {
                    while (true) {
                        cout << "dice " << dice << " : ";
                        cin >> _start >> _end;
                        if (_start + (dice == 1 ? dice1 : dice2) == _end && play_with_distance(_start, _end)) {
                            cout << "nice move" << endl;
                            break;
                        } else
                            cout << "wrong move, try again" << endl;
                    }
                }
            } else {
                while (true) {
                    cout << "dice 1,2 : ";
                    cin >> _start >> _end;
                    if (_start + dice1+ dice2 == _end && play_with_distance(_start, _end)) {
                        cout << "nice move" << endl;
                        break;
                    } else
                        cout <<  "wrong move, try again" << endl;
                }
            }
        } else {
            cout << "1 for dice 1 & 2\n2 for the sum\n";
            cin >> _mode;

            if (_mode == 1) {
                for (int dice = 1; dice <= 2; ++dice) {
                    while (true) {
                        cout << "dice " << dice << " : ";
                        cin >> _eat;
                        if (_eat == (dice == 1 ? dice1 : dice2) && eat_dice(_eat)) {
                            cout << "nice eat" << endl;
                            break;
                        } else
                            cout << "wrong eat, try again" << endl;
                    }
                }
            } else {
                while (true) {
                    cout << "dice 1,2 : ";
                    cin >> _eat;
                    if (_eat == dice1+ dice2 && eat_dice(_eat)) {
                        cout << "nice eat" << endl;
                        break;
                    } else
                        cout <<  "wrong eat, try again" << endl;
                }
            }

        }

    }



}


bool tawla::play_with_distance(const int _start, const int _end) {
    bool cur_end = (place[_end].empty() ? current_player : place[_end].back());
    if (place[_start].back() == current_player && (place[_end].empty() || cur_end == current_player || (cur_end == !current_player && place[_end].size() == 1))) {
        place[_start].pop_back();
        place[_end].push_back(current_player);
        if (_end >= 19)
            (current_player == white ? home1++ : home2++);
        return true;
    }
    return false;
}




bool tawla::eat_dice(int _dice) {
    _dice = 25 - _dice;
    if (place[_dice].back() == current_player) {
        place[_dice].pop_back();
        if (current_player == white)
            pieces1 --;
        else
            pieces2 --;
        return true;
    }
    return false;
}



void tawla::throw_dice() {
    dice1 = random_class.random_number();
    dice2 = random_class.random_number();
}



void tawla::print() const {

    cout << dice1 << ' ' << dice2 << endl;

    /*

     + white - black

     | | | | | | | | | | | | | |
                 |



                 |
     | | | | | | | | | | | | | |
     */


    for (int i = 0; i < 2; ++i) {
        for (int pl = 12; pl >= 1; --pl) {
            if (place[pl].size() > i) {
                if (place[pl][i] == white)
                    cout << "+ ";
                else
                    cout << "- ";
            } else {
                if (i == 0)
                    cout << "| ";
                else
                    cout << "  ";
            }

            if (pl == 7)
                cout << "| ";
        }
        cout << endl;
    }

    for (int pl = 12; pl >= 1; --pl) {
        if (place[pl].size() > 2)
            cout << place[pl].size()-2 << ' ';
        else
            cout << "  ";

        if (pl == 7)
            cout << "  ";
    }
    cout << '\n' << endl;

    for (int pl = 13; pl <= 24; pl++) {
        if (place[pl].size() > 2)
            cout << place[pl].size()-2 << ' ';
        else
            cout << "  ";

        if (pl == 18)
            cout << "  ";
    }
    cout << endl;

    for (int i = 1; i >= 0; --i) {
        for (int pl = 13; pl <= 24; ++pl) {
            if (place[pl].size() > i) {
                if (place[pl][i] == white)
                    cout << "+ ";
                else
                    cout << "- ";
            } else {
                if (i == 0)
                    cout << "| ";
                else
                    cout << "  ";
            }

            if (pl == 18)
                cout << "| ";
        }
        cout << endl;
    }
}



