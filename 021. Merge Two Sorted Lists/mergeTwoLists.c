/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* newnest;
    if( l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    if(l1->val < l2->val){
        newnest = l1;
        l1 = l1->next;
    }
    else{
        newnest = l2;
        l2 = l2->next;
    }
    struct ListNode * run = newnest;
    while( l1 != NULL && l2 != NULL){
        if( l1->val < l2->val){
            run->next = l1;
            l1 = l1->next;
        }
        else{
            run->next = l2;
            l2 = l2->next;
        }
        run = run->next;
    }
    if(l1 != NULL)
        run->next = l1;
    else
        run->next = l2;
    return newnest;
}