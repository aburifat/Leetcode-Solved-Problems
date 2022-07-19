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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a;
        ListNode* b;
        ListNode* pre;
        a=head;
        b=head;
        pre=head;
        while(a!=nullptr){
            n--;
            a=a->next;
            if(n<0)b=b->next;
            if(n<-1)pre=pre->next;
        }
        if(b->next!=nullptr){
            b->val = b->next->val;
            b->next = b->next->next;
        }else if(pre!=b){
            pre->next=nullptr;
        }else head=nullptr;
        return head;
    }
};
