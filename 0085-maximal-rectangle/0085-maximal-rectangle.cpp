class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        // 2 1 5 6 2 3 0 2 1 10 2 3 
        // smaller on left 
        // smaller on right
        int n=arr.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;
        for (int i=0;i<arr.size();i++){
            if (st.empty()){
                left[i]=-1;
            
            }
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();
            }
            if (st.empty()){
                left[i]=-1;
                
            }
            else{
            int x=st.top();
            left[i]=x;
        
            }
            st.push(i);

        }
        while(!st.empty()){
            st.pop();
        }
        for (int i=n-1;i>=0;i--){
            if (st.empty()){
                right[i]=n;
                
            }
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if (st.empty()){
                right[i]=n;
            }
            else {
                int x= st.top();
                right[i]=x;
                

            }
            st.push(i);
        }
        int maxi=0;
        for (int i=0;i<arr.size();i++){
            maxi=max(maxi,(right[i]-left[i]-1)*arr[i]);
        }
        return maxi;
        
    }

    int maximalRectangle(vector<vector<char>>& arr) {
       int n=arr.size(); 
       int m=arr[0].size();
       vector<int> v(m,0);
       int maxi=0;
       for (int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if (arr[i][j]=='0'){
                v[j]=0;
            }else{
                v[j]++;
            }
        }
        maxi=max(maxi,largestRectangleArea(v));
        
       }
       return maxi;

    }
};