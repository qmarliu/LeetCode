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
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        /*
         *Approach #1 (Brute Force) 
         */
        vector<int> twoSum(vector<int>& nums, int target) {
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

        /*
         *Approach #2 (Two-pass Hash Table)
         */
        vector<int> twoSum2(vector<int>& nums, int target) {
            map<int, int> im;
            for( int i = 0; i < nums.size(); ++i) {
                im[nums[i]] = i;
            }

            vector<int> retIv;
            for(int i=0; i< nums.size(); ++i) {
                int complement = target - nums[i];
                auto it = im.find(complement);
                if( it != im.end()) {
                    retIv = { i, im[complement] };
                    return retIv;
                }
            }
            return retIv;
        }

        /*
         *Approach #3(One-pass Hash Table)
         */
        vector<int> twoSum3(vector<int> &nums, int target) {
            vector<int> retIv;
            map<int, int> im;
            for(int i=0; i<nums.size(); ++i) {
                int complement = target - nums[i];
                if( im.find(complement) != im.end()) {
                    retIv = { i, im[complement] };
                    return retIv;
                }
                im[nums[i]] = i;
            }
            return retIv;
        }
        /*
         *Approach #4(LeetCode上实现的最好方案)
         */
        vector<int> twoSum4(vector<int> &nums, int target) {
            vector<int>::iterator it, start = nums.begin(), it_rem;
            map<int, int> m;
            vector<int> result;

            for( it = nums.begin(); it!=nums.end(); ++it) {
                int num=*it;
                int rem = target - num;

                if(m[rem] == 1) {
                    it_rem = find(nums.begin(), nums.end(), rem);
                    result.push_back(it_rem - start);
                    result.push_back(it - start);
                    return result;
                } else {
                    m[num] = 1;
                }
            }
            return result;
        }
};

int main( int argc, char **argv )
{
    Solution s;
    vector<int> nums{ 2,7,11,15 };
    int target = 17;
    vector<int> retNums = s.twoSum4(nums, target);
    if(retNums.size() > 1 ) {
        cout << "Because nums[" << retNums[0] << "] + nums[" << retNums[1] << "] = " << 
            nums[retNums[0]] << " + " << nums[retNums[1]] << " = " << target << endl;

    }
    return 0;
}
