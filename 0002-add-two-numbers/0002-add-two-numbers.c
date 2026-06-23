/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
   struct ListNode *head , *p = l1 , *q = l2 , *t , *l ; // *l = head; initializes the garbage value so there will be errors
  
   int c = 0 , d = 0; 
   
   while(p || q || c){
       if(d == 0){
            head = malloc(sizeof(struct ListNode));
            l = head;
            head->next = NULL;
            d++;
       }
       else{
            t = malloc(sizeof(struct ListNode));
            l->next = t;
            l = t;
            t->next = NULL;
       }

       l->val = (p? p->val : 0) + (q? q->val : 0) + c;

       p = (p? p->next : NULL);
       q = (q? q->next : NULL);
       c = 0;

       if(l->val > 9){
           l->val = l->val % 10;
           c = 1;
       }
   }
   return head;
}