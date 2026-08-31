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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head -> next == nullptr){
            return {-1,-1};
        }
        int x = 1;
        ListNode* i = head;
        ListNode* j = i -> next;
        bool flag = true;
        int minimum = INT_MAX, maximum = -1, first = -1, last = -1, currentMinIndex = 0;
        while(j -> next != nullptr){
            if( (j->val > i->val && j->val > j->next->val) || (j->val < i->val && j->val < j->next->val) )
            {
                if(flag){
                    first = x;
                    flag = false;
                }
                if(last != -1 && first != -1){
                    minimum = min(x - last , minimum);
                }
                last = x;
            }
            x++;
            i = j;
            j = j->next;
        }
        if(last == first){return {-1,-1};}
        maximum = last - first;
        return {minimum , maximum};
    }
};