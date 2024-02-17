#ifndef VALID_SUDOKU_H
#define VALID_SUDOKU_H
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row_to_check_by_sub_boxes = 0;
        for (auto i = board.cbegin(); i != board.cend(); i++){
            vector<char> current_row;

            int column_to_check_by_columns = 0;
            for (auto j = i->cbegin(); j != i->cend(); j++){
                if (i == board.cbegin()){
                    vector<char> current_column;
                    for (int row_to_check_by_columns = 0; row_to_check_by_columns < 9; row_to_check_by_columns++){
                       if(board.at(row_to_check_by_columns).at(column_to_check_by_columns) != '.'){
                            if ( is_repeat(board.at(row_to_check_by_columns).at(column_to_check_by_columns), current_column)) return false;
                             current_column.push_back(board.at(row_to_check_by_columns).at(column_to_check_by_columns));
                        }
                    }
                }
                if(*j != '.'){
                    if ( is_repeat(*j, current_row)) return false;
                    current_row.push_back(*j);
                }
                if (column_to_check_by_columns % 3 == 0 && row_to_check_by_sub_boxes % 3 == 0){
                    vector<char> current_sub_box;
                    for (int v_element = row_to_check_by_sub_boxes; v_element < row_to_check_by_sub_boxes + 3; v_element++)
                        for (int hz_elemen = column_to_check_by_columns; hz_elemen < column_to_check_by_columns + 3; hz_elemen++){
                             if(board.at(v_element).at(hz_elemen) != '.'){
                                 if (is_repeat(board.at(v_element).at(hz_elemen), current_sub_box)) return false;
                                current_sub_box.push_back(board.at(v_element).at(hz_elemen));
                            }
                        }
                }
                column_to_check_by_columns++;
            }
            row_to_check_by_sub_boxes++;
        }
        return true;
    }
    bool is_repeat(char sample, vector<char>& data){
        for (auto k = data.cbegin(); k != data.cend(); k++){
            if (*k == sample) return true;
        }
        return false;
    }
};
#endif // VALID_SUDOKU_H
