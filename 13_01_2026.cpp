/**
 * Title: 144. Binary Tree Preorder Traversal
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
 * Difficulty: Easy
 * Time Complexity: O(N) - We visit every node exactly once
 * Space Complexity: O(H) - Stack space proportional to the height of the tree
 */


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();

           
            result.push_back(curr->val);
            if (curr->right) s.push(curr->right);
            
            if (curr->left) s.push(curr->left);
        }

        return result;
    }
};

/*
problem statement:
Return the preorder traversal (Root-Left-Right) of a binary tree's nodes.

how i approached this problem:
While recursion is the simplest way, I implemented the iterative version using 
a Stack to mimic the call stack. Since a stack is Last-In-First-Out (LIFO), 
I pushed the right child before the left child. This ensures the left child 
is at the top of the stack and gets processed immediately after the root.

SUMMARY:
- Difficulty: Easy
- Concept: Tree Traversal / Stack
- Data Structure: Binary Tree & Stack
- Efficiency: O(N) time and O(H) space
*/
