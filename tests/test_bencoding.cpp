#include <gtest/gtest.h>
#include "bencoding.h"

class BencodeParserTest : public ::testing::Test 
{
};

TEST_F(BencodeParserTest, ParseStringTest) {
    Bencoding::BencodeParser parser;
    std::string input = "5:hello";
    std::string expected_output = "hello";
    std::istringstream iss(input);
    parser.setInput(iss);
    std::string output = parser.parseString();
    EXPECT_EQ(output, expected_output);
}

TEST_F(BencodeParserTest, ParseStringEmptyInputTest) {
    Bencoding::BencodeParser parser;
    std::string input = "0:";
    std::string expected_output = "";
    std::istringstream iss(input);
    parser.setInput(iss);
    std::string output = parser.parseString();
    EXPECT_EQ(output, expected_output);
}

TEST_F(BencodeParserTest, ParseStringInvalidInputTest) {
    Bencoding::BencodeParser parser;
    std::string input = "5hello";
    std::istringstream iss(input);
    parser.setInput(iss);
    EXPECT_THROW(parser.parseString(), std::invalid_argument);
}

TEST_F(BencodeParserTest, ParseStringTooLongTest) {
    Bencoding::BencodeParser parser;
    std::string input = "10:hello";
    std::istringstream iss(input);
    parser.setInput(iss);
    EXPECT_THROW(parser.parseString(), std::length_error);
}
