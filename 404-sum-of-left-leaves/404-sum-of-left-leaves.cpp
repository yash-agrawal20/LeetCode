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
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root->left && !root->right)
            return 0;
        
        queue<TreeNode*> q;
        int sum = 0;
        
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left){
                
                TreeNode* temp2 = temp->left;
                
                //leaf node
                if(!temp2->left && !temp2->right)
                    sum += temp2->val;
                
                else
                    q.push(temp2);
            }
            
            if(temp->right)
                q.push(temp->right);
        }
        
        return sum;
    }
};