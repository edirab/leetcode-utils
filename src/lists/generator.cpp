#include "leetcode_utils/lists/ListNode_int.h"
#include "leetcode_utils/lists/generator.h"
#include "leetcode_utils//arrays/random_ints.h"

namespace leetcode_utils
{
namespace lists
{

using leetcode_utils::arrays::RandomGenerator;

ListNode* Generator::from_rand_ints(int n) {
    RandomGenerator rg(0, 20, 8);
    auto res = rg.unique_sorted_ints();

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
