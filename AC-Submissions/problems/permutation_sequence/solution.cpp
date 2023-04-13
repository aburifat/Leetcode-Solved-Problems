#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string s="";

        ordered_set oss;
        for(int i=1;i<=n;i++)oss.insert(i);

        // n!
        int fact = 1;
        for(int i=2;i<=n;i++){
            fact*=i;
        }

        for(int i=n;i>0;i--){
            fact/=i; // (n-1)!
            int idx = (i==1)? 0 : (k/fact);
            k %= fact;
            int val=*oss.find_by_order(idx);
            s+=to_string(val);
            oss.erase(oss.find_by_order(idx));
        }
        return s;
    }
};