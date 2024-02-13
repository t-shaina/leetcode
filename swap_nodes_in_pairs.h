#ifndef SWAP_NODES_IN_PAIRS_H
#define SWAP_NODES_IN_PAIRS_H
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* i = head;
        if (i == nullptr) return nullptr;
        if (i->next == nullptr) return head;
        int step = 0;
        ListNode* tmp = i;
        ListNode* previous = i;
        while (i->next != nullptr){
            if (step == 0) {
                head = i->next;
            }
            if (step % 2 == 0) {
                tmp = i->next->next;
                previous->next = i->next;
                if (tmp)
                    i->next->next = i;
                else {
                    previous->next->next = i;
                    i->next = nullptr;
                }
            }
            else {
                previous = i;
                i->next = tmp;
                i = i->next;
            }
            step++;
        }
        return head;
    }
};
#endif // SWAP_NODES_IN_PAIRS_H
