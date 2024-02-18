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
//#include "combination_sum_two.h"
#include "multiply_strings.h"

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

    std::vector<int> v ({10,1,2,7,6,1,5});
    std::string num1 = "123";
    std::string num2 = "456";
    //std::vector<vector<int>> rez = s.multiply(num1, num2)

    std::cout << "rez is "<< s.multiply(num1, num2)<<  std::endl;
    return 0;
}
