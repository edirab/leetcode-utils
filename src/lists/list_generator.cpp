#include "leetcode_utils/lists/ListNode_int.h"
#include "leetcode_utils/lists/list_generator.h"
#include "leetcode_utils//arrays/random_ints.h"

namespace leetcode_utils
{
namespace lists
{

using leetcode_utils::arrays::RandomGenerator;

ListNode* ListGenerator::from_vector(vector<int>& nums) 
{
    if (nums.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode{nums.at(0)};
    ListNode* prev = head;

    for (int i = 1; i < nums.size(); i++) 
    {
        ListNode* curr = new ListNode{nums.at(i)};
        prev->next = curr;
        prev = prev->next;
    }
    return head;
}

ListNode* ListGenerator::from_ints(int from, int to, int n)
{
    RandomGenerator rg{};
    auto res = rg.ints(from, to, n);

    ListNode* head = from_vector(res);
    return head;
}

ListNode* ListGenerator::from_unique_ints(int from, int to, int n)
{
    RandomGenerator rg{};
    auto res = rg.unique_ints(from, to, n);

    ListNode* head = from_vector(res);
    return head;
}

ListNode* ListGenerator::from_unique_sorted_ints(int from, int to, int n)
{
    RandomGenerator rg{};
    auto res = rg.unique_sorted_ints(from, to, n);

    ListNode* head = from_vector(res);
    return head;
}

ListNode* ListGenerator::clone(ListNode* l1) 
{
    if (l1 == nullptr) {
        return nullptr;
    }

    ListNode* head_new = new ListNode{l1->val};
    ListNode* curr = head_new;
    l1 = l1->next;

    while (l1 != nullptr) {
        curr->next = new ListNode{l1->val};
        curr = curr->next;
        l1 = l1->next;
    }

    return head_new;
}

vector<int> ListGenerator::to_vector(ListNode* l1) 
{
    vector<int> res;
    ListNode* curr = l1;

    while (curr != nullptr) {
        res.push_back(curr->val);
        curr = curr->next;
    }
    return res;
}

} // namespace lists
} // namespace leetcode_utils
