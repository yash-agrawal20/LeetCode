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
        //Leaf Node
        if(!root->left && !root->right){
            
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        
        //Stuff
        s += to_string(root->val);
        s += "->";
        
        //Continue
        if(root->left)
            f(res, root->left, s);
        if(root->right)
            f(res, root->right, s);
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        //Using Recusion
        // vector<string> res;
        // string s;
        
        //f(res, root, s);
        
        // return res;
        
        //Iterative approach
        string s = "";
        vector<string> res;
        
        queue<TreeNode*> rtemp;
        queue<string> stemp;
        
        rtemp.push(root);
        stemp.push(to_string(root->val));
        
        while(!rtemp.empty()){
            
            TreeNode* temp = rtemp.front();
            rtemp.pop();
            
            string strtemp = stemp.front();
            stemp.pop();
            
            if(!temp->left && !temp->right){
                
                res.push_back(strtemp);
            }
            
            else{
                
                if(temp->left){
                    
                    rtemp.push(temp->left);
                    stemp.push(strtemp + "->" + to_string(temp->left->val));
                }
                
                if(temp->right){
                    
                    rtemp.push(temp->right);
                    stemp.push(strtemp + "->" + to_string(temp->right->val));
                }
            }
        
        }
        
        return res;
    }
};