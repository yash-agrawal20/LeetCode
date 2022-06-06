class Solution {
public:
    //TLE
//     int subarraysDivByK(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         int count = 0;
        
//         for(int i = 0; i < n; i++){
            
//             int sum = 0;
//             for(int j =  i; j < n; j++){
                
//                 sum += nums[j];
                
//                 if(sum % k == 0) count++;
//             }
//         }
        
//         return count;
        int subarraysDivByK(vector<int>& A, int K) {
            
//             vector<int> count(K);
//             count[0] = 1;
//             int prefix = 0, res = 0;
//             for (int a : A) {
//                 //IMP
//                 prefix = (prefix + a % K + K) % K;
//                 res += count[prefix]++;
//             }
            
//             return res;
            
            unordered_map<int, int> mp;
            int n = A.size();
            int sum = 0;
            int res = 0;
            
            //Initialize
            mp[0] = 1;
            
            for(int i = 0; i < n; i++){
                
                sum += A[i];
                int rem = sum % K;
                
                if(rem < 0)
                    rem += K;
                
                res += mp[rem];
                mp[rem]++;
            }
            
            return res;
    }
        
};