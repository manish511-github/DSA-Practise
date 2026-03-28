class FrequencyTracker {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>fp;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int x= mp[number];
        mp[number]++;
        int y= mp[number];
        fp[x]--;
        if (fp[x]==0){
            fp.erase(x);
        }
        fp[y]++;
    }
    
    void deleteOne(int number) {
        if (mp.find(number)!=mp.end()){
            int x= mp[number];
            mp[number]--;
            fp[x]--;
             fp[mp[number]]++;
            if (mp[number]==0){
                mp.erase(number);
            }
           
        if (fp[x]==0){
            fp.erase(x);
        }
        }
        
    }
    
    bool hasFrequency(int frequency) {
 if (fp.find(frequency)!=fp.end()){
    return true;
 }
 return false;
        
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */