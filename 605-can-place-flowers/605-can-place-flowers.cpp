class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0) return true;
        
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        int i = 1;
        int count = 0;
        
        while(i <= (flowerbed.size()-2) && count < n){
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                count++;
                i+=2;
            }
            
            else if(flowerbed[i] == 1){
                i += 2;
            }
            
            else{
                i += 1;
            }
        }
        
        if(count == n) return true;
        
        else return false;        
        
    }
};