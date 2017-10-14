/*
 *Description:
 ******************
 *Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *******************
 Example:

    Input: "babad"

    Output: "bab"

    Note: "aba" is also a valid answer.
 Example:

    Input: "cbbd"

    Output: "bb"
 */

 #include <iostream>
 #include <string>
 using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        int state = 0; //二种状态， 0是偶数回文，1是奇数回文
        string longestP;
        const int mid = s.size() / 2 - 1;
        int curMid = mid;
        int left = mid, right = mid + 1;
        int len = right - left + 1;

        //从字符串中间开始判断是否为回文,如果不是再向两边移动
        int lIndex = 0;
        int rIndex = 0;
        while (1)
        {
            len = right - left + 1;
            if (isPalindromic(s.substr(left, len)))
            {
                if (len > longestP.size())
                {
                    longestP = s.substr(left, len);
                }
                if (left > 0 && right < (s.size() - 1))
                {
                    --left;
                    ++right;
                    continue;
                }
            }

            if (state == 0)
            {
                state = 1;
                left = curMid - longestP.size() / 2;
                right = curMid + longestP.size() / 2;
                if (left > 0 && right < s.size())
                    continue;
            }
            state = 0;

            //左移
            curMid = mid - lIndex;
            if (curMid > 0 && longestP.size() < curMid * 2)
            {
                ++lIndex;
                curMid = mid - lIndex;
                left = curMid - (longestP.size() / 2);
                right = curMid + 1 + (longestP.size() / 2);
                if (left < 0)
                {
                    left = 0;
                }
                continue;
            }

            //右移
            curMid = mid + rIndex;
            if (curMid < s.size() && longestP.size() < (s.size() - (curMid + 1)) * 2)
            {
                rIndex++;
                curMid = mid + rIndex;
                left = curMid - (longestP.size() / 2);
                right = curMid + 1 + (longestP.size() / 2);
                continue;
            }
            break;
        }
        return longestP;
    }

    bool isPalindromic(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.longestPalindrome("babbaasldkfjeiofasfdlssldkjfladsjflkajfiewhgghewiooiwehg") << endl;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("ccc") << endl;
    return 0;
}