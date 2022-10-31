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
    void mergelist(ListNode* l1, ListNode* l2, ListNode* merge)
    {
        if(l1==NULL&&l2==NULL)
            return;
        else
        {
            if(l1!=NULL&&l2!=NULL)
            {
                if(l1->val>l2->val)
                {
                    merge->next=new ListNode(l2->val);
                    mergelist(l1,l2->next,merge->next);
                }
                else
                {
                    merge->next=new ListNode(l1->val);
                    mergelist(l1->next,l2,merge->next);
                }
            }
            else if(l1!=NULL&&l2==NULL)
            {
                merge->next=new ListNode(l1->val);
                mergelist(l1->next,l2,merge->next);
            }
            else
            {
                merge->next=new ListNode(l2->val);
                mergelist(l1,l2->next,merge->next);
            }
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* merge=new ListNode();
        ListNode* head=merge;
        mergelist(l1,l2,merge);
        return head->next;
    }
};
