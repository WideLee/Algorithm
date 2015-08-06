##Add Two Numbers 
2015-08-06 10:55:46 

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```

>Tags:  `Linked List` `Math`

###题目分析
模拟加法运算过程，求出两个使用链表表示的数的和。


###我的解题思路
因为那个链表已经是反过来的，链表头表示的是数的个位，因此可以依次遍历列表产生结果，如果大于10则需要在下一次的运算中处理进位。

> **注意：** Wrong Answer 了两次 T^T  在运算结束之后忘记处理最高位的进位1，还有当运算结果小于10的时候忘记重置进位，不应该啊…

~~~c++
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = NULL, *ptr = NULL;
    bool carry = false;
    while (l1 != NULL || l2 != NULL) {
        int cur;
        if (l1 == NULL) {
            cur = l2->val;
            l2 = l2->next;
        } else if(l2 == NULL) {
            cur = l1->val;
            l1 = l1->next;
        } else {
            cur = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry) {
            cur += 1;
        }
        if(cur > 9) {
            cur = cur % 10;
            carry = true;
        } else {
            carry = false;
        }
        ListNode *node = new ListNode(cur);
        if(ptr == NULL) {
            result = node;
            ptr = result;
        } else {
            ptr->next = node;
            ptr = node;
        }
    }
    if(carry) {
        ListNode *node = new ListNode(1);
        ptr->next = node;
        ptr = node;
    }

    if(ptr != NULL) {
        ptr->next = NULL;
    }
    return result;
}
~~~
###更好地解决方法
更简洁的代码 →_→

~~~c++
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
~~~
