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

struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto head : lists) {
            pq.push(head);
        }

        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            node = node->next;
            if(node) {
                pq.push(node);
            }
        }
        return res->next;
    }
};








