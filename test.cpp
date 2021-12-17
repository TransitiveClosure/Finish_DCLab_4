#include <gtest/gtest.h>

int fun(int a, int b);

TEST(checking_answer, check_option_c){
  
    EXPECT_EQ(fun(1,1),2);
}
