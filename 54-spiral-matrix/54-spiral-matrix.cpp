//https://leetcode.com/problems/spiral-matrix/discuss/20573/A-concise-C%2B%2B-implementation-based-on-Directions

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         vector<int> res; 
//         vector<vector<int>> dir{{0,1}, {1,0}, {0,-1}, {-1,0}};
        
//         vector<int> nSteps{n, m-1};
        
//         int idir = 0; //index of direction
//         int ir = 0, ic = -1; //initial index
        
//         while(nSteps[idir % 2]){
            
//             for(int i = 0; i < nSteps[idir % 2]; i++){
                
//                 ir += dir[idir][0];
//                 ic += dir[idir][1];
//                 res.push_back(matrix[ir][ic]);
//             }
            
//             idir = (idir + 1) % 4;
//             nSteps[idir % 2]--;
//         }
        
//         return res;
        
    vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
    vector<int> res;
        
    int nr = matrix.size();   
    int nc = matrix[0].size();  
    
    vector<int> nSteps{nc, nr-1};
    
    int iDir = 0;   // index of direction.
    int ir = 0, ic = -1;    // initial position
        
    while (nSteps[iDir%2]) {
        
        for (int i = 0; i < nSteps[iDir%2]; ++i) {
            
            ir += dirs[iDir][0]; ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        
        nSteps[iDir%2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
        
    }
};