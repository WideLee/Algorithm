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

/*
 * Use a pseudo ListHead;
 * class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pseudo_head = new ListNode(0);
        pseudo_head->next = head;
        ListNode *cur = pseudo_head;
        while(cur){
            if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
            else    cur = cur->next;
        }
        return pseudo_head->next;
    }
};
 */

class Solution {
public:
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

    void print(ListNode *head) {
        while (head != NULL) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    sol.print(n1);
    n1 = sol.removeElements(n1, 1);
    sol.print(n1);
    return 0;
}