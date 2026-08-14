/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
   struct ListNode *p = head , *l = head , *r = head, *f = head;
    if(!p) return NULL;
    int x = k;
    while(x){
        if(!p || k == 1) return p;
        p = p->next;
        r = r->next;
        x--;
    }

    while(!p || (l != p->next) ){
        if(l->next == p){
            swap(&l->val,&(f->val));
            p = l;
            l = f->next;
            f = f->next;
        }
        l = l->next;
    }
    reverseKGroup(r,k);

    return head;
}