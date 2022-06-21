class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int len=heights.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        int idx=0;
        int ct=0;
        for(int i=1;i<len;i++){
            int dif=heights[i]-heights[i-1];
            if(dif>0){
                if(ct<ladders){
                    pq.push(dif);
                    idx=i;
                    ct++;
                }else{
                    int mn=dif;
                    if(!pq.empty())mn=min(pq.top(),mn);
                    if(mn<=bricks){
                        pq.push(dif);
                        pq.pop();
                        bricks-=mn;
                        idx=i;
                    }else break;
                }
            }else idx=i;
        }
        return idx;
    }
};
