## Add Two Numbers II

2017-03-08 11:56:48

You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Follow up:**
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

**Example:**

```
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```

> Tags: `Linked List` 



### 题目分析

和之前的Add Two Numbers类似，区别在于之前的链表是反向的而这里的链表是正向的，链表每一个节点的数代表整数中的每一位，求两个链表所代表的数之和

### 我的解题思路

考虑到不需要翻转链表，思路是先按照对应位直接相加，然后遍历数组考虑进位的问题

首先需要把链表的各位对齐，即先处理较长的链表同时记录当前剩余的长度，当两者长度一样的时候开始相加，结果存在一个新的链表中

然后处理进位问题，使用两个指针分别记录当前查询的节点和上一个查询的节点，如果当前节点大于10，那么进行进位操作。一直重复遍历链表直到没有出现进位。

***这样可能会出现一个问题，如果是99999+1的话需要遍历5次数组对时间消耗比较长***

```c++
class Solution {
public:
    int count(ListNode *l) {
        int count = 0;
        while (l != NULL) {
            count++;
            l = l->next;
        }
        return count;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int count1 = count(l1);
        int count2 = count(l2);

        ListNode *long_list = count1 > count2 ? l1 : l2;
        ListNode *short_list = count1 <= count2 ? l1 : l2;
        int long_count = count1 > count2 ? count1 : count2;
        int short_count = count1 <= count2 ? count1 : count2;

        ListNode *root_node = NULL, *next_node = NULL;

        while (long_list != NULL) {
            ListNode *now_node;
            if (long_count > short_count) {
                now_node = new ListNode(long_list->val);

                long_list = long_list->next;
                long_count--;
            } else {
                now_node = new ListNode(long_list->val 
                                        + short_list->val);
                long_list = long_list->next;
                short_list = short_list->next;
                long_count--;
                short_count--;
            }

            if (root_node == NULL) {
                root_node = now_node;
                next_node = root_node;
            } else {
                next_node->next = now_node;
                next_node = next_node->next;
            }
        }

        bool has_indent;
        do {
            has_indent = false;
            ListNode *cur = root_node;
            ListNode *pre = root_node;

            if (cur->val >= 10) {
                ListNode *new_root = new ListNode(1);
                new_root->next = root_node;
                root_node->val = root_node->val - 10;
                root_node = new_root;
                has_indent = true;
                cur = new_root->next;
                pre = new_root;
            } else {
                pre = cur;
                cur = cur->next;
            }

            while (cur != NULL) {
                if (cur->val >= 10) {
                    pre->val = pre->val + 1;
                    cur->val = cur->val - 10;
                    has_indent = true;
                }
                pre = cur;
                cur = cur->next;
            }
        } while (has_indent);

        return root_node;
    }
};
```



### 其他解决方法

使用栈存储链表后进行进一步处理，由于后进先出，相当于对链表进行了翻转

```java
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
  Stack<Integer> s1 = new Stack<Integer>();
  Stack<Integer> s2 = new Stack<Integer>();

  while(l1 != null) {
    s1.push(l1.val);
    l1 = l1.next;
  };
  while(l2 != null) {
    s2.push(l2.val);
    l2 = l2.next;
  }

  int sum = 0;
  ListNode list = new ListNode(0);
  while (!s1.empty() || !s2.empty()) {
    if (!s1.empty()) sum += s1.pop();
    if (!s2.empty()) sum += s2.pop();
    list.val = sum % 10;
    ListNode head = new ListNode(sum / 10);
    head.next = list;
    list = head;
    sum /= 10;
  }

  return list.val == 0 ? list.next : list;
}
```

