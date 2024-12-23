#include "hello/hello.h"
#include "hello/hello1.h"
#include "gtest.h"

TEST(testcase1, isOdd3)
{
    EXPECT_TRUE(isOdd(3));
}

TEST(testcase1, isOdd5)
{
    EXPECT_TRUE(isOdd(5)) << "5 is not odd!";
}

TEST(testcase2, Sum1_2)
{
    int a = 10;
    int b = 11;
    EXPECT_EQ(Sum(a, b), 21);
    int c = 20;
    int d = 21;
    EXPECT_EQ(Sum(c, d), 41);
}

