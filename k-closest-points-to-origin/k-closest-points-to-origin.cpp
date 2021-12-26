class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //key, value pair
        multimap <int, vector<int>> m;
        vector<vector<int>> res;
        
        for(auto i:points){
            
            int x = i[0], y = i[1];
            int dis = x*x + y*y;
            
            m.insert({dis, i});
        }
        
        for(auto it:m){
            
            if(k--){
                res.push_back(it.second);
            }
            
            else{
                return res;
            }
        }
        
        return res;
        
    }
};