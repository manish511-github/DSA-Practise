class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        int maxi=0;
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='('){
                st.push(i);
            }
            else {
                if (!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                   st.push(i);

                }
            }
        }

        int endterminal = s.length();

        while(!st.empty())
        {
            int startterminal = st.top();
            cout<<startterminal;
            st.pop();
            maxi = max(maxi,endterminal-startterminal-1);
            endterminal = startterminal;

        }
        return max(maxi,endterminal);
        
    }
};