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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp=nullptr;
        if(head==nullptr)return head;
        ListNode* curr=head;
        ListNode* nxt=head->next;
        while(1){
            curr->next=tmp;
            if(nxt==nullptr)return curr;
            tmp=curr;
            curr=nxt;
            nxt=nxt->next;
        }
    }
};
