/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      
    struct ListNode *last , *p = head , *prev;

    int count = 0;
    while(p){
        p = p->next;
        last = p;
        count++;
    }
    p = head;
    if(count == n){
        head = p->next;
        p->next = NULL;
        free(p);
        return head;
    }
    while(count != n){
        prev = p;
        p = p->next;
        count--;
    }

    prev->next = p->next;
    p->next = NULL;
    free(p);

    return head;
}
