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
  
    pair<int, TreeNode*> helper(TreeNode* root) {
        if (!root) return {0, nullptr};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        int left_depth = left.first;
        int right_depth = right.first;
        
        if (left_depth == right_depth) {
    
            return {left_depth + 1, root};
        } else if (left_depth > right_depth) {
     
            return {left_depth + 1, left.second};
        } else {
    
            return {right_depth + 1, right.second};
        }
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;
    }
};