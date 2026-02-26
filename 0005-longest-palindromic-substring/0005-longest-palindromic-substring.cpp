class Solution {
public:

int helper(int start , int end, string s){
    while(start >= 0 && end<s.length() && s[start]==s[end]){
        start--;
        end++;

    }
    return end-start-1;
}
    string longestPalindrome(string s) {
        // babad
        int maxi=INT_MIN;
        int start;
        for(int i=0;i<s.length();i++){
            int len1 = helper(i,i,s);
            int len2 = helper(i,i+1,s);
            int len3 = max(len1, len2);
            if (len3 > maxi){
                maxi = len3;

                start = i-(len3-1)/2;

            }
        }
        return s.substr(start,maxi);


    }
};