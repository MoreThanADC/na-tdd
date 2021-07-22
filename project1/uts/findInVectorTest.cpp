#include "gtest/gtest.h"
#include "findInVector.hpp"

class FindInVectorTest : public ::testing::Test
{
    protected:
    FindInVectorTest() {};
    ~FindInVectorTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(FindInVectorTest, GivenVectorOfItemsThatContainSearchingNumberReturnsCorrectPositionOnItem)
{
    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(3, utils::findInVector(vec,3));
}

TEST_F(FindInVectorTest, WhenNotFindItemInVectorExpectReturnNULL)
{
    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(NULL, utils::findInVector(vec,11));
}

TEST_F(FindInVectorTest, GivenEmptyVectorAndExpectNULL)
{
    std::vector<int> vec = {};
    EXPECT_EQ(NULL, utils::findInVector(vec,0));
}

TEST_F(FindInVectorTest, GivenVectorOfItemsAndDoSth)
{
    std::vector<int> vec = {3,5,8};
    EXPECT_EQ(0, utils::findInVector(vec,3));
}
// WRONG!!
TEST_F(FindInVectorTest, GivenVectorOfTheSameValuesAndExpectReturnFirstPosition)
{
    std::vector<int> vec = {3,3,3,3,3,3,3,3};
    EXPECT_EQ(0, utils::findInVector(vec,3));
}