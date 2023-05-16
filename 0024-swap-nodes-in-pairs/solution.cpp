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
    ListNode* swapPairs(ListNode* head) {
        ListNode* st = nullptr;
        ListNode* curr = head;
        ListNode* nxt=nullptr;
        ListNode* ed=nullptr;
        while(curr!=nullptr){
            nxt=curr->next;
            if(nxt!=nullptr){
                ed=nxt->next;
                if(st!=nullptr)st->next= nxt;
                nxt->next=curr;
                curr->next=ed;
                if(st==nullptr)head=nxt;
            }else break;
            st=curr;
            curr=st->next;
        }
        return head;
    }
};
