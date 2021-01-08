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
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        vector<TreeNode*> treeNodeList;
        preOrderTranverse(root, treeNodeList);

        for(int i = 0; i < treeNodeList.size() - 1; i++) {
            treeNodeList[i]->left = nullptr;
            treeNodeList[i]->right = treeNodeList[i + 1];
        }
    }

    void preOrderTranverse(TreeNode* root, vector<TreeNode*> & treeNodeList) {
        if(root == nullptr) return;

        treeNodeList.push_back(root);

        preOrderTranverse(root->left, treeNodeList);
        preOrderTranverse(root->right, treeNodeList);
    }
};