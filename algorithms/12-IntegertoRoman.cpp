/*
 *Description:
 ******************
 *Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

tips
罗马数字共有7个，即Ⅰ（1）、Ⅴ（5）、Ⅹ（10）、Ⅼ（50）、Ⅽ（100）、Ⅾ（500）和Ⅿ（1000）。

重复数次：一个罗马数字重复几次，就表示这个数的几倍。
右加左减：
在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
但是，左减时不可跨越一个位值。比如，99不可以用IC（ {\displaystyle 100-1} 100-1）表示，而是用XCIX（ {\displaystyle [100-10]+[10-1]} [100-10]+[10-1]）表示。（等同于阿拉伯数字每位数字分别表示。）
左减数字必须为一位，比如8写成VIII，而非IIX。
右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
加线乘千：
在罗马数字的上方加上一条横线或者加上下标的Ⅿ，表示将这个数乘以1000，即是原数的1000倍。
同理，如果上方有两条横线，即是原数的1000000（ {\displaystyle 1000^{2}} 1000^{{2}}）倍。
数码限制：
同一数码最多只能连续出现三次，如40不可表示为XXXX，而要表示为XL。
例外：由于IV是古罗马神话主神朱庇特（即IVPITER，古罗马字母里没有J和U）的首字，因此有时用IIII代替IV。
 *******************
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime: 76ms
    string intToRoman(int num) {
        const char *c[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}};

        string roman;
        roman.append(c[3][num / 1000 % 10]);
        roman.append(c[2][num / 100 % 10]);
        roman.append(c[1][num / 10 % 10]);
        roman.append(c[0][num % 10]);
        return roman;
    }

    //leetCode上最好的回答 Runtime: 35ms
    string intToRoman(int num) {
        string result;
        int temp = num;
        if (temp == 0)
            return result;
        int thousand = temp / 1000;
        temp = temp % 1000;
        int hundred = temp / 100;
        temp = temp % 100;
        int ten = temp / 10;
        temp = temp % 10;
        int one = temp;
        for (int i = 0; i < thousand; i++) {
            result.push_back('M');
        }
        switch (hundred) {
            case 1:
                result.push_back('C');
                break;
            case 2:
                result.push_back('C');
                result.push_back('C');
                break;
            case 3:
                result.push_back('C');
                result.push_back('C');
                result.push_back('C');
                break;
            case 4:
                result.push_back('C');
                result.push_back('D');
                break;
            case 5:
                result.push_back('D');
                break;
            case 6:
                result.push_back('D');
                result.push_back('C');
                break;
            case 7:
                result.push_back('D');
                result.push_back('C');
                result.push_back('C');
                break;
            case 8:
                result.push_back('D');
                result.push_back('C');
                result.push_back('C');
                result.push_back('C');
                break;
            case 9:
                result.push_back('C');
                result.push_back('M');
                break;
            case 0:
                break;
            default:break;
        }
        switch (ten) {
            case 1:
                result.push_back('X');
                break;
            case 2:
                result.push_back('X');
                result.push_back('X');
                break;
            case 3:
                result.push_back('X');
                result.push_back('X');
                result.push_back('X');
                break;
            case 4:
                result.push_back('X');
                result.push_back('L');
                break;
            case 5:
                result.push_back('L');
                break;
            case 6:
                result.push_back('L');
                result.push_back('X');
                break;
            case 7:
                result.push_back('L');
                result.push_back('X');
                result.push_back('X');
                break;
            case 8:
                result.push_back('L');
                result.push_back('X');
                result.push_back('X');
                result.push_back('X');
                break;
            case 9:
                result.push_back('X');
                result.push_back('C');
                break;
            case 0:
                break;
            default:break;
        }
        switch (one) {
            case 1:
                result.push_back('I');
                break;
            case 2:
                result.push_back('I');
                result.push_back('I');
                break;
            case 3:
                result.push_back('I');
                result.push_back('I');
                result.push_back('I');
                break;
            case 4:
                result.push_back('I');
                result.push_back('V');
                break;
            case 5:
                result.push_back('V');
                break;
            case 6:
                result.push_back('V');
                result.push_back('I');
                break;
            case 7:
                result.push_back('V');
                result.push_back('I');
                result.push_back('I');
                break;
            case 8:
                result.push_back('V');
                result.push_back('I');
                result.push_back('I');
                result.push_back('I');
                break;
            case 9:
                result.push_back('I');
                result.push_back('X');
                break;
            case 0:
                break;
            default:break;
        }
        return result;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.intToRoman(60) << endl;
    // getchar();
    return 0;
}