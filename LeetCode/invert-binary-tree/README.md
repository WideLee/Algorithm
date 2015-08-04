##Invert Binary Tree
2015-08-04 08:27:13

Invert a binary tree.

```            
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```
to

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
> Tags: `Tree`

###题目分析
反转二叉树的所有节点，可以使用递归的方法解决

###我的解决方法

当根节点为`NULL`的时候为递归的停止条件，否则递归交换它的左右节点。

~~~c++
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
~~~

###另一种解法
非递归解法，使用栈来模拟递归的过程。

~~~c++
TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}
~~~
