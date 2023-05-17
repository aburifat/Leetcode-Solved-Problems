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
    int pairSum(ListNode* head) {
        ListNode* pre=nullptr;
        ListNode* slow=head;
        ListNode* nxt=head->next;
        ListNode* fast=head->next;
        while(1){
            slow->next=pre;
            pre=slow;
            fast=(fast->next==nullptr)?nullptr:fast->next->next;
            if(fast==nullptr)break;
            slow=nxt;
            nxt=slow->next;
        }
        int ans=0;
        while(nxt!=nullptr){
            ans=max(ans,nxt->val+slow->val);
            nxt=nxt->next;
            slow=slow->next;
        }
        return ans;
    }
};
