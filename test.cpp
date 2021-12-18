#include <gtest/gtest.h>
#include "Lab1.c"
//int fun(int a, int b);
typedef struct uint1024_t
{
    unsigned int element[32];
} uint1024_t;

uint1024_t t;
uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
TEST(fun_from_uint, positive_value){
    t.element[0] = 10000;
    EXPECT_EQ(from_uint(10000).element[0],t.element[0]);
}
TEST(fun_from_uint, negative_value){
    t.element[0] = UINT32_MAX - 1000 + 1;
    EXPECT_EQ(from_uint(-1000).element[0],t.element[0]);
}
TEST(fun_from_uint, zero){
    t.element[0] = 0;
    EXPECT_EQ(from_uint(0).element[0],t.element[0]);
}
TEST(fun_add_op, limits_value){
    uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t res = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    num1.element[0] = UINT32_MAX;
    num2.element[0] = UINT32_MAX;
    res.element[0] = UINT32_MAX - 1;
    res.element[1] = 1;
    EXPECT_EQ(add_op(num1, num2).element[0],res.element[0]);
    EXPECT_EQ(add_op(num1, num2).element[1],res.element[1]);
}
TEST(fun_add_op, simple_add){
    uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t res = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    num1.element[0] = 8;
    num2.element[0] = 9;
    res.element[0] = 17;
    EXPECT_EQ(add_op(num1, num2).element[0],res.element[0]);
    EXPECT_EQ(add_op(num1, num2).element[1],res.element[1]);
}
TEST(fun_subtr_op, a_more_b){
    uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t res = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    num1.element[1] = 1;
    num2.element[0] = 2422;
    res.element[0] = UINT32_MAX - 2422 + 1;
    EXPECT_EQ(subtr_op(num1, num2).element[0],res.element[0]);
    EXPECT_EQ(subtr_op(num1, num2).element[1],res.element[1]);
}
TEST(fun_subtr_op, b_more_a){
    uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t res = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    num1.element[0] = 1000000;
    num2.element[1] = 1;
    res.element[0] = 0;
    EXPECT_EQ(subtr_op(num1, num2).element[0],res.element[0]);
    EXPECT_EQ(subtr_op(num1, num2).element[1],res.element[1]);
}
TEST(fun_mult_op, multiplication){
    uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t res = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    num1.element[0] = UINT32_MAX;
    num2.element[0] = 10000;
    res.element[0] = 4294957296;
    res.element[1] = 9999;
    EXPECT_EQ(mult_op(num1, num2).element[0],res.element[0]);
    EXPECT_EQ(mult_op(num1, num2).element[1],res.element[1]);
}
TEST(fun_mult_op, multiplication_by_zero){
    uint1024_t num1 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t num2 = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint1024_t res = {0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    num1.element[0] = UINT32_MAX;
    num1.element[1] = UINT32_MAX;
    num1.element[2] = UINT32_MAX;
    num2.element[0] = 0;
    EXPECT_EQ(mult_op(num1, num2).element[0],res.element[0]);
    EXPECT_EQ(mult_op(num1, num2).element[1],res.element[1]);
}
int main(int argc, char**argv)
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
