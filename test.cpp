#include <gtest/gtest.h>
#include "Lab1.c"
//int fun(int a, int b);

TEST(checking_answer, check_option_c){
  
    ASSERT_EQ(fun(1,1),2);
}
