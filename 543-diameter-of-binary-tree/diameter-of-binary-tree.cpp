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
     int level(TreeNode* root){
    if(root==NULL) return 0;
    int leftlevel= level(root->left);
    int rightlevel=level(root->right);
    return 1+max(leftlevel,rightlevel);
}
    int diameterOfBinaryTree(TreeNode* root) {
             if(root==NULL) return 0 ;
             int l =   level(root->left);
         int r =   level(root->right);
        int leftdia=diameterOfBinaryTree( root->left) ;
     int rightdia=   diameterOfBinaryTree(root->right) ;
         
         return max({l+r,leftdia,rightdia});
    }
};