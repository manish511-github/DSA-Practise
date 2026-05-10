class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& arr) {
    int n= arr.size();
    int m=arr[0].size();
    vector<long long > row(n,0);
    vector<long long > col(m,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            row[i]+=arr[i][j];
            col[j]+=arr[i][j];
        }
    }
    long long  rowSum= accumulate(row.begin(), row.end(), 0LL);
    long long  colSum= accumulate(col.begin(), col.end(), 0LL);
    long long pre=0;
    for (int i=0;i<n;i++){
        pre+=row[i];
        rowSum-=row[i];
        if (pre==rowSum){
            return true;
        }
    }
    
    pre=0;
    for (int i=0;i<m;i++){
        pre+=col[i];
        colSum-=col[i];
        if (pre==colSum){
            return true;
        }
    }
    return false;

 
    }
};