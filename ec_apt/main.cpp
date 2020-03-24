#include <vector>
#include <string>
#include <iostream>
using namespace std;

class node {
public:
    int x;
    int y;
    node(int h, int v){
        x = h;
        y = v;
    }
};

int step(node* root, int horizontal, int vertical, vector<string> enc){
    if(enc[root->y].at(root->x)=='C'){
        return 1;
    }
    else if(horizontal!=0 && vertical!=0 && root->x+horizontal>=0 && root->x+horizontal<=enc[0].length()-1
            && root->y+vertical>=0 && root->y+vertical<=enc.size()-1
            && enc[root->y+vertical].at(root->x)!='X'
            && enc[root->y].at(root->x+horizontal)!='X'){
        node* new_horizontal_node = new node(root->x+horizontal, root->y);
        node* new_vertical_node = new node(root->x,root->y+vertical);
        return step(new_horizontal_node, horizontal, vertical, enc)
               +step(new_vertical_node, horizontal, vertical, enc);
    }
    else if(horizontal!=0 && root->x+horizontal>=0 && root->x+horizontal<=enc[0].length()-1
            && enc[root->y].at(root->x+horizontal)!='X') {
        node* new_horizontal_node = new node(root->x+horizontal, root->y);
        return step(new_horizontal_node, horizontal, vertical, enc);
    }
    else if(vertical!=0 && root->y+vertical>=0 && root->y+vertical<=enc.size()-1
            && enc[root->y+vertical].at(root->x)!='X'){
        node* new_vertical_node = new node(root->x,root->y+vertical);
        return step(new_vertical_node, horizontal, vertical, enc);
    }
    else
        return 0;
}

int num_routes(vector<string> enc) {
    int Rx, Ry;
    for(int i=0; i<enc.size(); i++){
        if(enc[i].find("R")!=string::npos){
            Ry=i;
            Rx=enc[i].find("R");
        }
    }
    int Cx, Cy;
    for(int i=0; i<enc.size(); i++){
        if(enc[i].find("C")!=string::npos){
            Cy=i;
            Cx=enc[i].find("C");
        }
    }
    int horizontal;
    if(Cx-Rx>0) horizontal = 1;
    if(Cx-Rx==0) horizontal = 0;
    if(Cx-Rx<0) horizontal = -1;
    int vertical;
    if(Cy-Ry>0) vertical = 1;
    if(Cy-Ry==0) vertical = 0;
    if(Cy-Ry<0) vertical = -1;

    node* root = new node(Rx,Ry);
    int paths = step(root, horizontal, vertical, enc);

    return paths;
}

int main() {
    vector<string> enc = {
            ".XX...",
            "XX....",
            "X..RX.",
            "...X..",
            ".XXC..",
            "...X.."};
    cout << num_routes(enc) << endl;
    return 0;
}