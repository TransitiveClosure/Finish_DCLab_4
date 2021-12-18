#include <gtest/gtest.h>
#include "Lab1.c"
//int fun(int a, int b);

TEST(checking_answer, check_option_c){ 
    EXPECT_EQ(fun(1,1),2);
}
TEST(checking_answer, check_option_l){ 
    EXPECT_EQ(fun(2,1),3);
}
TEST(checking_answer, check_option_w){ 
    EXPECT_EQ(fun(5,2),7);
}

int main(int argc, char**argv)
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
