##Implement Queue using Stacks
2015-08-03 22:17:58

Implement the following operations of a queue using stacks.

- push(x) -- Push element x to the back of queue.
- pop() -- Removes the element from in front of queue.
- peek() -- Get the front element.
- empty() -- Return whether the queue is empty.

Notes:

- You must use only standard operations of a stack -- which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
- Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
- You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

>Tags: `Stack` `Data Structure`

###题目分析
使用栈来实现队列的基本操作。

###我的解决方法
使用两个栈，其中si作为真正存数据的容器，里边的顺序已经排好了（栈顶的元素是最先进栈的元素），当有新的数据插入时，使用so作为缓冲，把新的数据放到si的最低端实现后进后出的特性。

~~~c++
class Queue {
public:
    stack<int> si;
    stack<int> so;

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
~~~

###更好地解决方法
Using input stack to store all input element. And move to output stack when peek or pop an element from queue.

这样的方法好处是再需要访问队列头元素的时候才批量调换元素位置，当压栈的操作比较频繁地时候，该方法能明显节省时间。
 
~~~c++
class Queue {
public:
	stack<int> input, output;
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
~~~
 

