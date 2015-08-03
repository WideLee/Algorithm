##Intersection of Two Linked Lists 
2015-08-03 23:54:29

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
```
begin to intersect at node c1.


Notes:

- If the two linked lists have no intersection at all, return null.
- The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
- Your code should preferably run in O(n) time and use only O(1) memory.

> Tags:  `Linked List`

###题目分析
找到两个链表相交的地方，相交不仅仅是元素的值一样，指针的位置也一样，返回相交位置的指针。

###解决方法
> 想了好久，想到反转链表从末端开始找起相同的项，但后来想到反转会影响另外一个链表所以不可行

其实很简单，先求两个链表的长度，然后比较长的那个先让头指针往后移一段距离使得两个链表尾端对齐，然后开始同时往后移来寻找一样的节点，如果到链表尾还没找到，那就没有相交。

~~~c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = length(headA);
    int lengthB = length(headB);

    if(lengthA > lengthB) {
        int error = lengthA - lengthB;
        for(int i = 0; i < error; i++) {
            headA = headA->next;
        }
    } else {
        int error = lengthB - lengthA;
        for(int i = 0; i < error; i++) {
            headB = headB->next;
        }
    }
    while(headA != NULL && headB != NULL) {
        if(headA == headB) {
            return headA;
        }

        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

int length(ListNode *headA) {
    int length = 0;
    while(headA != NULL) {
        length++;
        headA = headA->next;
    }

    return length;
}

~~~

###官方提供的解决方法
> 感觉真的很巧妙，两个指针分别指向A链表与B链表的头，然后同时往后移，当一个指针移到链表尾的时候，就重定位到另一个链表的头，一轮下去之后，保证A指针到达了B链表的尾，B指针到达A链表的头，如果中间没有相同的节点，那就没有相交。

There are many solutions to this problem:

- Brute-force solution (O(mn) running time, O(1) memory):
    - For each node ai in list A, traverse the entire list B and check if any node in list B coincides with ai.

- Hashset solution (O(n+m) running time, O(n) or O(m) memory):
    - Traverse list A and store the address / reference to each node in a hash set. Then check every node b_i in list B: if b_i appears in the hash set, then b_i is the intersection node.
- Two pointer solution (O(n+m) running time, O(1) memory):
    - Maintain two pointers pA and pB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
    - When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pB reaches the end of a list, redirect it the head of A.
    - If at any point pA meets pB, then pA/pB is the intersection node.
    - To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less than pA does. By redirecting pB to head A, and pA to head B, we now ask pB to travel exactly 2 more nodes than pA would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
    - If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.

Analysis written by @stellari.
