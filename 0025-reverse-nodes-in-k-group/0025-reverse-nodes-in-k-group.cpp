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

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k <= 1)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;  

        while (true)
        {
            ListNode *groupStart = prevGroupEnd->next;
            ListNode *groupEnd = groupStart;
            for (int i = 1; i < k && groupEnd; ++i)
                groupEnd = groupEnd->next;

            if (!groupEnd)
                break;

            ListNode *nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr;

            // Reverse the current group
            ListNode *prev = nullptr, *curr = groupStart;
            while (curr)
            {
                ListNode *nextTemp = curr->next;
                curr->next = prev; 
                prev = curr;
                curr = nextTemp;
            }

            // Connect the reversed group with the previous part
            prevGroupEnd->next = prev;
            groupStart->next = nextGroupStart;

            // Move to the next group
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};