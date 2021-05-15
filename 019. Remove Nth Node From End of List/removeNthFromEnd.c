/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int dealy = 0;
    int total_num = 0;
    struct ListNode* runner = head;
    struct ListNode* runner2 = head;
    
    for( int i = 0; runner != NULL; i++ ){
        runner = runner->next;
        if( i > n )
           runner2 = runner2->next;
        total_num++;
    }
    if(total_num < 2)
        return NULL;
    if(total_num == n)
        head = head->next;
    else
        runner2->next = runner2->next->next;
    return head;
}