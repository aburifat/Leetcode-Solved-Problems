class NumArray {
    vector<int>tree;
	int Trush=0;
    int siz;
public:
    int combine(int a, int b){
		return a+b;
	}
    void TreeBuild(vector<int>& nums, int idx, int tl, int tr){
		if(tl==tr)tree[idx]=nums[tl];
		else{
			int tm=tl+(tr-tl)/2;
			TreeBuild(nums,idx*2,tl,tm);
			TreeBuild(nums,idx*2+1,tm+1,tr);
			tree[idx]=combine(tree[idx*2],tree[idx*2+1]);
		}
	}
    NumArray(vector<int>& nums) {
        int len=nums.size();
        siz=len;
        tree.resize(len*4);
        TreeBuild(nums,1,0,len-1);
    }
    void TreeUpdate(int idx, int tl, int tr, int pos, int val){
		if(tl==tr)tree[idx]=val;
		else{
			int tm=tl+(tr-tl)/2;
			if(pos<=tm)TreeUpdate(idx*2,tl,tm,pos,val);
			else TreeUpdate(idx*2+1,tm+1,tr,pos,val);
			tree[idx]=combine(tree[idx*2],tree[idx*2+1]);
		}
	}
    void update(int index, int val) {
        TreeUpdate(1,0,siz-1,index,val);
    }
    int TreeQuery(int idx, int tl, int tr, int l, int r){
		if(l>r)return Trush;
		if(l==tl&&r==tr)return tree[idx];
		int tm=tl+(tr-tl)/2;
		return combine(TreeQuery(idx*2,tl,tm,l,min(r,tm)),TreeQuery(idx*2+1,tm+1,tr,max(l,tm+1),r));
	}
    int sumRange(int left, int right) {
        return TreeQuery(1,0,siz-1,left,right);
    }
};

/**
 * Your NumArray object wiint be instantiated and cainted as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
