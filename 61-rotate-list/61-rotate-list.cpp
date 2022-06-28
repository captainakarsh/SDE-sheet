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
    ListNode* rotateRight(ListNode* head, int k) {
              if (!head or !(head->next)) {
            return head;
        }
        ListNode* it = head;
        int len = 1;
        while (it->next) {
            it = it->next;
            len=len+1;
        }
        it->next = head;
        it = head;
        
        for(int i = 1; i < len - (k % len); ++i)
            it = it->next;
        
        head = it->next;
        it->next = NULL;
        return head;
    }
};