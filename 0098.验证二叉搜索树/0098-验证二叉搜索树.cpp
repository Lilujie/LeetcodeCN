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
class Solution {
private:
    TreeNode *prev;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        //访问左子树
        if (!isValidBST(root->left))  return false;

        //访问当前节点：如果当前节点小于等于中序遍历的前一个节点直接返回false。
        if (prev != nullptr && prev->val >= root->val)  return false;
        prev = root;

        //访问右子树
        if (!isValidBST(root->right))  return false;

        return true;
    }
};