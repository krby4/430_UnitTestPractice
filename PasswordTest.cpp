/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, long_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZZZZZZZZZZZZZZ");
	ASSERT_EQ(19, actual);
}
TEST(PasswordTest, empty_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, camel_case_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zz");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, 2letter_camel)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Zz");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, 1letter_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Z");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, 1letter_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("z");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, lower_only)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zzzzzzz");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, upper_only)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZZZZZZZ");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, empty_mixedcase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, numbers_only)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("1234");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, chars_only)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!@#");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, mixed_num_char_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123^&zZ");
	ASSERT_EQ(true, actual);
}