//https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1727776/JavaC%2B%2B-Explanation-going-from-Brute-to-Optimal-Approach

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int maxArea = 0;
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = -1;
        right[n-1] = n;
        
        for(int i = 1; i < n; i++){
            int prev = i-1;
            while(prev >= 0 && heights[prev] >= heights[i])
                prev = left[prev];
            
            left[i] = prev;
        }
        
        for(int j = n-1; j >= 0; j--){
            int prev = j+1;
            while(prev < n && heights[prev] >= heights[j])
                prev = right[prev];
            
            right[j] = prev;
        }
        
        for(int i = 0; i < n; i++){
            
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        
        return maxArea;
    }
};