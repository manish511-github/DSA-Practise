class Solution {
public:

    int minFlips(string s) {
        int mini=INT_MAX;
        // there are no operation count for task1 
        int n=s.length();
        string str1;
        string str = s+s;

        int tail=0;
        int diff1=0;
        int diff2=0;

        for (int i=0;i<str.length();i++){
            // even or odd indexes
            int expected1 = (i%2==0)?'0':'1';
            int expected2 = (i%2==0)?'1':'0';
            if (str[i]!=expected1){
                diff1++;
            }
            if (str[i]!=expected2){
                diff2++;
            }
            // '111000111000'
            while(i-tail+1>s.length()){
                //compare the strings and handle 
              
                int tail1 = (tail%2==0)?'0':'1';
                int tail2 = (tail%2==0)?'1':'0';
                if (str[tail]!=tail1){
                    diff1--;
                }
                if (str[tail]!=tail2){
                    diff2--;
                }
                    tail ++;
                }
            if (i-tail+1==s.length()){
                mini = min(mini, min(diff1, diff2));
            }

        }
        return mini;
        
    }
};