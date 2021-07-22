#include "gtest/gtest.h"
#include "stringLib.hpp"

#include <string>

class StringLibTest : public ::testing::Test
{
    protected:
    StringLibTest() {};
    ~StringLibTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(StringLibTest, GivenStringWithSpacesAndExpectUnderscores)
{
    std::string expectedString = "_____";
    std::string result = utils::StringLib::spacesToUnderscoresRemoveNumbers("     ");
    EXPECT_TRUE(expectedString == result);
}
TEST_F(StringLibTest, GivenStringWithNumbersAndExpectEmptyString)
{   
    std::string expectedString = "";
    std::string result = utils::StringLib::spacesToUnderscoresRemoveNumbers("123456789");
    EXPECT_TRUE(expectedString == result);
}
TEST_F(StringLibTest, GivenStringWithSpacesAndNumbersAndExpectStringWithoutNumbersAndWithUnderscores)
{
   std::string expectedString = "Ala_ma__koty";
   std::string result = utils::StringLib::spacesToUnderscoresRemoveNumbers("Ala ma 4 koty");
   EXPECT_TRUE(expectedString == result);
}
TEST_F(StringLibTest, GivenStringWithSpecialCharacterAndExpectStringWithoutNumbersAndWithSpecialCharacter)
{
   std::string expectedString = "Ala_ma_@_koty";
   std::string result = utils::StringLib::spacesToUnderscoresRemoveNumbers("Ala ma @ koty");
   EXPECT_TRUE(expectedString == result);
}

TEST_F(StringLibTest, GivenTwoSameStringsAndExpectTrue)
{
   std::string string1 = "Ala_ma_4_koty";
   std::string string2 = "Ala_ma_4_koty";
   EXPECT_TRUE(utils::StringLib::sameStrings(string1, string2));
}
TEST_F(StringLibTest, GivenTwoDifferentStringsAndExpectFalse)
{
   std::string string1 = "Ala_ma_4_koty";
   std::string string2 = "Ala_ma_2_koty";
   EXPECT_FALSE(utils::StringLib::sameStrings(string1, string2));
}

TEST_F(StringLibTest, GivenTwoDifferentStringsAndExpectTheyAreTheSame)
{
    std::string string1 = utils::StringLib::spacesToUnderscoresRemoveNumbers("Ala ma 4 koty");
    std::string string2 = utils::StringLib::spacesToUnderscoresRemoveNumbers("Ala ma 2 koty");
    EXPECT_TRUE(utils::StringLib::sameStrings(string1, string2));
}

// WRONG!!
TEST_F(StringLibTest, GivenErrorCode4AndExpectedStringErrorCode4) 
{
    auto result = utils::StringLib::errorString(4);
    auto expectedString = "Error Code: 4" ;
    EXPECT_STREQ(result, expectedString);
}
