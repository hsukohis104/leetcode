/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head)
        return NULL;
    if(!head->next)
        return head;
    struct ListNode* run;
    struct ListNode* odd_head = head;
    struct ListNode* even_head = head->next;
    run = even_head->next;
    struct ListNode*odd_run = odd_head;
    struct ListNode*even_run = even_head;
    int count = 3;
    while( run != NULL ){
        if(count % 2 == 0){
            even_run->next = run;
            even_run = even_run->next;
        }
        else{
            odd_run->next = run;
            odd_run = odd_run->next;
        }
        count++;
        run = run->next;
    }
    even_run->next = NULL;
    odd_run->next = even_head;
    return odd_head;
}