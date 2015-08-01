#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = length(headA);
        int lengthB = length(headB);

        if(lengthA > lengthB) {
            int error = lengthA - lengthB;
            for(int i = 0; i < error; i++) {
                headA = headA->next;
            }
        } else {
            int error = lengthB - lengthA;
            for(int i = 0; i < error; i++) {
                headB = headB->next;
            }
        }
        while(headA != NULL && headB != NULL) {
            if(headA == headB) {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }

    int length(ListNode *headA) {
        int length = 0;
        while(headA != NULL) {
            length++;
            headA = headA->next;
        }

        return length;
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
    return 0;
}