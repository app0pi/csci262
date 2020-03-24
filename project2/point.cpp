//
// Created by kenny on 10/24/2018.
//

#include "point.h"

point::point(int row, int column) {
    _row = row;
    _column = column;
}

int point::get_row() {
    return _row;
}

int point::get_column() {
    return _column;
}
