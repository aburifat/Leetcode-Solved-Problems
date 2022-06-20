class Solution {
public:
    void margeSort(int l, int r, vector<vector<int>>& events){
        if(l<r){
            int mid=l+(r-l)/2;
            margeSort(l,mid,events);
            margeSort(mid+1,r,events);
            vector<vector<int>>tmp;
            int i=l,j=mid+1;
            for(i=l,j=mid+1;i<=mid&&j<=r;){
                if(events[i][1]>events[j][1]){
                    tmp.push_back(events[j]);
                    j++;
                }else if(events[i][1]==events[j][1]&&events[i][0]>events[j][0]){
                    tmp.push_back(events[j]);
                    j++;
                }else{
                    tmp.push_back(events[i]);
                    i++;
                }
            }
            while(i<=mid){
                tmp.push_back(events[i]);
                i++;
            }
            while(j<=r){
                tmp.push_back(events[j]);
                j++;
            }
            for(int i=0;i<tmp.size();i++){
                events[i+l]=tmp[i];
            }
        }
    }
    vector<int>DSU;
    int find_DSU(int val){
        if(DSU[val]==val)return val;
        return DSU[val]=find_DSU(DSU[val]);
    }
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        int len=events.size();
        //margeSort(0,len-1,events);
        sort(events.begin(),events.end(),cmp);
        int mxTime=events[events.size()-1][1];
        for(int i=0;i<=mxTime+1;i++)DSU.push_back(i);
        int ct=0;
        for(int i=0;i<len;i++){
            int slot=find_DSU(events[i][0]);
            if(slot<=events[i][1]){
                ct++;
                DSU[slot]=find_DSU(slot+1);
            }
        }
        return ct;
    }
};