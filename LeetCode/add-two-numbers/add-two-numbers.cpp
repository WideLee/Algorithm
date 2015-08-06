#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
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

    void print(ListNode *headA) {
        while (headA != NULL) {
            printf("%d->", headA->val);
            headA = headA->next;
        }
        printf("\n");
    }
};

int main() {
    Solution sol;
    ListNode * l11 = new ListNode(5);
    ListNode * l12 = new ListNode(4);

    l11->next = NULL;
//    l12->next = NULL;

    ListNode * l21 = new ListNode(5);
//    ListNode * l22 = new ListNode(6);
//    ListNode * l23 = new ListNode(4);

    l21->next = NULL;
//    l22->next = l23;
//    l23->next = NULL;

    ListNode * res = sol.addTwoNumbers(l11, l21);
    sol.print(res);
    return 0;
}