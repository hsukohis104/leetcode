/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if( head == NULL || head->next == NULL || head->next->next == NULL)
        return false;
    struct ListNode * current = head->next;
    struct ListNode * current2 = head->next->next;
    while(current2){
        if(current == current2)
            return true;
        if( current2->next == NULL)
            return false;
        current = current ->next;
        current2 = current2->next->next;
    }
    return false;
}