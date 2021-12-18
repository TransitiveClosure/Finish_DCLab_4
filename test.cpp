#include <gtest/gtest.h>
#include "Lab1.c"
//int fun(int a, int b);

TEST(checking_answer, check_option_c){ 
    EXPECT_EQ(fun(1,1),2);
}

int main(int argc, char**argv)
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
