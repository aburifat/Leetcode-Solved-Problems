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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*>mp;
        ListNode* curr=head;
        int sum=0;
        while(curr!=nullptr){
            sum+=curr->val;
            if(mp[sum]!=nullptr){
                ListNode* tmp=mp[sum]->next;
                int tmpsum=sum;
                while(tmp!=curr){
                    tmpsum+=tmp->val;
                    mp[tmpsum]=nullptr;
                    tmp=tmp->next;
                }
                mp[sum]->next=curr->next;
                curr=curr->next;
            }else if(sum==0){
                head=curr->next;
                curr=curr->next;
                mp.clear();
            }else{
                mp[sum]=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};
