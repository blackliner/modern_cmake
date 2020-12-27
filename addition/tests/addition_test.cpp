#include <catch2/catch.hpp>

#include <addition/addition.h>

SCENARIO("frist test")
{
    GIVEN("two values")
    {
        const addition_types::SumType lhs{5};
        const addition_types::SumType rhs{7};

        WHEN("addition is called")
        {
            const auto result = addition::add(lhs, rhs);
            THEN("the result has to be equal the sum of the two values")
            {
                REQUIRE(result == 12);
            }
        }
    }
}