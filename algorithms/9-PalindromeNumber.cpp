/*
 *Description:
 ******************
 *Determine whether an integer is a palindrome. Do this without extra space.

 *******************
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    //自己实现的，Runtime: 148ms
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        //取出x中每位的值，并存储到queue中
        deque<int> iq;
        while (x != 0)
        {
            int min = x % 10;
            x = x / 10;
            iq.push_back(min);
       }
       while(iq.size() > 1)
       {
           if (iq.front() != iq.back())
               return false;
            iq.pop_front();
            iq.pop_back();
       }
       return true;
    }

    //leetcode上最好的回答： 62ms
    bool isPalindrome2(int x) {
        if(x<0||(x%10==0&&x!=0))
            return false;
        if(x<10)
            return true;
        int n = x;
        int rem, sum=0;
        while(n>sum){
            rem = n%10;
            sum = sum*10+rem;
            n /= 10;
        }
        return n==sum || n==(sum/10);
    }
};

int main( int argc, char **argv )
{
    Solution s;
    cout << (s.isPalindrome(-2147447412) ? " is Palindrome." : " not Palindrome.") << endl;
    cout << (s.isPalindrome(123) ? " is Palindrome." : " not Palindrome.") << endl;
    cout << (s.isPalindrome(121) ? " is Palindrome." : " not Palindrome.") << endl;
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = a;
    for(auto i : b)
    {
        cout << i << endl;
    }
    getchar();
    return 0;
}