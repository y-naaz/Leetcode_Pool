/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="" ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(node==NULL) s.append("#,");
            else {
                s.append(to_string(node->val)+",");
                q.push(node->left);
                q.push(node->right);
            }
        } 
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode*root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(ss,str,',');
            if(str=="#"){
                node->left = NULL;
            }
            else{
                TreeNode* nodeleft = new TreeNode(stoi(str));
                node->left = nodeleft;
                q.push(nodeleft);
            }
            getline(ss,str,',');
            if(str=="#"){
                node->right = NULL ;
            }
            else{
                TreeNode* noderight = new TreeNode(stoi(str));
                node->right = noderight;
                q.push(noderight);
            }
        }
        return root ; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));