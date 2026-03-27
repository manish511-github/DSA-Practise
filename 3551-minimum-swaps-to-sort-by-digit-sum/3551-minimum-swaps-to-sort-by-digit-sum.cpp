class Solution {
public:
void helper(int node, vector<int> adj[], vector<int>& visited,int &cnt){
    visited[node]=1;
    cnt++;
    for (auto it:adj[node]){
        if (!visited[it]){
            helper(it,adj,visited,cnt);
        }
    }

}
    int digitsum(int x){
        int sum=0;
        while(x>0){
            int digit = x%10;
            sum+=digit;
            x/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>smp;
        
        for (int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        
        for (int i=0;i<arr.size();i++){
            smp[arr[i]]=digitsum(arr[i]);
        }
        //[277993448,416038674,616955867,539372283]             0->1->3->2->0   min swap -> k-1
            // 0           1           2       3
        // [416038674 539372283 277993448 616955867 ]           // 0->1->3->2
            // 0           1           2       3

        // 539372283 416038674 277993448 616955867

        //  


        sort(arr.begin(), arr.end(), [&smp](const int &a , const int &b){
            // string sa = to_string(a);
            // string sb = to_string(b);
            int suma=smp[a];
            int sumb=smp[b];
            // for (int i=0;i<sa.size();i++){
            //     suma+=(sa[i] -'0');
            // }
            // for (int i=0;i<sb.size();i++){
            //     sumb+=(sb[i] -'0');
            // }
            if (suma<sumb){
                return true;
            }
            else if(suma>sumb){
                return false;
            }
             
            return a<b;
        });
        int cnt=0;
//        [18,43,34,16]             0 -> 1  // 
//          0  1 2  3
//        [16 34 43 18 ]            0-> 3->0 -> 1+ 1
//          0  1  2 3           
        vector<int> visited(arr.size(),0);
        int n=arr.size();
        vector<int> adj[n];
        for (int i=0;i<arr.size();i++){
            adj[i].push_back(mp[arr[i]]);
        }
        int sum=0;

        for (int i=0;i<arr.size();i++){
            int cnt=0;
            if (!visited[i]){
                helper(i,adj,visited,cnt);
                sum+=(cnt-1);
                
            }
            
        }
        // if (arr.size()%2!=0){
        //     return (cnt/2)+1;
        // }
        return sum;

    }
};