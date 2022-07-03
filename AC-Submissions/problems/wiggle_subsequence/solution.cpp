class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>tmp;
        for(int i=1;i<nums.size();i++){
            int dif=nums[i-1]-nums[i];
            if(tmp.size()==0){
                if(dif!=0)tmp.push_back(dif);
                continue;
            }
            if(dif==0)continue;
            if(dif<0&&tmp[tmp.size()-1]<0)tmp[tmp.size()-1]=min(tmp[tmp.size()-1],dif);
            else if(dif>0&&tmp[tmp.size()-1]>0)tmp[tmp.size()-1]=max(tmp[tmp.size()-1],dif);
            else tmp.push_back(dif);
        }
        return tmp.size()+1;
    }
};