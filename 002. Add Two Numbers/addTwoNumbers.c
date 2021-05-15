/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* new_list_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* new_list = new_list_head;
    int carry = 0;
    
    while(l1 != NULL || l2 != NULL){
        int l1_val = 0, l2_val = 0;
        if(l1 != NULL)
            l1_val = l1->val;
        if(l2 != NULL)
            l2_val = l2->val;
        int temp = l1_val + l2_val + carry;
        carry = 0;
        if(temp >= 10){
            new_list->val = temp - 10;
            carry = 1;
        }
        else 
            new_list->val = temp;
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
        if(l1||l2){
            new_list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            new_list = new_list->next; 
        } 
    }
    if(carry){
        new_list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_list = new_list->next; 
        new_list->val = 1;
    }
    new_list->next = NULL;
    return new_list_head;
    
}