class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int> v;
        int i=0;
        int j=n-1;
        int p=0;
        int l=m-1;
        while(i<=j && p<=l){
            for (int k=p;k<=l;k++){
                v.push_back(arr[i][k]);
            }
            i++;
            if (i>j){
                break;
            }
            for (int k=i;k<=j;k++){
                v.push_back(arr[k][l]);
            }
            l--;
            if (p>l){
                break;
            }
            for (int k=l;k>=p;k--){
                v.push_back(arr[j][k]);
            }
            j--;
            for (int k=j;k>=i;k--){
                v.push_back(arr[k][p]);
            }
            p++;
        }
        return v;
        
    }
};