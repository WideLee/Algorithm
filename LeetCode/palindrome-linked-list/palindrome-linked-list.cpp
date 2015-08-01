#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
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

    void print(ListNode *headA) {
        while (headA != NULL) {
            printf("%d->", headA->val);
            headA = headA->next;
        }
        printf("\n");
    }
};

int main() {
    ListNode *head = NULL;

    Solution sol;
    sol.print(head);

    cout << sol.isPalindrome(head) << endl;
    return 0;
}