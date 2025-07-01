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
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
 
        if (l1)
            current->next = l1;
        if (l2)
            current->next = l2;

        return dummy->next; 
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1)  // Continue merging until only one list remains
        { 
            vector<ListNode *> mergedLists;
            for (int i = 0; i < lists.size(); i += 2)
            {
                if (i + 1 < lists.size())
                {
                    mergedLists.push_back(mergeLists(lists[i], lists[i + 1]));
                }
                else
                {
                    mergedLists.push_back(lists[i]);
                }
            }
            lists = mergedLists; 
        }

        return lists[0]; 
    }
};