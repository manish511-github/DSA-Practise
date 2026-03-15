class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        if (n<1000){
            return 0;
        }
        
        // 10068
        // 10000
        // len =5
        // 1000
        // 69 + 
        // while(n>=1000){
        //     string str = to_string(n);
        //     // 10000
        //     // len = 5
        //     int len = str.length(); 
        //     int noofcommans = len/3;
        //     int digits = pow(10, len-1);
        //     int nos = n-digits+1;
        //     cnt+= (nos*noofcommans);
        //     n=n/10;            
        // }
        return n-1000+1;
        

        
    }
};