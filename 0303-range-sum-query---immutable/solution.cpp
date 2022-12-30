typedef long long ll;
static const ll MXN=5e5;
static const ll K=20;
ll n=1e5,k;
ll lg[MXN+5];
ll arr[MXN+5];
ll st[K+5][MXN+5];

void setLog(){
    lg[0]=lg[1]=0;
    for(ll i=2;i<=MXN;i++)lg[i]=lg[i/2]+1;
}

ll func(ll a, ll b){
    ll val=a+b;
    return val;
}

void build(){
    setLog();
    k=lg[n];
    k++;
    for(ll i=0;i<n;i++)st[0][i]=arr[i];
    for(ll i=1;i<=k;i++){
        for(ll j=0;j+(1<<i)<=n;j++){
            st[i][j]=func(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}

ll query(ll l, ll r){
    ll ans=0;
    for(ll i=k;i>=0;i--){
        if((1<<i)<=r-l+1){
            ans=func(ans,st[i][l]);
            l+=(1<<i);
        }
    }
    return ans;
}

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        for(ll i=0;i<n;i++)arr[i]=nums[i];
        build();
    }
    
    int sumRange(int left, int right) {
        cout<<left<<" "<<right<<endl;
        int ans=query(left,right);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
