class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
     if(s1.size()!=s2.size())
     {
        return false;
     }
     int count =0;
     int index =-1;

     for(int i=0;i<s1.size();i++)
     {
        if (s1[i]!=s2[i])
        {
            if (count ==0 )
            {
                index =i;
                count++;

            }
            else if (count ==1)
            {
                if (s1[i]==s2[index] && s2[i] == s1[index])
                {
                    count++;
                }
                else{
                    return false;
                }

            }
            else
            {
                count++;
            }
          

        }
     }
     return count ==0 || count ==2  ;
        
    }
};