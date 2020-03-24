/*
        image_editor.cpp
        
        Method implementations for the image_editor class.

        author: C. Painter-Wakefield

        last modified: 1/15/2018
*/

#include "image_editor.h"

using namespace std;

bool image_editor::load(istream& in) {
    // test magic string
    string magic;
    in >> magic;
    if (magic != "P3") return false;

    // TODO: get columns, rows, ensure valid
    in >> columns >> rows;
    // TODO: get and discard color depth
    in >> colordepth;
    // TODO: initialize your image storage data structure
    //see the image_editor.h file
    // TODO: get image data from input stream into your data structure
    data.clear();
    for(int i=0; i<rows; i++) {
        vector<vector<int>> row;
        for (int j = 0; j < columns; j++) {
            vector<int> column;
            for (int k = 0; k < 3; k++) {
                int value;
                in >> value;
                column.push_back(value);
            }
            row.push_back(column);
        }
        data.push_back(row);
    }
    return true;
}

void image_editor::save(ostream& out) {
    // TODO: output valid PPM file format data to the
    // output stream out
    out << "P3" << endl;
    out << columns << " " << rows << endl;
    out << colordepth << endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            for(int k=0; k<3; k++) {
                out << data[i][j][k];
            }
        }
    }
}

int image_editor::get_rows() {
    // TODO: return the correct # of rows
    return rows;
}

int image_editor::get_columns() {
    // TODO: return the correct # of columns
    return columns;
}

int image_editor::get_red(int row, int col) {
    // TODO: return the actual pixel red value
    return data[row][col][0];
}

int image_editor::get_green(int row, int col) {
    // TODO: return the actual pixel green value
    return data[row][col][1];
}

int image_editor::get_blue(int row, int col) {
    // TODO: return the actual pixel blue value
    return data[row][col][2];
}

void image_editor::apply_effect(int action_index) {
    enum action a = (enum action)action_index;

    // TODO: fill out this method
    if (a == GRAYSCALE) {
        // call a method that applies the grayscale
        // effect to the image in your data structure
        grayscale();
    } else if (a == NEGATE_RED) {
        // etc.
        negate_red();
    } else if (a == NEGATE_GREEN) {
        negate_green();
    } else if (a == NEGATE_BLUE) {
        negate_blue();
    } else if (a == FLATTEN_RED) {
        flatten_red();
    } else if (a == FLATTEN_GREEN) {
        flatten_green();
    } else if (a == FLATTEN_BLUE) {
        flatten_blue();
    } else if (a == EXTREME_CONTRAST) {
        extreme_contrast();
    } else if (a == FLIP_HORIZONTAL) {
        flip_horizontally();
    } else if (a == FLIP_VERTICAL) {
        flip_vertically();
    } else if (a == ENLARGE) {
        enlarge();
    } else if (a == REDUCE) {
        reduce();
    } else if (a == ROTATE) {
        rotate();
    } else if (a == BLUR_3X3) {
        blur_3x3();
    } else if (a == SHARPEN) {
        sharpen();
    } else if (a == DEEP_FRY) {
        deep_fry();
    } else if (a == BLACK_OUTLINE) {
        black_outline();
    }

}

// TODO: add effect methods below here
void image_editor::grayscale() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            int avg = (data[i][j][0]+data[i][j][1]+data[i][j][2])/3;
            for(int k=0; k<3; k++) {
                data[i][j][k] = avg;
            }
        }
    }
};

void image_editor::negate_red() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            data[i][j][0] = colordepth - data[i][j][0];
        }
    }
}

void image_editor::negate_green() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            data[i][j][1] = colordepth - data[i][j][1];
        }
    }
}

void image_editor::negate_blue() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            data[i][j][2] = colordepth - data[i][j][2];
        }
    }
}

void image_editor::flatten_red() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            data[i][j][0] = 0;
        }
    }
}

void image_editor::flatten_green() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            data[i][j][1] = 0;
        }
    }
}

void image_editor::flatten_blue() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            data[i][j][2] = 0;
        }
    }
}

