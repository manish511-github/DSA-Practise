class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate=0;
        int cnt=0;
        for (int i=0;i<arr.size();i++){
            if (cnt==0){
                candidate=arr[i];
                // cnt++;
            }
            if (arr[i]==candidate){
                cnt++;
            }
            if (arr[i]!=candidate){
                cnt--;
            }
        }
        // for (int i=0;i<arr.size();i++){

        // }
        return candidate;
    }
};