#ifndef REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include <iostream>
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
      ListNode* removeNthFromEnd(ListNode* head, int n) {
          vector<ListNode*> previous_ptr;

          ListNode* i = head;
          previous_ptr.push_back(nullptr);
          previous_ptr.push_back(i);
          if (i->next == nullptr) return nullptr;
          int size = 3;
          while (i->next != nullptr){
              previous_ptr.push_back(i->next);
              i = i->next;
              ++size;
          }
          previous_ptr.push_back(nullptr);
          ListNode* src = previous_ptr.at(size - n);
          ListNode* dist = previous_ptr.at(size - n - 2);
          if (dist == nullptr){
              head = src;
          }
          else dist->next = src;
          return head;
      }
};
#endif // REMOVE_NTH_NODE_FROM_END_OF_LIST_H
