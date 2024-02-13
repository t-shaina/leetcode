#ifndef ADD_TWO_NUMBERS_H
#define ADD_TWO_NUMBERS_H


 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        //int number_of_units = sum % 10;
        int number_of_tens = 0;
        ListNode* rez = new ListNode();
        ListNode* previous = new ListNode();
        ListNode* rez_iter =  rez;
        ListNode* l1_iter =  l1;
        ListNode* l2_iter =  l2;
        while (!(l1_iter == nullptr && l2_iter == nullptr)){
            if (l1_iter == nullptr && l2_iter != nullptr){
                sum = l2_iter->val;
                l2_iter = l2_iter->next;
            }
            else if (l1_iter != nullptr && l2_iter == nullptr){
                sum = l1_iter->val;
                l1_iter = l1_iter->next;
            }
            else{
                sum = l1_iter->val + l2_iter->val;
                l1_iter = l1_iter->next;
                l2_iter = l2_iter->next;
            }
            int inner_sum = sum + number_of_tens;
            int inner_number_of_units = inner_sum % 10;
            ListNode* next = new ListNode();
            previous = rez_iter;
            rez_iter->val = inner_number_of_units;
            rez_iter->next = next;
            number_of_tens = inner_sum / 10;

            rez_iter = next;
        }
        if (number_of_tens > 0){
            ListNode* final = new ListNode(number_of_tens, nullptr);
            previous->next = final;
        }
        else previous->next = nullptr;
        return rez;
    }
};
#endif // ADD_TWO_NUMBERS_H
