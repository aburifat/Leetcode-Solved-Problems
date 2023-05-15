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
    ListNode* swapNodes(ListNode* head, int k) {
        int ct=0,idx=0;
        ListNode* curr=head;
        ListNode* fst=nullptr;
        ListNode* lst=nullptr;
        while(curr!=nullptr){
            ct++;
            if(fst==nullptr&&ct%k==0){
                fst=curr;
                lst=head;
                idx=1;
            }
            if(fst!=nullptr&&(ct-idx)==k){
                lst=lst->next;
                idx++;
            }
            curr=curr->next;
        }
        swap(fst->val,lst->val);
        return head;
    }
};
