class Solution {
public:
    int countCompleteSubarrays(vector<int>& arr) {
        int head=0;
        int tail=0;  
        // 3 1 2 2 3
        // 3 -> 1
        // 3 1 -> 
        // 3 1 2 ->

        // 1 2 3
        // 1 + (1 2 ) + (1 ,1 2  , 1 2 3, 2 3 , 2, 3)



           // 1 3 1 2 2 
                        // set -> 3
                        // 1 -> 1
                        // 3-> 1
                        // 2 -> 1
                        // 1 3 1 2 2 
                        // -------
                        //   3 1 2 
                        // 

        int total=0;
        unordered_map<int,int>mp;
        unordered_set<int> st(arr.begin(),arr.end());
        int k = st.size();
                    int count=0;

        for(head=0;head<arr.size();head++)
        {
            mp[arr[head]]++;
            while(tail<=head && mp.size()==k)
            {
                mp[arr[tail]]--;
                if (mp[arr[tail]]==0)
                {
                    mp.erase(arr[tail]);
                }
                tail++;
                count+= (arr.size()-head);
            }

        }

        return count;
    }
};