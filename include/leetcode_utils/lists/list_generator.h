#pragma once

#include "ListNode_int.h"
#include "leetcode_utils/leetcode_utils.h"

namespace leetcode_utils
{
namespace lists
{

using leetcode_utils::arrays::RandomGenerator;

void print(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "\n";
    return;
}

class ListGenerator {

public:

    ListNode* from_vector(vector<int>& nums);
    ListNode* from_ints(int from, int to, int n);
    ListNode* from_unique_ints(int from, int to, int n);
    ListNode* from_unique_sorted_ints(int from, int to, int n);

    ListNode* clone(ListNode* l1);
    vector<int> to_vector(ListNode* l1);

};

} // namespace lists
} // namespace leetcode_utils
