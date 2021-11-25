#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){
    EXPECT_EQ(3,FunSearchProblem::facingSun({2,3,1,2,4,1}));
    EXPECT_EQ(0,FunSearchProblem::facingSun({}));
    EXPECT_EQ(1,FunSearchProblem::facingSun({7}));
}

TEST(test, squareR){
    EXPECT_EQ(5,FunSearchProblem::squareR(25));
    EXPECT_EQ(0,FunSearchProblem::squareR(0));

}

TEST(test, missingvalue){
    EXPECT_EQ(1,FunSearchProblem::smallestMissingValue({-1,4,7,-3,0}));
    EXPECT_EQ(0,FunSearchProblem::smallestMissingValue({-3,-6,0}));
    EXPECT_EQ(5,FunSearchProblem::smallestMissingValue({1,2,3,4}));
}

TEST(test, minPages){
    EXPECT_EQ(-1,FunSearchProblem::minPages({10,15,8,13},10));
    EXPECT_EQ(54,FunSearchProblem::minPages({10,20,45,12,54,13},6));
    EXPECT_EQ(45,FunSearchProblem::minPages({10,20,30,40,50,60},2));
}
