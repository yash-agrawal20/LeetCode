class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
        if(!s2.empty())
            s2.push(x);
        else
            s1.push(x);
    }
    
    int pop() {
        
        int x = -1;
        
        if(!s1.empty()){
            while(s1.size() > 0){
                
                s2.push(s1.top());
                s1.pop();
            }
            
            x = s2.top();
            s2.pop();
            
            while(s2.size() > 0){
                
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        else if(!s2.empty()){
            
            while(s2.size() > 0){
                
                s1.push(s2.top());
                s2.pop();
            }
            
            x = s1.top();
            s1.pop();
            
            while(s1.size() > 0){
                
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return x;        
    }
    
    int peek() {
        
        int x = -1;
        
        if(!s1.empty()){
            while(s1.size() > 0){
                
                s2.push(s1.top());
                s1.pop();
            }
            
            x = s2.top();
            
            while(s2.size() > 0){
                
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        else if(!s2.empty()){
            
            while(s2.size() > 0){
                
                s1.push(s2.top());
                s2.pop();
            }
            
            x = s1.top();
            
            while(s1.size() > 0){
                
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return x;  
        
    }
    
    bool empty() {
        
        if(!s1.empty() || !s2.empty())
            return false;
        
        return true;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */