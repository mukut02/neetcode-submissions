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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* p1=list1, *p2 = list2;
        if(!p1) return p2;
        if(!p2) return p1;
        if(!p1 && !p2) return p1;
        ListNode* ans = nullptr;
        ListNode* ansHead = nullptr;
        while(p1 && p2){
            if(p1->val > p2->val){
                if(!ansHead) {
                    ansHead=p2;
                    ans=p2;
                }
                else{
                    ans->next=p2;
                    ans=ans->next;
                }
                p2=p2->next;
            }
            else{
               if(!ansHead) {
                    ansHead=p1;
                    ans=p1;
                }
                else{
                    ans->next=p1;
                    ans=ans->next;
                }
                p1=p1->next; 
            }
        }
        while(p1){
            ans->next=p1;
            ans=ans->next;
            p1=p1->next;
        }
        while(p2){
            ans->next=p2;
            ans=ans->next;
            p2=p2->next;
        }
        return ansHead;
    }
};
