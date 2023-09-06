/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getNode(ListNode* node, int nxtct){
        if(node==nullptr||nxtct<=0)return node;
        return getNode(node->next,--nxtct);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for(auto _ = head; _ ; _ = _->next)len++;
        vector<ListNode*>ans(k,nullptr);
        int ct = len/k;
        int rem = len%k;
        ListNode* curr = head;
        for(int i=0;i<k;i++){
            ans[i]=curr;
            int siz = ct;
            if(rem>0){
                siz++;
                rem--;
            }
            curr=getNode(curr,siz-1);
            if(curr!=nullptr){
                ListNode* tmp = curr->next;
                curr->next=nullptr;
                curr=tmp;
            }
        }
        return ans;
    }
};
