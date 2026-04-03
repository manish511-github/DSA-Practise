class MedianFinder {
public:
    int size=0;

    MedianFinder() {
    
        
    }

    // -1       // -2

    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    
    void addNum(int num) {
        
            if (size%2==0){
                if (maxi.empty()){
                    maxi.push(num); 
                }
                else{
                    if (num<mini.top()){
                        maxi.push(num);
                    }
                    else{
                        int t= mini.top();
                        mini.pop();
                        maxi.push(t);
                        mini.push(num);
                    }

                    
                }
                
            }else{
                // if (mini.empty()){
                //     mini.push(num);
                // }
                // else{
                    if (!maxi.empty() && num<maxi.top()){
                        int t =maxi.top();
                        maxi.pop();
                        mini.push(t);
                        maxi.push(num);

                    }
                    else{
                        mini.push(num);
                    }

                // }
                
            }
            size++;
    }
    
    double findMedian() {
        if (size%2==0){
            return (mini.top()+maxi.top())/2.0;
        }
        else{
            return maxi.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */