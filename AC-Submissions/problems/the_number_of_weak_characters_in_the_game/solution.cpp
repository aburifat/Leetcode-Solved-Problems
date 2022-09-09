#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        ordered_set oss;
        int len=properties.size();
        vector<pair<int,int>>v;
        for(int i=0;i<len;i++){
            v.push_back({properties[i][0],properties[i][1]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<len;i++){
            oss.insert(v[i].second);
        }
        int pre=-1;
        int ans=0;
        for(int i=0;i<len;i++){
            pre=v[i].first;
            vector<int>res;
            res.push_back(v[i].second);
            int pos=oss.order_of_key(v[i].second);
	        int val=*oss.find_by_order(pos);
	        if(v[i].second==val)oss.erase(oss.find_by_order(pos));
            while(i<len-1&&v[i+1].first==pre){
                i++;
                res.push_back(v[i].second);
                pos=oss.order_of_key(v[i].second);
	            val=*oss.find_by_order(pos);
	            if(v[i].second==val)oss.erase(oss.find_by_order(pos));
            }
            if(i!=len-1){
                for(int j=0;j<res.size();j++){
                    int nowVal=res[j];
                    pos=oss.size()-1;
                    val=*oss.find_by_order(pos);
                    if(val>nowVal)ans++;
                }
            }
        }
        return ans;
    }
};