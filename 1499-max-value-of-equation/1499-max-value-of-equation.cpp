//https://leetcode.com/problems/max-value-of-equation/discuss/713354/C%2B%2B-or-Deque-or-O(n)-or-Thorough-explanation-with-extensive-comments-or

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
//         int n = points.size();
//         int maxVal = INT_MIN;
        
//         //TC: O(n^2)
//         for(int i = 0; i < (n-1); i++){
//             for(int j = i+1; j < n; j++){
                
//                 int x = abs(points[i][0] - points[j][0]);
                
//                 if(x <= k){
                    
//                     maxVal = max(maxVal, points[i][1] + points[j][1] + x);
//                 }
//             }
//         }
        
//         return maxVal;
        
        //Using Deque (Double Sided Queue)
        int n = points.size();
        int res = INT_MIN;
        deque<int> d;
        
        for(int i = 0; i < n; i++){
            
            while(d.size() && (points[i][0] - points[d.front()][0] > k))
                d.pop_front();
            
            if(d.size())
                res = max(res, points[i][1] + points[i][0] - (points[d.front()][0] - points[d.front()][1]));
            
            while(d.size() && (points[i][0] - points[i][1]) <= (points[d.back()][0] - points[d.back()][1]))
                d.pop_back();
            
            d.push_back(i);
        }
        
        return res;
        
    }
};