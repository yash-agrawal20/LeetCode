class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        //Using Stack
        //Finding the next greater number
        stack<int> s;
        int n = t.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++){
            
            while(!s.empty() && t[s.top()] < t[i]){
                
                ans[s.top()] = i - s.top();
                s.pop();
            }
            
            s.push(i);
        }
        
        return ans;
        
    }
};