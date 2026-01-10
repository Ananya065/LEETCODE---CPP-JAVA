/**
 * Title: 865. Smallest Subtree with all the Deepest Nodes
 * Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=daily-question&envId=2026-01-09
 * Difficulty: Medium
 * Time Complexity: O(N) - We visit each node once
 * Space Complexity: O(H) - Stack space equal to the height of the tree
 */

class Solution {
  
    private class Result {
        int depth;
        TreeNode node;

        Result(int depth, TreeNode node) {
            this.depth = depth;
            this.node = node;
        }
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }

    private Result dfs(TreeNode node) {
        if (node == null) {
            return new Result(0, null);
        }

        Result left = dfs(node.left);
        Result right = dfs(node.right);

        
        if (left.depth > right.depth) {
            return new Result(left.depth + 1, left.node);
        } 
        
        else if (right.depth > left.depth) {
            return new Result(right.depth + 1, right.node);
        } 
       
        else {
            return new Result(left.depth + 1, node);
        }
    }
}

/*
problem statement:
Find the smallest subtree that contains all the deepest nodes of the original tree. 
If there's only one deepest node, that node is the answer. If there are multiple, 
we need their Lowest Common Ancestor (LCA).

how i approached this problem:
I used a post-order DFS (bottom-up). By creating a 'Result' helper class, 
each node can tell its parent two things: "How deep is my deepest leaf?" 
and "Which node is currently the best candidate for the LCA?". 
When a parent sees that its left and right children have the same max depth, 
it knows it's the new candidate for the smallest subtree.

SUMMARY:
- Difficulty: Medium
- Concept: DFS / Lowest Common Ancestor (LCA)
- Data Structure: Binary Tree & Custom Result Class
- Efficiency: O(N) time and O(H) space
*/
