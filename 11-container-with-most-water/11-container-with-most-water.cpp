//https://leetcode.com/problems/container-with-most-water/discuss/1915172/JavaC%2B%2B-Easiest-Explanations

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right){
            
            int w = right - left;
            int h = min(height[left], height[right]);
            int a = w*h;
            
            maxWater = max(maxWater, a);
            
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else{
                left++;
                right--;
            }
        }
        
        return maxWater;
        
    }
};