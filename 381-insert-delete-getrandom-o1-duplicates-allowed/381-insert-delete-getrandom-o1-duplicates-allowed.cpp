//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/235295/C%2B%2B-simple-unordered_set-and-clever-vector

class RandomizedCollection {
private:
    vector<int> values;
    unordered_map<int, unordered_set<int>> indices;
    
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        bool res = indices.find(val) == indices.end();
        indices[val].insert(values.size());
        values.push_back(val);
        
        return res;
        
    }
    
    bool remove(int val) {
        
        if(indices.find(val) != indices.end()){
            
            int i = *indices[val].begin();
            //auto i = indices[val].begin();
            if(indices[val].size() == 1)
                indices.erase(val);
            
            else
                indices[val].erase(indices[val].begin());
            
            if(i < values.size() - 1){
                
                values[i] = values.back();
                indices[values[i]].erase(values.size() - 1);
                indices[values[i]].insert(i);
            }
            
            values.pop_back();
            return true;
        }
        
        return false;
        
    }
    
    int getRandom() {
        
        return values[rand() % values.size()];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */