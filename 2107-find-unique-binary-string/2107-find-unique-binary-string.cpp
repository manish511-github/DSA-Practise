class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(),nums.end());
        int n = nums.size();
        int total = 1<<n;
        for (int i=0;i<total;i++)
        {
            string str="";
            for (int j=n-1;j>=0;j--)
            {
                str+=to_string(((i>>j)&1));

            }
            if(s.find(str)==s.end())
            {
                return str;
            }
        
        }
        return "";
        
    }

};