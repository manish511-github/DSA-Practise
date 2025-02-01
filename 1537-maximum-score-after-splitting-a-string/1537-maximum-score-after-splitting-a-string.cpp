class Solution {
public:
    int maxScore(string s) {
        int n =s.length();
        int zeros =0;
        int maxi=0;
        for(int i =0; i<n;i++)
        {
            if(s[i] =='0' )
            {
                zeros++;
            }
        }

        int ones =0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                zeros--;
            }
            if(i!=0 && s[i]=='1')
            {
                ones++;
            }
            cout<<zeros+ones<<endl;
            maxi =max(maxi,zeros+ones);
            
        }
        
        return maxi;
    }
};