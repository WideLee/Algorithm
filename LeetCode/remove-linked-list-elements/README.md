##Remove Linked List Elements
2015-08-04 10:05:38

Remove all elements from a linked list of integers that have value val.

Example:

```
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
```

>Tags: `Linked List`

###题目分析
删除链表中等于某个值的所有节点

###我的解决方法
遍历链表，把等于`val`的节点删掉，它前一个节点的`next`指针直接指向下一个节点，注意边界条件。

**在我的解决方法中没有delete指针！！！！会出现内存泄露！！**


~~~c++
ListNode *removeElements(ListNode *head, int val) {
    ListNode *preNode;
    ListNode *curNode;

    while (head != NULL && head->val == val) {
        head = head->next;
    }

    if (head == NULL) {
        return head;
    }

    preNode = head;
    curNode = head->next;

    while (curNode != NULL) {
        if (curNode->val == val) {
            preNode->next = curNode->next;
            curNode = preNode->next;
        } else {
            preNode = curNode;
            curNode = curNode->next;
        }
    }

    return head;
}
~~~

###更好的解决方法
添加一个虚拟的头节点，可以不处理链表头就是要删除的元素的情况。

**他也没有delete指针！**

~~~c++
ListNode* removeElements(ListNode* head, int val) {
    ListNode *pseudo_head = new ListNode(0);
    pseudo_head->next = head;
    ListNode *cur = pseudo_head;
    while(cur){
        if(cur->next && cur->next->val == val)   
            cur->next = cur->next->next;
        else    
            cur = cur->next;
    }
    return pseudo_head->next;
}
~~~

可以使用递归的方法，简洁明了

~~~java
public ListNode removeElements(ListNode head, int val) {
        if (head == null) return null;
        head.next = removeElements(head.next, val);
        return head.val == val ? head.next : head;
}
~~~
