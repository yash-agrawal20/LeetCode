class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        if(heights.size() == 1)
            return 0;
        
        int pos = 0;
        //Using min heap data structure
        priority_queue<int, vector<int>, greater<int>> pq;
        
        while(pos < heights.size() - 1){
            
            int x = heights[pos+1] - heights[pos];
            
            if(x > 0){
                
                pq.push(x);
                if(pq.size() > ladders){
                    
                    int y = pq.top();
                    pq.pop();
                    
                    bricks = bricks - y;
                }
                
                if(bricks < 0)
                    break;
            }
            
            if(x <= 0 || bricks >= 0)
                pos++;
        }
        
        return pos;
        
    }
};