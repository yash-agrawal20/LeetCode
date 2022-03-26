class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1];
        int i = 1;
        
        while(i < intervals.size()){
            
            if(end >= intervals[i][0]){
                
                if(end < intervals[i][1]){
                    end = intervals[i][1];
                }
            }
            
            else if(end < intervals[i][0]){
                
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            
            if(i == intervals.size() - 1){
                res.push_back({start, end});
            }
            
            i++;
        }
        
        return res;
        
    }
};