#include <QCoreApplication>
#include <iostream>
//#include "atoi.h"
//#include "3sum.h"
//#include "3sum_closest.h"
//#include "4sum.h"
//#include "letter_combinations_of_a_string_number.h
//#include "swap_nodes_in_pairs.h"
//#include "divide_two_integers.h"
#include "next_permutation.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Solution s;
    /*ListNode* first = new ListNode(1);
    ListNode* begin = first;
    for (auto i = 1; i != 4; i++){
        ListNode* current = new ListNode(i + 1);
        begin->next = current;
        begin = current;
        if (i == 3) current->next = nullptr;
    }
    ListNode* head = s.swapPairs(first);
    while (head->next != nullptr) {
        std::cout << head->val;
        head = head->next;

    }*/
    std::vector v = {1,1,5};
    s.nextPermutation(v);
    for (auto i = v.begin(); i != v.end(); ++i){
        std::cout << *i ;
    }
    std::cout << std::endl;
    return 0;
}