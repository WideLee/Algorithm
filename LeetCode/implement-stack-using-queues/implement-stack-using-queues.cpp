#include <iostream>
#include <queue>

using namespace std;
/*
class Stack {
public:

    queue<int> input;
    queue<int> output;

    // Push element x onto stack.
    void push(int x) {
        while(!output.empty()) {
            input.push(output.front());
            output.pop();
        }
        output.push(x);
        while(!input.empty()) {
            output.push(input.front());
            input.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        output.pop();
    }

    // Get the top element.
    int top() {
        return output.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return output.empty();
    }
}; */

// Other Solution
class Stack {
public:
    queue<int> output;

    // Push element x onto stack.
    void push(int x) {
        output.push(x);
        for(int i = 0; i < output.size() - 1; i++) {
            output.push(output.front());
            output.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        output.pop();
    }

    // Get the top element.
    int top() {
        return output.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return output.empty();
    }
};


int main() {

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    s.push(4);
    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    s.pop();
    cout << s.top() << endl;

    return 0;
}