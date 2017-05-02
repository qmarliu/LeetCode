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
                if((s.length() > 1) && (s.length()-1 > maxS.length()))
                    s = s.substr(1);
                else
                    break;
            }
            cout << maxS << endl;
            return maxS.length();
        }
};

int main( int argc, char **argv )
{
    string str{ "loddktdji" };
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
