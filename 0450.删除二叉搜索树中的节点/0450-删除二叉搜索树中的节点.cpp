/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /**
  * 有三种情况：
  * 1. 删除的为叶子节点，直接删除，将其父节点指向NULL
  * 2. 删除的节点有一个孩子， 删除该节点后，将它的孩子挂在它的父亲上
  * 3. 删除的节点有左右两个孩子，应该从其左子树中找最大的元素（或者从右子树中找最小的元素）替换它，并
  *    (递归地)删除那个最大(或者最小)的元素。
  */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        TreeNode* tmp;

        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right  = deleteNode(root->right, key);
        else if (root->left && root->right) {
            tmp = findMin(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        } else {
            tmp = root;

            if (!root->left)  root = root->right;
            else if (!root->right) root = root->left;
            delete tmp;
            tmp = nullptr;
        }

        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        if (!root) return nullptr;

        if (root->left) return findMin(root->left);
        else return root;
    }
};