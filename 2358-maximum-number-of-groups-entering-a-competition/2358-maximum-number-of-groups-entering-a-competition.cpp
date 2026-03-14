class Solution {
public:
// int helper(){
//     int cnt=0;
//     int sum=0;
//     int lastsum=0;
//     int prevlen=0;
//     // 3 5 6 7 10 12
//     // 3  
//     for (int i=0;i<arr.size();i++){
//         sum+=arr[i]
//         len++;
//         if (sum>lastsum && len>prevlen){
//             lastsum=sum;
//             prevlen=len;
//             len=0;
//             sum=0;
//             cnt++;
//         }
        
//     }
    
// }
// 1  2,3  4 5 6   7 8
// 8 76 543  
    int maximumGroups(vector<int>& arr) {
        int n = arr.size();
        int k = 0;
        int need = 1;

        while (n >= need) {
            n -= need;
            need++;
            k++;
        }

        return k;

    }
};