void image_editor::extreme_contrast() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            for (int k=0; k<3; k++) {
                if (data[i][j][k]>colordepth/2)
                    data[i][j][k] = colordepth;
                else
                    data[i][j][k] = 0;
            }
        }
    }
}

void image_editor::flip_horizontally() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns/2; j++) {
            for(int k=0; k<3; k++)
                swap(data[i][j][k],data[i][columns-j-1][k]);
        }
    }
}

void image_editor::flip_vertically() {
    for(int i=0; i<rows/2; i++) {
        for(int j=0; j<columns; j++) {
            for(int k=0; k<3; k++)
                swap(data[i][j][k],data[rows-i-1][j][k]);
        }
    }
}

void image_editor::reduce() {
    vector<vector<vector<int>>> copydata = data;
    data.clear();
    rows /= 2;
    columns /= 2;
    for(int i=0; i<rows; i++) {
        vector<vector<int>> row;
        for (int j = 0; j < columns; j++) {
            vector<int> column;
            for (int k = 0; k < 3; k++) {
                int value;
                value = copydata[2*i][2*j][k];
                column.push_back(value);
            }
            row.push_back(column);
        }
        data.push_back(row);
    }
}

void image_editor::enlarge() {
    vector<vector<vector<int>>> copydata = data;
    data.clear();
    rows *= 2;
    columns *= 2;
    for(int i=0; i<rows; i++) {
        vector<vector<int>> row;
        for (int j = 0; j < columns; j++) {
            vector<int> column;
            for (int k = 0; k < 3; k++) {
                int value;
                value = copydata[i/2][j/2][k];
                column.push_back(value);
            }
            row.push_back(column);
        }
        data.push_back(row);
    }
}

void image_editor::rotate() {
    vector<vector<vector<int>>> copydata = data;
    data.clear();
    swap(rows, columns);
    for(int i=0; i<rows; i++) {
        vector<vector<int>> row;
        for (int j = 0; j < columns; j++) {
            vector<int> column;
            for (int k = 0; k < 3; k++) {
                int value;
                value = copydata[j][i][k];
                column.push_back(value);
            }
            row.push_back(column);
        }
        data.push_back(row);
    }
}

void image_editor::blur_3x3() {
    int arr[3][3] = {{1,2,1},{2,4,2},{1,2,1}};

    for(int i=1; i<rows-1; i++) {
        for(int j=1; j<columns-1; j++) {
            for(int k=0; k<3; k++) {
                int accumulator = 0;
                for(int l=0; l<3; l++) {
                    for(int m=0; m<3; m++) {
                        accumulator += arr[l][m]*data[i+l-1][j+m-1][k]/16;
                    }
                }
                data[i][j][k] = accumulator;
            }
        }
    }
}

void image_editor::sharpen() {
    int arr[3][3] = {{0,-1,0},{-1,5,-1},{0,-1,0}};

    vector<vector<vector<int>>> copydata = data;
    for(int i=1; i<rows-1; i++) {
        for(int j=1; j<columns-1; j++) {
            for(int k=0; k<3; k++) {
                int accumulator = 0;
                for(int l=0; l<3; l++) {
                    for(int m=0; m<3; m++) {
                        accumulator += arr[l][m]*copydata[i+l-1][j+m-1][k];
                    }
                }
                data[i][j][k] = min(accumulator,255);
            }
        }
    }
}

void image_editor::deep_fry() {
    int arr[3][3] = {{0,-1,0},{-1,5,-1},{0,-1,0}};

    for(int i=1; i<rows-1; i++) {
        for(int j=1; j<columns-1; j++) {
            for(int k=0; k<3; k++) {
                int accumulator = 0;
                for(int l=0; l<3; l++) {
                    for(int m=0; m<3; m++) {
                        accumulator += arr[l][m]*data[i+l-1][j+m-1][k];
                    }
                }
                data[i][j][k] = min(accumulator,255);
            }
        }
    }
}

void image_editor::black_outline() {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            if(i==0 || j==0 || i==rows || i==columns)
            for(int k=0; k<3; k++) {
                data[i][j][k] = 0;
            }
        }
    }
}