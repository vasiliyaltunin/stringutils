#include "../include/stringutils/stringutils.h"
#include <gtest/gtest.h>

using namespace altuninvv::string;

TEST(TestStringUtils, TrimTestsEn) {

  StringUtils<std::string> s;

  std::string testStr;

  testStr = "   TEST STRING";

  EXPECT_EQ(s.ltrim(testStr), "TEST STRING");

  testStr = "TEST STRING    ";

  EXPECT_EQ(s.rtrim(testStr), "TEST STRING");

  testStr = "     TEST STRING    ";

  EXPECT_EQ(s.trim(testStr), "TEST STRING");
}

TEST(TestStringUtils, TrimTestsRu) {

  StringUtils<std::wstring> s;

  std::wstring testStr;

  testStr = L"   ПРИВЕТ МИР";

  EXPECT_EQ(s.ltrim(testStr), L"ПРИВЕТ МИР");

  testStr = L"ПРИВЕТ МИР    ";

  EXPECT_EQ(s.rtrim(testStr), L"ПРИВЕТ МИР");

  testStr = L"     ПРИВЕТ МИР    ";

  EXPECT_EQ(s.trim(testStr), L"ПРИВЕТ МИР");
}

TEST(TestStringUtils, SplitTestsEn) {
  StringUtils<std::string> s;

  std::string testStr;

  testStr = "HELLO MY PERFECT WORLD";

  StringUtils<std::string>::strlist result;

  result.insert(result.end(), "HELLO");
  result.insert(result.end(), "MY");
  result.insert(result.end(), "PERFECT");
  result.insert(result.end(), "WORLD");

  EXPECT_EQ(s.split(testStr, " "), result);
}

TEST(TestStringUtils, SplitTestsRu) {
  StringUtils<std::wstring> s;

  std::wstring testStr;

  testStr = L"ПРИВЕТ МОЙ НОВЫЙ МИР";
  StringUtils<std::wstring>::strlist result;

  result.insert(result.end(), L"ПРИВЕТ");
  result.insert(result.end(), L"МОЙ");
  result.insert(result.end(), L"НОВЫЙ");
  result.insert(result.end(), L"МИР");

  EXPECT_EQ(s.split(testStr, L" "), result);
}

 TEST(TestStringUtils, LoginTestsEn) {
  StringUtils<std::string> s;

  std::string testStr;

  testStr = "IVANOV PETR SEMENOVICH";
  std::string result = "IVANOVPS";

  EXPECT_EQ(s.makeLogin(testStr," "), result);

}

TEST(TestStringUtils, LoginTestsRu) {
  StringUtils<std::wstring> s;

  std::wstring testStr;

  testStr = L"ИВАНОВ ПЕТР СЕМЕНОВИЧ";
  std::wstring result = L"ИВАНОВПС";

  EXPECT_EQ(s.makeLogin(testStr,L" "), result);

} 

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}