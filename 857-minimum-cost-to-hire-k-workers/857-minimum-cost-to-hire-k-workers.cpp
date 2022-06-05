//https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/141768/Detailed-explanation-O(NlogN)

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<vector<double>> worker;
        for(int i = 0; i < quality.size(); i++){
            
            worker.push_back({(double)(wage[i])/quality[i], (double)quality[i]});
        }
        
        sort(worker.begin(), worker.end());
        double res = DBL_MAX;
        priority_queue<double> pq;
        
        double qsum = 0;
        
        for(auto w: worker){
            
            qsum += w[1];
            pq.push(w[1]);
            
            if(pq.size() > k){
                qsum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k){
                
                res = min(res, qsum*w[0]);
            }
        }
        
        return res;
        
    }
};