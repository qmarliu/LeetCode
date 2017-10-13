/*
 *Question
 ****************
 *You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 *You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *****************
 *Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *Output: 7 -> 0 -> 8
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    /*
     *自己写的解决方案
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *curr = l3;
        int carry = 0;
        
        while(l1 || l2) {
            int x = ((l1==NULL) ? 0 : l1->val);
            int y = ((l2==NULL) ? 0 : l2->val);
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) {
            curr->next = new ListNode(1);
        }
        curr = l3->next;
        delete(l3);
        return curr;
    }

    /*
     *LeetCode中给出的最好解决方案
     */
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        if (!l1)	return l2;
        if (!l2)	return l1;
        ListNode *_l1 = l1;
        ListNode *_l2 = l2;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = _l2;
        ListNode *last = NULL;
        int tmp = 0;
        while (_l1 && _l2) {

            tmp += _l1->val + _l2->val;
            _l2->val = tmp % 10;
            tmp /= 10;

            last = _l2;
            _l1 = _l1->next;
            _l2 = _l2->next;

        }
        if (_l1)
            last->next = _l1,
                _l2 = _l1;
        while (tmp && _l2) {
            tmp += _l2->val;
            _l2->val = tmp % 10;
            tmp /= 10;
            last = _l2;
            _l2 = _l2->next;
        }
        if (tmp) {
            last->next = new ListNode(tmp);
        }

        return dummy->next; 
    }
};



int main( int argc, char **argv )
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    l1->next = new ListNode(8);
    /*
     *l1->next->next = new ListNode(3);
     *l2->next = new ListNode(6);
     *l2->next->next = new ListNode(4);
     */

    Solution s;
    ListNode *result = s.addTwoNumbers2(l1, l2);
    while(result) {
        cout << result->val << endl;
        result = result->next;
    }
}
    













