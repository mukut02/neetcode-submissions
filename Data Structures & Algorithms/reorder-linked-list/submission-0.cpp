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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* p =head;
        while(p){
            v.push_back(p->val);
            p=p->next;
        }
        int n=v.size();
        int i=0,j=n-1;
        p=head;
        while(p){
            p->val = v[i++];
            p=p->next;
            if(!p) break;
            p->val=v[j--];
            p=p->next;
        }
        
    }
};
