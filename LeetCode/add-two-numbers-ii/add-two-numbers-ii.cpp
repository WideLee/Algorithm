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

//
// Created by Mingkuan Li on 2017/3/8.
//

#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 */


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
                now_node = new ListNode(long_list->val + short_list->val);
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

int main() {
    ListNode *l11 = new ListNode(7);
    ListNode *l12 = new ListNode(2);
    ListNode *l13 = new ListNode(4);
    ListNode *l14 = new ListNode(3);

    l11->next = l12;
    l12->next = l13;
    l13->next = l14;

    ListNode *l21 = new ListNode(2);
    ListNode *l22 = new ListNode(8);
    ListNode *l23 = new ListNode(4);
    ListNode *l24 = new ListNode(6);

    l21->next = l22;
    l22->next = l23;
    l23->next = l24;

    Solution solution;

    ListNode *result = solution.addTwoNumbers(l11, l21);

    return 0;
}