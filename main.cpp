#include <QCoreApplication>
#include <iostream>
//#include "atoi.h"
//#include "3sum.h"
//#include "3sum_closest.h"
//#include "4sum.h"
//#include "letter_combinations_of_a_string_number.h
//#include "swap_nodes_in_pairs.h"
//#include "divide_two_integers.h"
//#include "next_permutation.h"
//#include "find_first_and_last_position_of_element_in_sorted_array.h"
//#include "valid_sudoku.h"
//#include "count_and_say.h"
//#include "combination_sum.h"
#include "combination_sum_two.h"

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

    std::vector<int> v ({2,5,2,1,2});
    std::vector<vector<int>> rez = s.combinationSum2(v, 5);
    for (auto i = rez.begin(); i != rez.end(); ++i){
        for (auto j = i->begin(); j != i->end(); j++)
            std::cout << *j;
        std::cout << endl;
    }

    std::cout <<  std::endl;
    return 0;
}
