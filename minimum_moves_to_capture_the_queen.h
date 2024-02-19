#ifndef MINIMUM_MOVES_TO_CAPTURE_THE_QUEEN_H
#define MINIMUM_MOVES_TO_CAPTURE_THE_QUEEN_H
#include <iostream>
using namespace std;

class Figure {
public:
    int vertical_;
    int horizontal_;
    Figure(int v, int h): vertical_(v), horizontal_(h) {}
    bool is_white(){
        if (vertical_ == horizontal_) return true;
        if (vertical_ % 2 == 0){
            if (horizontal_ % 2 == 0) return true;
            else return false;
        }
        else {
            if (horizontal_ % 2 == 0) return false;
            else return true;
        }
    }
    bool is_on_same_line (const Figure& second)const{
        if (vertical_ == second.vertical_ || horizontal_ == second.horizontal_) return true;
        else return false;
    }
};
class Rook;
class Bishop : public Figure {
public:
    Bishop(int v, int h): Figure(v, h) {}
    bool is_on_same_diagonal (const Figure& second) const{
        if (vertical_ - second.vertical_ == horizontal_ - second.horizontal_) return true;
        if (vertical_ - second.vertical_ == second.horizontal_ - horizontal_) return true;
        else return false;
    }
    bool is_on_same_line_between (const Figure& queen, const Rook& rook) const;

};
class Rook : public Figure {
public:
    Rook(int v, int h): Figure(v, h) {}
    bool is_on_same_diagonal (const Figure& second) const{
        if (vertical_ - second.vertical_ == horizontal_ - second.horizontal_) return true;
        if (vertical_ - second.vertical_ == second.horizontal_ - horizontal_) return true;
        else return false;
    }
    bool is_on_same_diagonal_between (const Figure& queen, const Bishop& bishop) const{
        if (this->is_on_same_diagonal(queen) && this->is_on_same_diagonal(bishop)) {
            if (horizontal_ <= queen.horizontal_ && horizontal_ <= bishop.horizontal_) return false;
            if (horizontal_ >= queen.horizontal_ && horizontal_ >= bishop.horizontal_) return false;
            if (vertical_ <=queen.vertical_ && vertical_ <= bishop.vertical_) return false;
            if (vertical_ >= queen.vertical_ && vertical_ >= bishop.vertical_) return false;
             else return true;
        }
        else return false;
    }
};
bool Bishop::is_on_same_line_between (const Figure& queen, const Rook& rook) const{
    if (rook.is_on_same_line(queen) && this->is_on_same_line(rook)) {
        if (horizontal_ < queen.horizontal_ && horizontal_ < rook.horizontal_) return false;
        if (horizontal_ > queen.horizontal_ && horizontal_ > rook.horizontal_) return false;
        if (vertical_ < queen.vertical_ && vertical_ < rook.vertical_) return false;
        if (vertical_ > queen.vertical_ && vertical_ > rook.vertical_) return false;
        else return true;
    }
    else return true;
}
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int min_moves = 2;
        Figure queen(e, f);
        Rook rook(a, b);
        Bishop bishop(c, d);
        if (rook.is_on_same_line(queen)){
            if (! rook.is_on_same_line(bishop)) { cout << "1" << endl; return 1;}
            else if (!bishop.is_on_same_line_between(queen, rook)) { cout << "2" << endl; return 1;}
            else { cout << "3" << endl; return 2;}
        }
        if (queen.is_white() == bishop.is_white()){
            if (bishop.is_on_same_diagonal(queen)){
                if (!bishop.is_on_same_diagonal(rook)){ cout << "4" << endl; return 1;}
                else if (!rook.is_on_same_diagonal_between(queen, bishop)) { cout << "5" << endl; return 1;}
                else { cout << "6" << endl; return 2;}
            }
            { cout << "7" << endl; return 2;}
        }
        return 2;
    }
};
#endif // MINIMUM_MOVES_TO_CAPTURE_THE_QUEEN_H
