class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& arr, int k) {
        // [1,0][1,4],[1,8] [2,1] [3,5] [4,6]
        //  1,2 [3,4] 
        // [0,0] [1,1] [2,2] [3,3] [4,4] [5,5] [6,6]
        // 0 1 2 3 4 5 6 
        sort(arr.begin(), arr.end());
        int start = arr[0][0];
        int count =1;
        for (int i=1;i<arr.size();i++){
            if (arr[i][0]-start >k){
                count++;
                start =arr[i][0];
            }
        }
        return count;
        // 
    }
};