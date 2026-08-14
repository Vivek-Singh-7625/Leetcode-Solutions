/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *p = head, *q = head;
    int i = 0;
    if (!head || !head->next || k == 0) return head;
    int length = 1;
    while (p->next) {
        p = p->next;
        length++;
    }
    p->next = head;
    k = k % length;
    int steps = length - k;
    while (steps--) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}
