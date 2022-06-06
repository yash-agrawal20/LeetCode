//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization

//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/1202422/Short-and-Easy-Solutions-w-Explanation-or-Sliding-Window-and-2-Pointers-Approach

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += cardPoints[i];
        }
        
        if(k == n)
            return sum;
        
        int window = 0;
        int res = 0;
        
        //Making a sum of first k-1 elements
        for(int i = 0; i < n-k-1; i++){
            window += cardPoints[i];
        }
        
        //Starting from k index and then moving till the end
        for(int i = n-k-1; i < n; i++){
            window += cardPoints[i];//Window now has k elements
            res = max(res, sum-window);
            window -= cardPoints[i - (n-k-1)]; //Removing the starting element
        }
        
        return res;
        
        
    }
};