#ifndef DIVIDE_TWO_INTEGERS_H
#define DIVIDE_TWO_INTEGERS_H

#include <iostream>
#include <limits.h>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        long dividend_ = dividend;
        long divisor_ = divisor;
        bool is_negative = (dividend ^ divisor) < 0;

        if (dividend < 0) {
            //dividend &= ~(1 << (sizeof(int)*8 - 1));
            dividend_ = abs(dividend);
        }
        if (divisor < 0) {
            //divisor &= ~(1 << (sizeof(int)*8 - 1));
            divisor_ = abs(divisor);
        }
        //cout << "divisor is:" << divisor << endl;
        long rez = 0;
        long sum = 0;
        while ((sum += divisor_) <= dividend_) {
            //sum += divisor;
            rez++;
        }
        if (!is_negative && rez >= INT_MAX) rez = INT_MAX;

        return is_negative ? -rez : rez;
    }
};
#endif // DIVIDE_TWO_INTEGERS_H
