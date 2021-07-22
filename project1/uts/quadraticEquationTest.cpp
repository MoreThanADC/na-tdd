#include "quadraticEquation.hpp"
#include "gtest/gtest.h"

// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md <- here you can find how to properly handle floating point numbers in EXPECTs and ASSERTs

class QuadraticEquationTest : public ::testing::Test
{
    protected:
    QuadraticEquationTest() {};
    ~QuadraticEquationTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};

// (x-3)(x+3)
TEST_F(QuadraticEquationTest, GivenEquationWithTwoQuadraticRoots)
{
    std::pair<unsigned, std::pair<float, float>> expectetResult {2, {-3,3}};
    EXPECT_EQ(expectetResult, utils::quadraticEquation(1,0,-9));
    
}

// (x+3)^2
TEST_F(QuadraticEquationTest, lalala)
{
    float expectedNumberOfRoots {1};
    float expectedRoot {3};
    auto result = utils::quadraticEquation(1,-6,9);

    EXPECT_EQ(expectedNumberOfRoots, result.first);
    EXPECT_EQ(expectedRoot, result.second.first);
}

TEST_F(QuadraticEquationTest, change_this_name3)
{

}