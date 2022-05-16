// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         vector<vector<int>> ans;
        
//         if(n < 4) return ans;
        
//         sort(nums.begin(), nums.end());
        
//         for(int i = 0; i < nums.size() - 3; i++){
            
//             int target3 = target - nums[i];
            
//             for(int j = i+1; j < nums.size() - 2; j++){
                
//                 int target2 = target3 - nums[j];
                
//                 int front = j + 1;
//                 int back = n - 1;
                
//                 while(front < back){
                    
//                     int sum2 = nums[front] + nums[back];
                    
//                     if(sum2 < target) front++;
                    
//                     else if(sum2 > target) back--;
                    
//                     else{
                        
//                         vector<int> quad(4,0);
//                         quad[0] = nums[i];
//                         quad[1] = nums[j];
//                         quad[2] = nums[front];
//                         quad[3] = nums[back];
                        
//                         ans.push_back(quad);
                        
//                         //Duplicates of number 3
//                         while(front < back && quad[2] == nums[front]) front++;
                        
//                         //Duplicates of number 4
//                         while(front < back && quad[3] == nums[back]) back--;
//                     }
//                 }
//                 //Duplicates of number 2
//                 while(j < n-2 && nums[j+1] == nums[j]) j++;
//             }
            
//             //Duplicates of number 1
//             while(i < n-3 && nums[i+1] == nums[i]) i++;
//         }
        
//         return ans;
        
//     }
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > res;
        
        if (num.size() < 4)
            return res;
        
        sort(num.begin(),num.end());
        
        int i = 0, j;
        
        while (i < num.size() - 3)
        {
            j = i+1;
            
            while (j < num.size() - 2)
            {
                int target_2 = target - num[i] - num[j];
                
                int front = j + 1;
                int back = num.size() - 1;
                
                while(front < back) {
                    
                    int two_sum = num[front] + num[back];
                    
                    if (two_sum < target_2) front++;
                    
                    else if (two_sum > target_2) back--;
                    
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                        
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                        
                        // Processing the duplicates of number 4 
                        while (front < back && num[back] == quadruplet[3]) --back;
                    } } 
                
                // Processing the duplicates of number 2 
                while(j < num.size() - 2 && num[j + 1] == num[j++]);
            } 
            
            // Processing the duplicates of number 1 
            while (i < num.size() - 3 && num[i + 1] == num[i++]);
        }
        return res;
    } 
};