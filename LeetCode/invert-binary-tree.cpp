#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) {
            return root;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        left = invertTree(left);
        right = invertTree(right);

        root->right = left;
        root->left = right;

        return root;
    }

    void postorder(TreeNode* p, int indent=1)
    {
        if(p != NULL) {
            cout<< p->val << "\n ";
            if(p->left) postorder(p->left, indent+4);
            if(p->right) postorder(p->right, indent+4);
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
        }
    }
};

int main() {

    Solution sol;

    TreeNode * t1 = new TreeNode(1);
    TreeNode * t2 = new TreeNode(2);
    TreeNode * t3 = new TreeNode(3);
    TreeNode * t4 = new TreeNode(4);
    TreeNode * t6 = new TreeNode(6);
    TreeNode * t7 = new TreeNode(7);
    TreeNode * t9 = new TreeNode(9);

    t4->left = t2;
    t4->right = t7;
    t2->left = t1;
    t2->right = t3;
    t7->left = t6;
    t7->right = t9;

    sol.postorder(t4);

    TreeNode * tnew = sol.invertTree(t4);

    cout << endl;
    sol.postorder(tnew);
    return 0;
}