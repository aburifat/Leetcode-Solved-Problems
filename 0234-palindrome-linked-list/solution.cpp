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
    void print(ListNode* head){
        int ck=0;
        while(1){
            if(head==nullptr)break;
            if(!ck)ck++;
            else cout<<" -> ";
            cout<<head->val;
            head=head->next;
        }
        cout<<endl;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)return true;
        int ct=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            curr=curr->next;
            ct++;
        }
        ct=(ct/2)+(ct%2);
        ListNode* lastHead=head;
        ListNode* pre=head;
        while(ct--){
            pre=lastHead;
            lastHead=lastHead->next;
        }
        pre->next=nullptr;
        //cout<<lastHead->val<<endl;
        //cout<<pre->val<<endl;
        curr=lastHead;
        pre=nullptr;
        ListNode* nxt=lastHead->next;
        while(1){
            curr->next=pre;
            if(nxt==nullptr){
                lastHead=curr;
                break;
            }
            pre=curr;
            curr=nxt;
            nxt=curr->next;
        }
        //print(head);
        //print(lastHead);
        bool ans=true;
        ListNode* fst=head;
        ListNode* lst=lastHead;
        while(1){
            if(fst==nullptr||lst==nullptr)break;
            if(fst->val!=lst->val){
                ans=false;
                break;
            }
            fst=fst->next;
            lst=lst->next;
        }
        return ans;
    }
};
