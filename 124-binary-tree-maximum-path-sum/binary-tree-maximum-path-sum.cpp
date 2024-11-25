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
    int maxPath(TreeNode* node, int &maxi){
        if(!node) return 0 ; 
        int leftsum = max(0,maxPath(node->left,maxi));
        int rightsum = max(0,maxPath(node->right,maxi));
        maxi =max(maxi,leftsum+rightsum+node->val);
        return node->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi ; 
    }
};