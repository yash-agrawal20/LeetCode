class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         deque<int> dq;
//         vector<int> res;
        
//         for(int i = 0; i < n; i++){
            
//             if(dq.size() && dq.front() == (i - k))
//                 dq.pop_front();
            
//             while(dq.size() && nums[dq.back()] < nums[i])
//                 dq.pop_back();
            
//             dq.push_back(i);
            
//             if(i - k + 1 >= 0)
//                 res.push_back(nums[dq.front()]);
//         }
        
//         return res;
        
        //Arranging the elements in descending order
        //Element and index
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        int low = 0;
        int high = k-1;
        
        for(int i = 0; i <= high; i++){
            pq.push({nums[i], i});
        }
        
        //Highest element among the first k elements
        res.push_back(pq.top().first);
        high++;
        
        while(high < nums.size()){
            
            //Increasing the lowwer boundary and adding the new element
            low++;
            pq.push({nums[high], high});
            
            while(pq.size() && pq.top().second < low)
                pq.pop();
            
            res.push_back(pq.top().first);
            
            high++;
        }
        
        return res;
    }
};