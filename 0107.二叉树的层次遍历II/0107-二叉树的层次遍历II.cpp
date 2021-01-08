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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {            
            int currentSize = q.size();
            result.push_back(vector<int> ());
            for (int i = 0; i < currentSize; i++) {                
                TreeNode* node = q.front();
                q.pop();

                if(node) result.back().push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};