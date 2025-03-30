class Solution {
public:
    // vector<int> dig={0,1,2,3,4,5,6,7,8,9};
    vector<string>alp={"-","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
   void helper(string digits,vector<string> &v,string asf,int start)
    {
        if(asf.size()==digits.length())
        {
            v.push_back(asf);
            return;
            
}
        for(int i=start;i<digits.length();i++)
        {
            int dig=digits[i]-48;

            for(int j=0;j<alp[dig].length();j++)
            {
                helper(digits,v,asf+alp[dig][j],i+1);
                
            }
            
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string > v;
        string asf;
        if(digits.size()==0)
        {
            return v;
            
        }
        helper(digits,v,asf,0);
        return v;
        
        
    }
};