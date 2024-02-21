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
//#include "multiply_strings.h"
//#include "jump_game_two.h"
//#include "minimum_moves_to_capture_the_queen.h"
#include "maximum_square_area_by_removing_fences_from_a_field.h"

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

    //std::vector<int> v ({5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5});

    //std::vector<vector<int>> rez = s.multiply(num1, num2)
    std::vector<int> h {2};
    std::vector<int> v {2, 3};
    //std::cout << "rez is "<< s.maximizeSquareArea(4, 4, h, v)<<  std::endl;
    int x = 5;
    int* ptr = &x;
    std::cout << &x<<  std::endl;
    std::cout << ptr +1 <<  std::endl;
    return 0;
}
