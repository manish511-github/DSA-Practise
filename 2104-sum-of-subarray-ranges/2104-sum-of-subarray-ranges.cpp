class Solution {
public:

void getmaxleft(vector<int>& arr,vector<int> & max_left,stack<int> &st){
    int n=arr.size();
                for (int i=0;i<n;i++){
                // if (i==0){
                //     max_left[i]=-1;
                // }
                while(!st.empty() && arr[st.top()]<arr[i]){
                    st.pop();
                }
                
                if (!st.empty()){
                max_left[i]=st.top();

                }else{
                    max_left[i]=-1;
                }
                st.push(i);
            }
            return;
}

void getminleft(vector<int>& arr,vector<int> & min_left,stack<int> &st){
    int n=arr.size();
                for (int i=0;i<n;i++){
                // if (i==0){
                //     min_left[i]=-1;
                // }
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                
                if (!st.empty()){
                min_left[i]=st.top();

                }else{
                    min_left[i]=-1;
                }
                st.push(i);
            }
            return;
}

void getminright(vector<int>& arr,vector<int> & min_right,stack<int> &st){
    int n=arr.size();
                for (int i=n-1;i>=0;i--){
                // if (i==n-1){
                //     min_right[i]=n;
                // }
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                
                if (!st.empty()){
                min_right[i]=st.top();

                }
                else{
                    min_right[i]=n;
                }
                st.push(i);
            }
            return;
}

void getmaxright(vector<int>& arr,vector<int> & max_right,stack<int> &st){
    int n=arr.size();
                for (int i=n-1;i>=0;i--){
                // if (i==n-1){
                    
                // }
                while(!st.empty() && arr[st.top()]<=arr[i]){
                    st.pop();
                }
                
                if (!st.empty()){
                max_right[i]=st.top();

                }
                else{
                    max_right[i]=n;
                }
                st.push(i);
            }
            return;
}
    long long subArrayRanges(vector<int>& arr) {
            // next greater element index on left
            // next greater element index on right
            //  next smaller element index on right
            //  next smaller element index on left
            int n=arr.size();
            stack<int> st;
            vector<int> max_left(n,0);
            vector<int> max_right(n,0);
            vector<int> min_left(n,0);
            vector<int> min_right(n,0);



            getmaxright(arr,max_right,st);
            while(!st.empty()){
                st.pop();
            }
            getmaxleft(arr,max_left,st);
            while(!st.empty()){
                st.pop();
            }
            getminright(arr,min_right,st);
            while(!st.empty()){
                st.pop();
            }
            getminleft(arr,min_left,st);

            for (auto x : max_left) cout << x << " ";
            cout<<endl;
            for (auto x : max_right) cout << x << " ";
            cout<<endl;
            for (auto x : min_left) cout << x << " ";
            cout<<endl;
            for (auto x : min_right) cout << x << " ";
            cout<<endl;

            long long  sum=0;
            for (int i=0;i<n;i++){
                sum += 1LL * arr[i] * (i - max_left[i]) * (max_right[i] - i);
            }
            
            long long sum2=0;
            for (int i=0;i<n;i++){
                sum2 += 1LL * arr[i] * (i - min_left[i]) * (min_right[i] - i);
            }
            return abs(sum-sum2);
    }
};