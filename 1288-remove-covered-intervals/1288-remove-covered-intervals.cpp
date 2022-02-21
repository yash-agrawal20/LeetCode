class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int l = -1, r = -1;
        int count = 0;
        
        for(auto &v : intervals){
            
            if(v[0] > l && v[1] > r){
                count++;
                l = v[0];
            }
            r = max(r, v[1]);
        }
        
        return count;
        
    }
};