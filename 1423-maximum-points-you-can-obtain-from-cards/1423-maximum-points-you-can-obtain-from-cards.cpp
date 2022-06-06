//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization

//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/1202422/Short-and-Easy-Solutions-w-Explanation-or-Sliding-Window-and-2-Pointers-Approach

class Solution {
private:
    int f(vector<int>& cardPoints, int k, int s, int e){
        
        if(k == 0)
            return 0;
        
        return max((cardPoints[s] + f(cardPoints, k-1, s+1, e)), (cardPoints[e] + f(cardPoints, k-1, s, e-1)));
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        //Approach 1
        //Recursive Solution
        //Brute force
        //TLE
        // return f(cardPoints, k, 0, cardPoints.size() - 1);
        
        //Approach 2
//         int n = cardPoints.size();
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += cardPoints[i];
//         }
        
//         if(k == n)
//             return sum;
        
//         int window = 0;
//         int res = 0;
        
//         //Making a sum of first k-1 elements
//         for(int i = 0; i < n-k-1; i++){
//             window += cardPoints[i];
//         }
        
//         //Starting from k index and then moving till the end
//         for(int i = n-k-1; i < n; i++){
//             window += cardPoints[i];//Window now has k elements
//             res = max(res, sum-window);
//             window -= cardPoints[i - (n-k-1)]; //Removing the starting element
//         }
        
//         return res;
        
        
        //Approach 3
        //Inserting one vector after anothre
        
        int n = cardPoints.size();
        vector<int> temp = cardPoints;
        
        //Concateating the 2 vectors
        temp.insert(temp.end(), cardPoints.begin(), cardPoints.end());
        
        //Finding the maximum
        int sum = 0;
        for(int i = n-k; i < n-1; i++){
            sum += temp[i];
        }
        
        int count = 0;
        int maxSum = 0;
        for(int i = n-1; count <= k; i++,count++){
            
            sum += temp[i];
            maxSum = max(maxSum, sum);

            sum -= temp[i - k + 1];
        }
        
        return maxSum;
        
        
    }
};