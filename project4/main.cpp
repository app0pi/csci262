// Project 4: 20 Questions by Kenny Lieu on December 6-8, 2018

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
    bool is_question;
};

node* read_game_node(fstream &file){
    string line;
    getline(file, line);
    node* bob = new node();
    if(line.substr(0,2)=="#Q") {
        bob->is_question = true;
        bob->data = line;
        bob->left = read_game_node(file);
        bob->right = read_game_node(file);
    }
    else{
        bob->is_question = false;
        bob->data = line;
        bob->left = nullptr;
        bob->right = nullptr;
    }
    return bob;
}

node* read_game_tree(){
    fstream file;
    file.open("animal.txt");
    return read_game_node(file);
}

void expand_game_tree(node* root){
    cout << "Enter a new animal in the form of a question," << endl;
    cout << "e.g., 'Is it a whale?':" << endl;
    string old_animal = root->data;
    string new_animal;
    getline(cin, new_animal);
    cout << "Now enter a question for which the answer is 'yes' for your new " << endl;
    cout << "animal, and which does not contradict your previous answers:" << endl;
    string new_question;
    getline(cin, new_question);
    root->right = new node();
    root->right->data = old_animal;
    root->right->left = nullptr;
    root->right->right = nullptr;
    root->right->is_question = false;
    cout << root->right->data << endl;
    root->left = new node();
    root->left->data = "#A " + new_animal;
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->left->is_question = false;
    cout << root->left->data << endl;
    root->data = "#Q " + new_question;
    root->is_question = true;
    cout << root->data << endl;
}

void play_game(node* root) {
    cout << root->data << " (y/n):" << endl;
    string response;
    getline(cin, response);
    if(response=="y" || response=="Y"){
        if(root->is_question)
            play_game(root->left);
        else{
            cout << "Yes, I guessed your animal!" << endl << endl;
        }
    }
    else if(response=="n" || response=="N") {
        if(root->is_question)
            play_game(root->right);
        else{
            cout << "BOO! I don't know!" << endl << endl;
            cout << "Would you like to expand the game tree? (y/n):" << endl << endl;
            string reply;
            while(true){
                getline(cin, reply);
                if(reply=="y" || reply=="Y"){
                    expand_game_tree(root);
                    break;
                }
                else if(reply=="n" || reply=="N") {
                    break;
                }
                else{
                    cout << "Please type in y or n." << endl;
                }
            }
        }
    }
    else{
        cout << "Please type in y or n." << endl;
        play_game(root);
    }
}

void write_game_node(node* root, ofstream &new_file){
    if(root->is_question) {
        new_file << root->data << endl;
        write_game_node(root->left, new_file);
        write_game_node(root->right, new_file);
    }
    else {
        new_file << root->data << endl;
    }
}

void save_game_tree(node* root){
    ofstream new_file("animal.txt");
    write_game_node(root, new_file);
    new_file.close();
}

void delete_game_tree(node* root){
    if(root==nullptr)
        return;
    delete_game_tree(root->left);
    delete_game_tree(root->right);
    delete(root);
}

int main() {
    node* root = read_game_tree();
    if (root == nullptr) return -1;

    while (true) {
        string tmp;
        int choice;

        cout << "Welcome to 20 questions!" << endl;
        cout << "  1) Play the game" << endl;
        cout << "  2) Save the game file" << endl;
        cout << "  3) Quit" << endl;
        cout << "Please make your selection: ";
        getline(cin, tmp);
        choice = atoi(tmp.c_str());

        switch (choice) {
            case 1:
                play_game(root);
                break;
            case 2:
                save_game_tree(root);
                break;
            case 3:
                break;
            default:
                cout << "Sorry, I don't understand." << endl << endl;
        }
        if (choice == 3) break;
    }

    delete_game_tree(root);

    return 0;
}

