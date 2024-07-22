#include <iostream>
#include <string>
#include <exception>

using std::string;
namespace leetcode_utils
{
namespace arrays
{

class IncorrectRangeException : public std::exception {
    public:
        IncorrectRangeException(int from, int to) {
            if (from >= to) {
                message = "Incorrect range: from(" + std::to_string(from) \
                + ") must be < then to(" + std::to_string(to) + ")!\n";
            }
        }

        const char* what() {
            return message.c_str();
        }

    private:
        string message{"Default initialization"};
};


class NotEnoughCapaciryException : public std::exception {
    public:
        NotEnoughCapaciryException(int from, int to, int nums) {
            if ( nums >  (to - from)  ) {
                message = "Not enought capacity: '" + 
                std::to_string(nums) + " > (" + std::to_string(to) + " - " + std::to_string(from) + ")' !\n";
            }
        }

        const char* what() {
            return message.c_str();
        }

    private:
        string message{"Default initialization"};
};


} // namespace arrays
} // namespace leetcode_utils
