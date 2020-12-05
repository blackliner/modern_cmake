
#include <addition/addition.h>

int main()
{
    const addition_types::SumType lhs{5};
    const addition_types::SumType rhs{7};

    const auto result = addition::add(lhs, rhs);
    return !(result == 12);
}