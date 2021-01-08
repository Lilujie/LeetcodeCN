/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        deque<TreeNode*> q;
        if(root) {
            q.push_back(root);
            TreeNode* tmp;
            bool flag = false;
            while(!q.empty()) {
                int currentSize = q.size();
                ret.push_back(vector<int> ());
                for (int i = 0; i < currentSize; i++) {
                    if (flag == false) {
                        tmp = q.front();
                        q.pop_front();
                        if (tmp->left) q.push_back(tmp->left);
                        if (tmp->right) q.push_back(tmp->right);
                    }
                    else {
                        tmp = q.back();
                        q.pop_back(); 
                        if (tmp->right) q.push_front(tmp->right);
                        if (tmp->left) q.push_front(tmp->left);
                    }
                    if (tmp) ret.back().push_back(tmp->val);
                }
                flag = !flag; 
            }     
        }
        return ret;
    }
};