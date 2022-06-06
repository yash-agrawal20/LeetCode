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
    void f(vector<string>& res, TreeNode* root, string s){
        
        //Base
        if(!root->left && !root->right){
            
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        
        s += to_string(root->val);
        s += "->";
        
        if(root->left)
            f(res, root->left, s);
        if(root->right)
            f(res, root->right, s);
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        //Using Recusion
        vector<string> res;
        string s;
        
        f(res, root, s);
        
        return res;
        
    }
};