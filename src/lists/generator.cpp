#include "leetcode_utils/lists/ListNode_int.h"
#include "leetcode_utils/lists/generator.h"
#include "leetcode_utils//arrays/random_ints.h"

namespace leetcode_utils
{
namespace lists
{

using leetcode_utils::arrays::RandomGenerator;

ListNode* Generator::from_rand_ints(int n) {
    int lower_bound = 0;
    int upper_bound = n;
    RandomGenerator rg{};
    auto res = rg.unique_sorted_ints(lower_bound, upper_bound, n);

    ListNode* head = new ListNode{};
    ListNode* curr = head;

    for (auto elem : res) {
        curr->val = elem;
        curr->next = new ListNode{};
        curr = curr->next;
    }
    return head;
}

} // lists
} // leetcode_utils
