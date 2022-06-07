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
class BSTIterator {
private:
    stack<TreeNode*> st;
    void find_left(TreeNode* root){
        
        TreeNode* n = root;
        while(n != NULL){
            
            st.push(n);
            n = n->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        
        find_left(root);
    }
    
    int next() {
        
        TreeNode* r = st.top();
        st.pop();
        
        if(r->right != NULL)
            find_left(r->right);
        
        return r->val;
    }
    
    bool hasNext() {
        
        if(!st.empty())
            return true;
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */