//
// Created by kenny on 10/24/2018.
//

#ifndef CODE_POINT_H
#define CODE_POINT_H

#endif //CODE_POINT_H

#include <iostream>
#include <vector>

using namespace std;

class point {
public:
    point(int row, int column);
    int get_row();
    int get_column();
private:
    int _row, _column;
};