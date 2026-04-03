class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int t;
    KthLargest(int k, vector<int>& arr) {
    t=k;
    for (int i=0;i<arr.size();i++){
        if (pq.size()<k){
            pq.push(arr[i]);
        }
        else {
            if (arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
            
        }
    }    
    }
    
    int add(int val) {
        if (pq.empty()){
            pq.push(val);
            return pq.top();
        }
        if (pq.size()<t){
            pq.push(val);    
        }
        else if  (val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */