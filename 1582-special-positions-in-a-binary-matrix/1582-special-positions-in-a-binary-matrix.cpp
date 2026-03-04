class Solution {
public:
    int numSpecial(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        for (int i=0;i<arr.size();i++){
            for (int j=0;j<arr[0].size();j++){
                if (arr[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }

        }
        int count =0;
        for (int i=0;i<arr.size();i++){
            for (int j=0;j<arr[0].size();j++){
                if (arr[i][j]==1){
                    if (row[i]==1 && col[j]==1){
                        count++;
                    }
                }
            }

        }
        return count;

    }
};