class TimeMap {
public:
    vector<int>timeTable[110];
    vector<string>keys;
    map<string,int>keyMap;
    map<pair<int,int>,string>timeLock;
    TimeMap() {
        for(int i=0;i<110;i++)timeTable[i].clear();
        timeLock.clear();
        keys.clear();
        keyMap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        if(!keyMap[key]){
            keys.push_back(key);
            keyMap[key]=keys.size();
        }
        timeTable[keyMap[key]-1].push_back(timestamp);
        timeLock[{keyMap[key]-1,timestamp}]=value;
    }
    
    string get(string key, int timestamp) {
        int keyVal=keyMap[key]-1;
        if(keyVal<0||timeTable[keyVal].size()==0)return "";
        int nowTime=lower_bound(timeTable[keyVal].begin(),timeTable[keyVal].end(),timestamp)-timeTable[keyVal].begin();
        if(nowTime==timeTable[keyVal].size()||timeTable[keyVal][nowTime]>timestamp)nowTime--;
        if(nowTime<0)return "";
        nowTime=timeTable[keyVal][nowTime];
        return timeLock[{keyVal,nowTime}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */