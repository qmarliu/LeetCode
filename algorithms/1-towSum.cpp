/*
 *Description:
 ******************
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 *Example:
 *******************
 *Given nums = [2, 7, 11, 15], target = 9,
 *
 *Because nums[0] + nums[1] = 2 + 7 = 9,
 *return [0, 1].
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        /*
         *Approach #1 (Brute Force) 
         */
        vector<int> towSum(vector<int>& nums, int target) {
            vector<int> retIv;
            for( vector<int>::size_type i = 0; i < nums.size() - 1; ++i) {
                for( auto j = i + 1; j < nums.size(); ++j) {
                    if( nums[i] + nums[j] == target) {
                        retIv = { static_cast<int>(i), static_cast<int>(j) };
                        return retIv;
                    }
                }
            }
            return retIv;
        }
};

int main( int argc, char **argv )
{
    Solution s;
    vector<int> nums{ 2,7,11,15 };
    int target = 17;
    vector<int> retNums = s.towSum(nums, target);
    if(retNums.size() > 1 ) {
        cout << "Because nums[" << retNums[0] << "] + nums[" << retNums[1] << "] = " << 
            nums[retNums[0]] << " + " << nums[retNums[1]] << " = " << target << endl;

    }
    return 0;
}
