/* Problem Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/ */

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
    
    public void inOrder (TreeNode root, ArrayList<Integer> arr){
        if (root == null)
            return;
        
        inOrder(root.left, arr);
        arr.add(root.val);
        inOrder(root.right, arr);
    }
    
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> arr= new ArrayList<>();
        inOrder (root, arr);
        return arr.get(k-1);
    }
}
