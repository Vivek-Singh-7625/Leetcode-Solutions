/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)   return head;
        Node *p , *q , *r;
        p = head;
        while(p){
            if(p->child){
                q = p;
                r = p->child;
                flatten(p->child);
                while(r->next)  r = r->next;
                r->next = q->next;
                if(q->next) q->next->prev = r;
                q->next = q->child;
                q->child->prev = q;
                q->child = NULL;
            }
            p = p->next;
        }
        return head;
    }
};