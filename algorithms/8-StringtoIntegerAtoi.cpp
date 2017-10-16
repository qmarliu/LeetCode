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
    //自己实现的，Runtime: 29ms
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
                if (temp > 0 && ans == (temp - (str[j] - '0')) / 10)
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

    //LeetCode上最好的实现： Runtime: 6ms
    int myAtoi2(string str) {
        int result = 0;
        bool pos = true;
        bool signed_used = false;
        bool first_digit = false;
        
        for(int i = 0;i < str.size();i++){
            int temp = str[i] - '0';
                        
            if(temp > 9 || temp < 0){ //string contains char outside 0 to 9 range
                if(str[i] == '+' && !signed_used){
                    pos = true;
                    signed_used = true;
                }
                else if(str[i] == '-' && !signed_used){
                   signed_used = true;
                    pos = false;
                }
                else if(str[i] == ' ' && !signed_used && !first_digit) continue;
                else
                    break;
            }
            else{
                if(result > numeric_limits<int>::max()/10){
                    if(!pos)
                        return numeric_limits<int>::min();
                    else
                        return numeric_limits<int>::max();
                }
                result = result*10 + temp;
                first_digit = true;
            }
        }
        if(!pos){
            if(numeric_limits<int>::min() > -result || -result > 0) return numeric_limits<int>::min();
            else return -result;
        }
        else{
            if(numeric_limits<int>::max() < result || result < 0) return numeric_limits<int>::max();
            return result;
        }
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
    cout << s.myAtoi2("2147483648") << endl;
    cout << s.myAtoi2("-2147483649") << endl;
    cout << s.myAtoi2("      +0011   ") << endl;
    cout << s.myAtoi2("    10522545459") << endl;
    cout << s.myAtoi2("123abc") << endl;
    cout << s.myAtoi("-123abc") << endl;
    cout << s.myAtoi("-1.23abc") << endl;
    cout << s.myAtoi("------1.23abc") << endl;
    cout << s.myAtoi("abc") << endl;
    getchar();
    return 0;
}