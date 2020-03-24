// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
using namespace std;

int main () {
    int myints[] = { 10, 20, 30, 40 };

    vector<int> myvector (myints,myints+4);vector<int>::iterator it;

    it = find (myvector.begin(), myvector.end(), 50);
    if (it != myvector.end())
        cout << "Element found in myvector: " << *it << '\n';
    else
        cout << "Element not found in myvector\n";

    return 0;
}