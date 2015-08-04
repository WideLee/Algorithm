##Reverse Linked List 
2015-08-04 10:18:25

Reverse a singly linked list.

**Hint:**

A linked list can be reversed either iteratively or recursively. Could you implement both?

>Tags: `Linked List`

###题目分析
反转一个链表

###我的解决方法
注意边界条件，如下是我实现的递归与非递归的解法。

~~~c++
ListNode *reverseList_iteratively(ListNode *head) {
    ListNode *preNode = NULL;
    ListNode *curNode = head;
    ListNode *postNode = NULL;
    
    while (curNode != NULL) {
        postNode = curNode->next;
        curNode->next = preNode;
        
        preNode = curNode;
        curNode = postNode;
    }
    head = preNode;
    
    return head;
}
    
ListNode *reverseList_recursively(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *second = head->next;
    head->next = NULL;
    ListNode *newHead = reverseList_recursively(second);
    second->next = head;
    return newHead;
}
~~~
