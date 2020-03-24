#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

int NUM_PASSED = 0;
int NUM_TESTED = 0;

void test_true(bool expr, string desc);

int main() {
    Queue<int> one_to_five;
    test_true(one_to_five.is_empty(),"int queue is initially empty");
    test_true(one_to_five.enqueue(1),"int queue enqueue method works");
    one_to_five.enqueue(2);
    one_to_five.enqueue(3);
    one_to_five.enqueue(4);
    one_to_five.enqueue(5);
    test_true(one_to_five.get_size()==5,"int queue has correct size after enqueues");
    one_to_five.dequeue();
    test_true(one_to_five.get_size()==4,"int queue has correct size after dequeue");
    Queue<int> one_to_four;
    one_to_four = one_to_five;
    test_true(one_to_four.get_front()==one_to_five.get_front(),"copy of int queue has same front");
    test_true(one_to_four.get_size()==one_to_five.get_size(),"copy of int queue has same size");
    test_true(one_to_four.is_empty()==one_to_five.is_empty(),"copy of int queue has same emptiness");

    Queue<char> cob;
    cob.enqueue('c');
    cob.enqueue('o');
    cob.enqueue('b');
    test_true(cob.get_size()==3,"char queue has correct size after enqueues");
    test_true(cob.get_front()=='c',"char queue has correct front after enqueues");
    cob.dequeue();
    cob.dequeue();
    cob.dequeue();
    test_true(cob.is_empty(),"char queue is empty after dequeues");

    cout << NUM_PASSED << " cases passed out of " << NUM_TESTED << endl;
}

void test_true(bool expr, string desc) {
    NUM_TESTED++;
    if (!expr) {
        cout << "FAILED test: ";
    } else {
        cout << "Passed test: ";
        NUM_PASSED++;
    }
    cout << '"' << desc << '"' << endl;
}