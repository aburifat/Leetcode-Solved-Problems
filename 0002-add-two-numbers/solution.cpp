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
    ListNode* ins(int &rem, ListNode* sum){
        ListNode* curr=new ListNode();
        sum->next=curr;
        if(rem<10){
            curr->val=rem;
            rem=0;
        }
        else{
            curr->val=(rem%10);
            rem/=10;
        }
        return curr;
    }

    void result(int rem, ListNode* l1, ListNode* l2, ListNode* sum){
        if(l1==nullptr&&l2==nullptr){
            if(rem){
                ListNode* curr=ins(rem,sum);
                result(rem,l1,l2,curr);
            }
        }else if(l1==nullptr){
            rem=rem+l2->val;
            ListNode* curr=ins(rem,sum);
            result(rem,l1,l2->next,curr);
        }else if(l2==nullptr){
            rem=rem+l1->val;
            ListNode* curr=ins(rem,sum);
            result(rem,l1->next,l2,curr);
        }else{
            rem=rem+l1->val+l2->val;
            ListNode* curr=ins(rem,sum);
            result(rem,l1->next,l2->next,curr);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum=new ListNode();
        result(0,l1,l2,sum);
        return sum->next;
    }
};
