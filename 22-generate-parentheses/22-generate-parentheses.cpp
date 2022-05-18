class Solution {
private:
    void addingPar(vector<string>& res, string str, int left, int right){
        
        //Base Case
        if(left == 0 && right == 0){
            res.push_back(str);
            return;
        }
        //Trust
        if(left > 0)
            addingPar(res, str + '(', left-1, right+1);
        if(right > 0)
            addingPar(res, str + ')', left, right-1);
    }
    
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        addingPar(res, "", n, 0);//IMP
        return res;
        
    }
};