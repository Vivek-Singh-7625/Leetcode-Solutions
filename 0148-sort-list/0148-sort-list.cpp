/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        struct ListNode* p = head;
        while(p){
            p = p->next;
            n++;
        }
        vector<int> A(n);
        p = head;
        while(n--){
            A[n] = p->val;
            p = p->next;
        } 
        sort(A.begin(),A.end());
        p = head;
        while(p){
            p->val = A[++n];
            p = p->next;
        }
        return head;
    }
};