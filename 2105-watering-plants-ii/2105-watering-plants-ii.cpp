class Solution {
public:
    int minimumRefill(vector<int>& arr, int icapA, int icapB) {
        int low=0;
        int capA=icapA;
        int capB=icapB;
        int cnt=0;
        int high=arr.size()-1;
        while(low<=high){
            if (low==high){
                if (capA==capB || capA>capB){
                    if (arr[low]<=capA){
                        capA-=arr[low];
                    }
                    else{
                        cnt++;
                        capA=icapA;
                        capA-=arr[low];
                    }
                    
                    low++;
                }
                else if (capB>capA){
                    if (arr[high]<=capB){
                        capB-=arr[high];
                    }else{
                        cnt++;
                        capB=icapB;
                        capB-=arr[high];
                    }
                    
                    high--;
                }
            }
            else{
                if (arr[low]<=capA){
                    capA-=arr[low];
                    low++;
                }
                else{
                    cnt++;
                    capA=icapA;
                    capA-=arr[low];
                    low++;
                }
                
                if (arr[high]<=capB){
                    
                    capB-=arr[high];
                    high--;
                }
                else{
                    cnt++;
                    capB=icapB;
                    capB-=arr[high];
                    high--;
                }
                
            }
        }
        return cnt;
    }
};