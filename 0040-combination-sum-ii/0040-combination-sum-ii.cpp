class Solution {
public:

    
    void helper(vector<int>& arr,int index,int sum,   vector<int> &v, vector<int> &box,set<vector<int>> &ans)
    {
        if(sum==0)
        {
ans.insert(v);
            
            return;
            
            
        }
        if(sum<0 ||index==arr.size())
        {
            return;
            
        }
        for(int i=index;i<arr.size();i++)
        {
            if(i>index && arr[i]==arr[i-1])
            {
                continue;
                
            }
                        if(arr[index]<=sum)
            {

         
            v.push_back(arr[i]);
            helper(arr,i+1,sum-arr[i],v,box,ans);
                v.pop_back();

            }
            
            
            
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int sum) {
   
        int n=arr.size();
vector<vector<int>>res;
        set<vector<int>>ans;
        vector<int> v;
        vector<int> box(n,0);
        
 sort(arr.begin(),arr.end());
        
                helper(arr,0,sum,v,box,ans);
for(auto it: ans)
{
    res.push_back(it);
    
}
        return res;
        
        
    }
};