#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
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
};

int main() {
    Solution sol;
    
    return 0;
}