#include "ListNode_int.h"
#include "../arrays/random_ints.h"

namespace leetcode_utils
{
namespace lists
{

using leetcode_utils::arrays::RandomGenerator;

class Generator {

public:

    ListNode* from_range();
    ListNode* from_rand_ints(int n);

};

} // lists
} // leetcode_utils
