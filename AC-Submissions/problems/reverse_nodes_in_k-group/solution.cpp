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
    pair<bool,ListNode*>check(ListNode* head, int k){
        int ct=1;
        while(ct<k&&head!=nullptr){
            head=head->next;
            ct++;
        }
        if(ct==k&&head!=nullptr)return {true,head};
        else return {false,nullptr};
    }
    ListNode* flip(ListNode* head, ListNode* tail, int k){
        if(head==nullptr||head->next==nullptr)return head;
        else{
            ListNode* pre=head;
            ListNode* curr=head->next;
            ListNode* nxt=head->next->next;
            for(int i=1;i<k;i++){
                curr->next=pre;
                pre=curr;
                curr=nxt;
                if(nxt!=nullptr)nxt=nxt->next;
            }
            head->next=nullptr;
            return curr;
        }
    }
    pair<ListNode*, ListNode*>join(ListNode* preHead, ListNode* preTail, ListNode* head, ListNode* tail){
        preTail->next=head;
        return {preHead,tail};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        bool ck;
        ListNode* tail;
        ListNode* root=new ListNode();
        ListNode* preHead=root;
        ListNode* preTail=root;
        ListNode* nextHead;
        pair<int,ListNode*>pr;
        pair<ListNode*, ListNode*>lpr;
        while(1){
            pr=check(head,k);
            ck=pr.first;
            tail=pr.second;
            if(!ck){
                lpr=join(preHead,preTail,head,tail);
                preHead=lpr.first;
                preTail=lpr.second;
                break;
            }else{
                nextHead=flip(head,tail,k);
                swap(head,tail);
                lpr=join(preHead,preTail,head,tail);
                preHead=lpr.first;
                preTail=lpr.second;
                head=nextHead;
            }
        }
        return root->next;
    }
};