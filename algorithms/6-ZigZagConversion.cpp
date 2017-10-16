/*
 *Description:
 ******************
 *The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 *******************
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime: 29ms
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        string ans;
        int sLen = s.size();
        int interval = (numRows - 1) * 2;
        int group = sLen / interval;
        //循环遍历每行
        for (int row = 0; row < numRows; ++row)
        {
            // 循环遍历每组
            for (int cnt = 0; cnt < group; ++cnt)
            {
                int subIndex = cnt * interval + row;
                ans.push_back(s[subIndex]);
                if (row != 0 && row != (numRows - 1))
                { //中间行
                    subIndex += (numRows - 1 - row) * 2;
                    ans.push_back(s[subIndex]);
                }
            }

            //最后一组
            if (sLen % interval > 0)
            {
                int subIndex = group * interval + row;
                if (subIndex < sLen)
                    ans.push_back(s[subIndex]);
                if (row != 0 && row != (numRows - 1))
                { //中间行
                    subIndex += (numRows - 1 - row) * 2;
                    if (subIndex < sLen)
                        ans.push_back(s[subIndex]);
                }
            }
        }
        return ans;
    }

    //leetcode上最好的答案 Runtime: 12ms
    string convert2(string s, int numRows) {
        int n = s.size();
        if (n <= 1 || numRows <= 1) {
            return s;
        }
        
        string result(n, 'c');
        int periodic = (numRows - 1) << 1;
        
        int k = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += periodic) {
                result[k++] = s[j];
                if (i > 0 && i < numRows - 1) {
                    int partner = j + periodic - 2 * i;
                    if (partner < n) {
                        result[k++] = s[partner];
                    }
                }
            }
        }
        return result;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    getchar();
    return 0;
}