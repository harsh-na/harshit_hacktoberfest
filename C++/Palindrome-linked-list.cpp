class Solution {
public:
    ListNode * reverse(ListNode * head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * curr = head;
        ListNode * pre = NULL;
        ListNode * nex = NULL;
        
        while(curr != NULL)
        {
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }
        
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return true;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode * start = head;
        while(slow != NULL)
        {
            if(slow->val != start->val)
                return false;
            
            slow = slow->next;
            start = start->next;
        }
        return true;
    }
};
