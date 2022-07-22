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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> q;
        ListNode *t = new ListNode(0);
        ListNode *ans = t;
        while(head)
        {
            if(head->val < x)
            {
                t->next = head;
                t=t->next;
            }
            else
            {
                q.push(head);
            }
            head=head->next;
        }
        while(q.size())
        {
            t->next = q.front();
            t=t->next;
            q.pop();
        }
        t->next = NULL;
        return ans->next;
    }
};