class Solution {
public:
    bool isPathCrossing(string arr) {
        set<pair<int,int>>st;
        int x=0;
        int y=0;
        st.insert({0,0});
        for(int i=0;i<arr.size();i++){
        if (arr[i]=='N'){
            y=y+1;
            if (st.find({x,y})!=st.end()){
                return true;
            }else{
                st.insert({x,y});
            }
            
        }else if (arr[i]=='S'){
            y=y-1;
            if (st.find({x,y})!=st.end()){
                return true;
            }else{
                st.insert({x,y});
            }
        } else if (arr[i]=='E'){
            x=x+1;
            if (st.find({x,y})!=st.end()){
                return true;
            }else{
                st.insert({x,y});
            }
        }else if (arr[i]=='W'){
            x=x-1;
            if (st.find({x,y})!=st.end()){
                return true;
            }else{
                st.insert({x,y});
            }
        }
        }
        return false;
        
    }
};