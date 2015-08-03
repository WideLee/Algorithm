##Implement Stack using Queues
2015-08-03 23:38:28

Implement the following operations of a stack using queues.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- empty() -- Return whether the stack is empty.


Notes:

- You must use only standard operations of a queue -- which means only `push to back`, `peek/pop from front`, `size`, and `is empty` operations are valid.
- Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
- You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

> Tags: ` Stack ` `Data Structure`

###题目分析
使用队列来实现栈的基本操作。

###我的解决方法
与使用栈实现队列类似，用两个队列，其中一个作为缓冲，另一个栈元素顺序反过来满足后进先出的特性，在push操作的时候把新的元素放在output队列的队列头。

~~~c++
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
};
~~~

###更好的解决方法

使用一个队列就可以实现，每次把元素插入到队列尾，然后把它前面的元素依次调到队列尾。

~~~c++
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
~~~
