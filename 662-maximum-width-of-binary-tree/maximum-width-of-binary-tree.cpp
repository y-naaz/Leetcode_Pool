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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0 ; 
        int ans = 0 ; 
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int sizes = q.size();
            long long minim = q.front().second;
            int first ; 
            int last ; 
            for(int i = 0 ;  i < sizes ; i++){
                TreeNode* node = q.front().first;
                long long id = q.front().second-minim ; 
                q.pop();
                if(i==0) first = id;
                if(i==sizes-1) last = id;
                if(node->left) q.push({node->left,2*id+1});
                if(node->right) q.push({node->right,2*id+2});
            }
            ans = max(ans,last-first+1);
        }
    return ans ;
    }
};