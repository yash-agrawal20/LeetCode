class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r = 1000000000;
        
        while(l <= r){
            
            int mid = l + (r - l)/2;
            
            if(check_num_hours(piles, mid, h)) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;        
    }
    
    bool check_num_hours(vector<int> piles, int mid, int h){
        
        int hours = 0;
        
        for(int pile: piles){
            
            hours += pile/mid;
            
            if(pile % mid != 0) hours += 1;
        }
        
        return hours <= h;
    }
};