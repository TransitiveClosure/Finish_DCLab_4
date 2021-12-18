#include <gtest/gtest.h>
#include "Lab1.c"
//int fun(int a, int b);

using testing::Eq;
TEST(checking_answer, check_option_c){
    char *str[3] = { "", "-c", "D:/UNIVER_PROGA/Programing/Programming_labs/TEST.txt"};
    EXPECT_EQ(work_with_file(3,str),31);
    str[3] = "--bytes";
    EXPECT_EQ(work_with_file(3,str),31);
}
TEST(checking_answer, check_option_l){
    char *str[3] = { "", "-l", "D:/UNIVER_PROGA/Programing/Programming_labs/TEST.txt"};
    EXPECT_EQ(work_with_file(3,str),3);
    str[3] = "--lines";
    EXPECT_EQ(work_with_file(3,str),3);
}
TEST(checking_answer, check_option_w){
    char *str[3] = { "", "-w", "D:/UNIVER_PROGA/Programing/Programming_labs/TEST.txt"};
    EXPECT_EQ(work_with_file(3,str),4);
    str[3] = "--words";
    EXPECT_EQ(work_with_file(3,str),4);
}
TEST(check_errors, check_error_1001){
    char *str[2] = { "", "-c"};
    EXPECT_EQ(work_with_file(2,str),-1001);
}
TEST(check_errors, check_error_1002){
    char *str[3] = { "", "-tgrgsdgsegwg", "D:/UNIVER_PROGA/Programing/Programming_labs/TEST.txt"};
    EXPECT_EQ(work_with_file(3,str),-1002);
}
TEST(check_errors, check_error_1003){
    char *str[3] = { "", "-l", "D:/UNIVER_PROGA/Programing/Programming_labs/TEST.txtfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
    EXPECT_EQ(work_with_file(3,str),-1003);
}
TEST(check_errors, check_error_1004){
    char *str[3] = { "", "-l", "file.txt"};
   EXPECT_EQ(work_with_file(3,str),-1004);
}
TEST(check_errors, check_error_1005){
    char *str[3] = { "", "-t", "D:/UNIVER_PROGA/Programing/Programming_labs/TEST.txt"};
    EXPECT_EQ(work_with_file(3,str),-1005);
}

int main(int argc, char**argv)
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
