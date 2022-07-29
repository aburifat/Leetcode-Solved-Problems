/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* here=head;
        ListNode* tortoise=head;
        bool ans=false;
        while(1){
            if(here==nullptr||here->next==nullptr||here->next->next==nullptr)break;
            here=here->next->next;
            tortoise=tortoise->next;
            if(here==tortoise){
                ans=true;
                break;
            }
        }
        return ans;
    }
};
