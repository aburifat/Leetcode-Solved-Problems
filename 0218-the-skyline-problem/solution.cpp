#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
ll,
null_type,
less_equal<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<ll>>v;
        vector<vector<ll>>anstmp;
        vector<ll>emp;
        for(ll i=0;i<buildings.size();i++){
            v.push_back(emp);
            for(ll j=0;j<buildings[i].size();j++){
                v[i].push_back((ll)buildings[i][j]);
            }
        }
        ll len=v.size();
        vector<ll>xval;
        map<ll,ll>mp;
        xval.push_back(-1);
        for(ll i=0;i<len;i++){
            ll a=v[i][0];
            ll b=v[i][1];
            if(!mp[a]){
                mp[a]=xval.size();
                xval.push_back(a);
            }
            if(!mp[b]){
                mp[b]=xval.size();
                xval.push_back(b);
            }
            if(!mp[b+1]){
                mp[b+1]=xval.size();
                xval.push_back(b+1);
            }
        }
        sort(xval.begin(),xval.end());
        for(ll i=0;i<xval.size();i++)mp[xval[i]]=i;
        ll siz=xval.size();
        vector<ll>left[10010],right[10010];
        ll height[siz+50];
        for(ll i=0;i<siz+50;i++)height[i]=0;
        for(ll i=0;i<len;i++){
            left[mp[v[i][0]]].push_back(i);
            right[mp[v[i][1]+1]].push_back(i);
        }
        ordered_set oss;
        long long pre=0;
        for(ll i=1;i<siz;i++){
            for(ll j=0;j<right[i].size();j++){
                ll pos=oss.order_of_key(v[right[i][j]][2]);
                oss.erase(oss.find_by_order(pos));
            }
            ll curr;
            if(oss.size()==0&&pre!=0){
                vector<ll>tmp;
                tmp.push_back(xval[i]-1);
                tmp.push_back(0);
                anstmp.push_back(tmp);
                pre=curr=0;
            }
            for(ll j=0;j<left[i].size();j++){
                oss.insert(v[left[i][j]][2]);
            }
            if(oss.size()==0)curr=0;
            else curr=*oss.find_by_order(oss.size()-1);
            if(curr>pre){
                vector<ll>tmp;
                tmp.push_back(xval[i]);
                tmp.push_back(curr);
                anstmp.push_back(tmp);
            }else if(curr<pre){
                vector<ll>tmp;
                ll val=xval[i]-1;
                tmp.push_back((int)val);
                tmp.push_back(curr);
                anstmp.push_back(tmp);
            }
            pre=curr;
        }
        vector<vector<int>>ans;
        vector<int>emp2;
        for(ll i=0;i<anstmp.size();i++){
            ans.push_back(emp2);
            for(ll j=0;j<anstmp[i].size();j++){
                ans[i].push_back((int)anstmp[i][j]);
            }
        }
        return ans;
    }
};
