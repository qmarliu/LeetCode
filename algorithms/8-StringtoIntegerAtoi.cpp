/*
 *Description:
 ******************
 *Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

 *******************
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime: ms
    int myAtoi(string str) {
        if (str.size() == 0)
            return 0;
        int ans = 0;
        int flag = 1;
        int i = 0;
        while (str[i] == ' ' && i < str.size())
            ++i;
        if (str[i] == '-')
        {
            flag = -1;
            ++i;
        }
        else if (str[i] == '+')
        {
            ++i;
        }
        for (; i < str.size() && str[i] == '0'; ++i)
        {
        }

        for (int j = i; j < str.size(); ++j)
        {
            if (str[j] >= '0' && str[j] <='9')
            {
                int temp = ans * 10 + (str[j] - '0');
                if (temp > 0)
                {
                    ans = temp;
                }
                else if (flag == 1)
                {
                    ans = INT_MAX;
                    break;
                }
                else// if (flag == -1)
                {
                    ans = INT_MIN;
                    flag = 1;
                    break;
                }
            }
            else
                break;
        }
        return flag * ans;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << atoi("00123") << endl;
    cout << atoi("123abc") << endl;
    cout << atoi("-00000123abc") << endl;
    cout << atoi("-1.23abc") << endl;
    cout << atoi("-----1.23abc") << endl;
    cout << atoi("abc") << endl;
    cout << atoi("2147483647") << endl;

    cout << "-------------" << endl;
    // cout << s.myAtoi("+1") << endl;
    cout << s.myAtoi("2147483648") << endl;
    cout << s.myAtoi("-2147483649") << endl;
    cout << s.myAtoi("      +0011   ") << endl;
    cout << s.myAtoi("123") << endl;
    cout << s.myAtoi("123abc") << endl;
    cout << s.myAtoi("-123abc") << endl;
    cout << s.myAtoi("-1.23abc") << endl;
    cout << s.myAtoi("------1.23abc") << endl;
    cout << s.myAtoi("abc") << endl;
    getchar();
    return 0;
}