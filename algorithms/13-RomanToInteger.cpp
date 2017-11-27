/*
 *Description:
 ******************
 *Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
static string s = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();

class Solution {
public:
    //自己实现的，Runtime: 82 ms
    int romanToInt(string s) {
        string c[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}};
        int result = 0;
        for (int i=0; i<s.size(); )
        {
            //找最大的四个匹配
            if (i + 4 <= s.size())
            {
                string tmp_s = s.substr(i, 4);
                if (tmp_s == "VIII")
                {
                    return result + 8;
                }
                if (tmp_s == "LXXX")
                {
                    result += 80;
                    i = i + 4;
                }
                else if (tmp_s == "DCCC")
                {
                    result += 800;
                    i = i + 4;
                }
                else
                    goto match_3;
                continue;
            }
        match_3:
            //三个匹配
            if (i + 3 <= s.size())
            {
                string tmp_s = s.substr(i, 3);
                if (tmp_s == "III")
                {
                    return result + 3;
                }
                if (tmp_s == "VII")
                {
                    return result + 7;
                }

                if (tmp_s == "XXX")
                {
                    result += 30;
                    i = i + 3;
                }
                else if (tmp_s == "LXX")
                {
                    result += 70;
                    i = i + 3;
                }
                else if (tmp_s == "CCC")
                {
                    result += 300;
                    i = i + 3;
                }
                else if (tmp_s == "DCC")
                {
                    result += 700;
                    i = i + 3;
                }
                else if (tmp_s == "MMM")
                {
                    result += 3000;
                    i = i + 3;
                }
                else
                    goto match_2;
                continue;
            }
            
            //二个匹配的
        match_2:
            if (i + 2 <= s.size())
            {
                string tmp_s = s.substr(i, 2);
                if (tmp_s == "II")
                {
                    return result + 2;
                }
                if (tmp_s == "IV")
                {
                    return result + 4;
                }
                if (tmp_s == "VI")
                {
                    return result + 6;
                }
                if (tmp_s == "IX")
                {
                    return result + 9;
                }

                if (tmp_s == "XX")
                {
                    result += 20;
                    i = i + 2;
                }
                else if (tmp_s == "XL")
                {
                    result += 40;
                    i = i + 2;
                }
                else if (tmp_s == "LX")
                {
                    result += 60;
                    i = i + 2;
                }
                else if (tmp_s == "XC")
                {
                    result += 90;
                    i = i + 2;
                }
                else if (tmp_s == "CC")
                {
                    result += 200;
                    i = i + 2;
                }
                else if (tmp_s == "CD")
                {
                    result += 400;
                    i = i + 2;
                }
                else if (tmp_s == "DC")
                {
                    result += 600;
                    i = i + 2;
                }
                else if (tmp_s == "CM")
                {
                    result += 900;
                    i = i + 2;
                }
                else if (tmp_s == "MM")
                {
                    result += 2000;
                    i = i + 2;
                }
                else
                    goto match_1;
                continue;
            }
 
            //一个匹配的
        match_1:
            if (i + 1 <= s.size())
            {
                string tmp_s = s.substr(i, 1);
                if (tmp_s == "I")
                {
                    return result + 1;
                }
                if (tmp_s == "V")
                {
                    return result + 5;
                }

                if (tmp_s == "X")
                {
                    result += 10;
                    ++i;
                }
                else if (tmp_s == "L")
                {
                    result += 50;
                    ++i;
                }
                else if (tmp_s == "C")
                {
                    result += 100;
                    ++i;
                }
                else if (tmp_s == "D")
                {
                    result += 500;
                    ++i;
                }
                else if (tmp_s == "M")
                {
                    result += 1000;
                    ++i;
                }
            }
        }
        return result;
    }

    //leetCode上最好的回答 Runtime: 35ms
    int romanToInt2(string s) {
        std::unordered_map<char, int> numerals;
        numerals['I'] = 1, numerals['V'] = 5,
        numerals['X'] = 10, numerals['L'] = 50,
        numerals['C'] = 100, numerals['D'] = 500,
        numerals['M'] = 1000;
        
        int sum = 0;
        int previousValue = 0;
        int currentValue = 0;
        
        for(int i = 0; i < s.size(); ++i)
        {
            currentValue = numerals[s[i]];           
            sum += (currentValue > previousValue) ? (currentValue - 2*previousValue) : currentValue;
            previousValue = currentValue;
        }
        
        return sum;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.romanToInt("MMMDL") << endl;
    getchar();
    return 0;
}