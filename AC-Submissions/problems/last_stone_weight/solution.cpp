class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int> >pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        int ans=0;
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            if(!pq.empty()){
                int b=pq.top();
                pq.pop();
                int dif=abs(a-b);
                if(dif>0)pq.push(dif);
            }else{
                ans=a;
                break;
            }
        }
        return ans;
    }
};