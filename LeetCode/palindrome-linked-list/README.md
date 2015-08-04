##Palindrome Linked List
2015-08-04 09:07:49


Given a singly linked list, determine if it is a palindrome.

**Follow up:**
Could you do it in O(n) time and O(1) space?

>Tags：`Linked List` `Two Pointers`

###题目分析
判断一个链表是否为回文的。

###我的解决方法

使用两个指针，指针A每次往后移动一格，指针B每次往后移动两格，当指针B移动到链表末尾的时候，指针A所在的位置即为链表的中间节点。然后反转链表的后部分，从后部分的表头（即原链表的末端节点）开始往前比对判断链表是否回文。

这种方法满足条件使用O(n)的时间和O(1)的空间。

> **问题：经过处理之后，改变了输入的链表**

另一种方法是遍历链表把链表转换成数组，这样就是O(n)的空间。

~~~c++
bool isPalindrome(ListNode* head) {
    ListNode * end = head;
    ListNode * mid = head;

    while (true) {
        if(end == NULL) {
            return true;
        }

        if(end->next == NULL) {
            break;
        }
        end = end->next;

        if(end->next == NULL) {
            break;
        }
        end = end->next;
        mid = mid->next;
    }

    ListNode * next = mid->next;
    mid->next = NULL;
    reverse(next);

    while(head != NULL && end != NULL) {
        if(head->val != end->val) {
            return false;
        }
        head = head->next;
        end = end->next;
    }

    return true;
}

ListNode *reverse(ListNode *head) {
    ListNode * preNode = NULL;
    ListNode * curNode = head;
    ListNode * postNode = NULL;

    while (curNode != NULL) {
        postNode = curNode->next;
        curNode->next = preNode;

        preNode = curNode;
        curNode = postNode;
    }
    head = preNode;

    return head;
}

~~~
