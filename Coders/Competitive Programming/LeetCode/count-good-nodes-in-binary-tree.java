/* Problem link: https://leetcode.com/problems/count-good-nodes-in-binary-tree */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int goodNodesHelper(TreeNode root, int previous) {
        if (root == null) 
            return 0;
        
        if (root.val >= previous) 
            return 1 + goodNodesHelper(root.left, Math.max(root.val, previous)) + goodNodesHelper(root.right, Math.max(root.val, previous));
        else
            return goodNodesHelper(root.left, Math.max(root.val, previous)) + goodNodesHelper(root.right, Math.max(root.val, previous));
    }
    
    public int goodNodes(TreeNode root) {
        return goodNodesHelper(root, Integer.MIN_VALUE);
    }
}
