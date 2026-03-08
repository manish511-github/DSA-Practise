class Solution {
public:
    int minimumOperations(vector<int>& arr) {
        // 3 -> 2
        // 4 -> 1
        // 3-2+3-1 = 1+2=3
        // total_index - maxleft // 6-2 = 4 -1 = 3

        // 1 --> 1
        // 2 --> 1
        // 3 --> 1

        // 1 -> 1      2 -> 2
        // 2 -> 2
        unordered_map<int,int>even;
        unordered_map<int,int>odd;
        for (int i=0;i<arr.size();i++){
            if (i%2==0){
                even[arr[i]]++;

            }
            else{
                odd[arr[i]]++;              
            }
        }
        int total_freq=arr.size();
        vector<pair<int,int>> even_freq (even.begin(),even.end());
        vector<pair<int,int>> odd_freq (odd.begin(), odd.end());
        sort(even_freq.begin(), even_freq.end(), [](auto &a, auto &b){
                    return a.second > b.second;
        });
        sort(odd_freq.begin(), odd_freq.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        int e_val = even_freq.size() ? even_freq[0].first : -1;
        int e_freq = even_freq.size() ? even_freq[0].second : 0;
        int e_freq2 = even_freq.size() > 1 ? even_freq[1].second : 0;

        int o_val = odd_freq.size() ? odd_freq[0].first : -1;
        int o_freq = odd_freq.size() ? odd_freq[0].second : 0;
        int o_freq2 = odd_freq.size() > 1 ? odd_freq[1].second : 0;

        int n = arr.size();

        if (e_val != o_val)
            return n - (e_freq + o_freq);

        return n - max(e_freq + o_freq2, e_freq2 + o_freq);
        
    }
};