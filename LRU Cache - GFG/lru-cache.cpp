// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way
class node{
    public:
    pair<int, int> d;
    node* prev;
    node* next;
    
    node(pair<int, int> n){
        
        d = n;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
    private:
    int s;
    node* head;
    node* tail;
    unordered_map<int, node*> mp;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        s = cap;
        head = new node({0,0});
        head->next = new node({0,0});
        head->next->prev = head;
        tail = head->next;
        
    }
    
    void insert(int ele, int key){
        
        node* ptr = head->next;
        node* p = new node({key, ele});
        p->prev = head;
        p->next = head->next;
        ptr->prev = p;
        head->next = p;
        s--;
        
        mp[key] = p;
    }
    
    void del(node* ptr){
        
        node* a = ptr->prev;
        node* b = ptr->next;
        a->next = b;
        b->prev = a;
        s++;
        
        mp[ptr->d.first] = NULL;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mp[key] == NULL){
            return -1;
        }
        int b = mp[key]->d.second;
        auto p = mp[key];
        del(p);
        insert(b, key);
        
        return b;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(mp[key]){
            del(mp[key]);
        }
        if(!s){
            del(tail->prev);
        }
        insert(value, key);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends