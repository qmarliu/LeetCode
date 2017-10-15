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
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime:12ms
    string longestPalindrome(string s)
    {
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
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    //天码营上的答案，但效率没有我的高。
    string longestPalindrome2(string s)
    {
        // 字符串长度
        int n = s.length();
        // 维护最长的答案
        string ans = "";
        // 枚举对称点是一个字符的所有情况
        for (int i = 0; i < n; i++)
        {
            // 在满足对称的情况下不断拓展长度
            int l = i, r = i;
            while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1])
            {
                l--;
                r++;
            }
            // 与当前答案作比较
            if (r - l + 1 > ans.length())
            {
                ans = s.substr(l, r - l + 1);
            }
        }
        // 枚举对称点是两个字符中间的所有情况
        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
            {
                // 注意初值的改变
                int l = i, r = i + 1;
                while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1])
                {
                    l--; r ++;
          }
          if (r - l + 1 > ans.length()) {
              ans = s.substr(l, r - l + 1);
          }
      }
      // 返回答案
      return ans;
    }

    //LeetCode上提供的答案,效率更低
    string longestPalindrome3(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s.at(L) == s.at(R))
        {
            L--;
            R++;
        }
        return R - L - 1;
    }

    //LeetCode上最好的答案 3ms
    string longestPalindrome4(string s)
    {
        if (s.empty())
            return "";
        if (s.size() == 1)
            return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();)
        {
            if (s.size() - i <= max_len / 2)
                break;
            int j = i, k = i;
            while (k < s.size() - 1 && s[k + 1] == s[k])
                ++k; // Skip duplicate characters.
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
            {
                ++k;
                --j;
            } // Expand.
            int new_len = k - j + 1;
            if (new_len > max_len)
            {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << s.longestPalindrome4("babbaasldkfjeiofasfdlssldkjfladsjflkajfiewhgghewiooiwehg") << endl;
    cout << s.longestPalindrome4("ababad") << endl;
    cout << s.longestPalindrome4("ccc") << endl;
    return 0;
}