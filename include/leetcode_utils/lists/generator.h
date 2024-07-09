#include "ListNode_int.h"
#include "../arrays/random_ints.h"

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

class Generator {

public:

    ListNode* from_range();
    ListNode* from_rand_ints(int n);

};

} // lists
} // leetcode_utils
