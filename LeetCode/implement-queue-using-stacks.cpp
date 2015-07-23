#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    stack<int> si;
    stack<int> so;

    Queue() {

    }

    // Push element x to the back of queue.
    void push(int x) {
        while(!si.empty()) {
            so.push(si.top());
            si.pop();
        }
        si.push(x);
        while(!so.empty()) {
            si.push(so.top());
            so.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!si.empty()) {
            si.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!si.empty()) {
            return si.top();
        }
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return si.empty();
    }
};

/* More better solution
 Using input stack to store all input element. 
 And move to output stack when peek or pop an element from queue.
 
 class Queue {
 stack<int> input, output;
 public:
 
 void push(int x) {
    input.push(x);
 }
 
 void pop(void) {
    peek();
    output.pop();
 }
 
 int peek(void) {
    if (output.empty())
        while (input.size())
            output.push(input.top()), input.pop();
    return output.top();
 }
 
 bool empty(void) {
    return input.empty() && output.empty();
 }
 };
 
 */



int main() {

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;

    return 0;
}