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

        if (head == nullptr || head->next == nullptr) {
            return false; 
        }
        ListNode *temp = head, *a = temp, *b = temp->next;
        while(b!=nullptr && b->next!=nullptr)
        {
            a = a->next;
            b = b->next->next;

            if(a == b)
                return true;
        }
        return false;
    }
};