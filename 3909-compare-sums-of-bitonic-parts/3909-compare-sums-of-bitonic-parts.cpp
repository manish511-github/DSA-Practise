class Solution {
public:
    int compareBitonicSums(vector<int>& arr) {
        auto max_it = max_element(arr.begin(),arr.end());
        long long asum=accumulate(arr.begin(),next(max_it),0LL);
        long long dsum=accumulate(max_it,arr.end(),0LL);
        if (asum>dsum){
            return 0;
        }
        else if (dsum>asum){
            return 1;
        }
        return -1;

    }
};