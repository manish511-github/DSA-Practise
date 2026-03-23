class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        // 1 2 3 10 11
        // 1*2 + 2
        // 4 3 10 11
        // 10 10 11

        // 1 1 2 4 9
        // 3 2 4 9
        // 8 4 9
        // 20 9
        // 
        // int cnt=0;
        // sort(arr.begin(),arr.end());
        // if (arr[0]>=k){
        //     return 0;
        // }

        // for (int i=1;i<arr.size();i++){
        //     long long x = min(arr[i],arr[i-1]);
        //     long long y = max(arr[i],arr[i-1]);
        //     long long z = x*2+y;
        //     if (arr.size()==2){
        //         return z>=k;
        //     }
        //     if (z>=k && arr[i+1]>=k){
        //         break;
        //     }
        //     cnt++;            

        // }
        // return cnt;

        int cnt=0;
        // [31, 38, 50, 57, 69, 84, 86, 89, 91, 97]

        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(),arr.end());
        while(!pq.empty() && pq.top()<k){
            long long x =pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long z = min(x,y)*2+max(x,y);
            pq.push(z);
            cnt++;

        }
        return cnt;
        

    }
};