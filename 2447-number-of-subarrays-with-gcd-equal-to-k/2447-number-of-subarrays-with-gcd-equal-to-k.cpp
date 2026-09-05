class Solution {
public:
    int subarrayGCD(vector<int>& arr, int k) {
        // [9 3 1 2 6 3]
        //  gcd(a, b) = gcd(b, a % b)
        int ans=0;
        int n=arr.size();
        for (int i=0;i<arr.size();i++){
            int cgcd=0;
            for (int j=i;j<n;j++){
                cgcd = gcd(cgcd,arr[j]);
                if (cgcd ==k)
                ans++;
                if (cgcd<k)
                break;
            }
        }
        return ans;
        
    }
}; 