/*
 *Question
 ***************
 *Given a string, find the length of the longest substring without repeating characters.
 *
 *Examples:
 *
 *Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 *Given "bbbbb", the answer is "b", with the length of 1.
 *
 *Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
    public:
        /*
         *自己实现的，效率不太好
         */
        int lengthOfLongestSubstring(string s) {
            string maxS;
            string temp;

            if( s.length() <= 1) {
                return s.length();
            }

            while(1) {
                for(auto &c : s ) {
                    //检查是否有这个字符
                    if( temp.find_first_of( c ) == string::npos) {
                        temp.push_back( c );
                    }
                    else {
                        if( maxS.length() < temp.length() ) {
                            maxS = temp;
                        }
                        temp = "";
                        break;
                    }
                }
                if( maxS.length() < temp.length() ) {
                    maxS = temp;
                }
                temp = "";
                if ((s.length() > 1) && (s.length() - 1 > maxS.length()))
                    s = s.substr(1);
                else
                    break;
            }
            cout << maxS << endl;
            return maxS.length();
        }

        /*
         *Approach #2 Brute Force [Time Limit Exceeded]
         */
        bool allUnique(string s, int start, int end)
        {
            set<char> cs;
            for (int i = start; i < end; ++i)
            {
                char ch = s.at(i);
                if (cs.end() != cs.find(ch))
                    return false;
                cs.insert(cs.end(), ch);
            }
            return true;
        }

        int lengthOfLongestSubstring2(string s)
        {
            int n = s.length();
            int ans = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j <= n; ++j)
                {
                    if (allUnique(s, i, j))
                    {
                        ans = (ans > (j - i)) ? ans : j - i;
                    }
                }
            }
            return ans;
        }

        /*
         *Approach #3 Sliding Window [Accepted]
         */
        int lengthOfLongestSubstring3(string s)
        {
            int n = s.length();
            set<char> cs;
            int ans = 0, i = 0, j = 0;
            while (i < n && j < n)
            {
                if (cs.find(s.at(j)) == cs.end())
                {
                    cs.insert(cs.end(), s.at(j++));
                    ans = (ans > (j - i)) ? ans : j - i;
                }
                else
                {
                    cs.erase(s.at(i++));
                }
            }
            return ans;
        }

        /*
         *Approach #4 Sliding Window Optimized
         */
        int lengthOfLongestSubstring4(string s)
        {
            int n = s.length(), ans = 0;
            int index[256] = {0}; // current index of character
            // try to extend the range [i, j]
            for (int j = 0, i = 0; j < n; j++)
            {
                i = (index[static_cast<int>(s.at(j))] > i) ? index[static_cast<int>(s.at(j))] : i;
                ans = (ans > (j - i + 1)) ? ans : j - i + 1;
                index[static_cast<int>(s.at(j))] = j + 1;
            }
            return ans;
        }

        /*
         *看到的最好的答案
         */
        int lengthOfLongestSubstring5(string s)
        {
            vector<int> v(256, -1);
            int len = s.size(), ans = 0, start = -1;

            for (int i = 0; i < len; i++)
            {
                if (v[s[i]] > start) //Slding window
                    start = v[s[i]];
                v[s[i]] = i;
                ans = max(ans, i - start);
            }
            return ans;
        }
};

int main( int argc, char **argv )
{
    string str{ "abcabcbb" };
    Solution s;
    cout << s.lengthOfLongestSubstring3(str) << endl;
    return 0;
}
