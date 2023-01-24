#include"/home/phoenix/cpp_project/C++/Ass4/include/headers.h"
#include<string>
#include<gtest/gtest.h>


//ADD

class AdditionTestFixture : public testing::Test
{

   protected:

    Sum my_object_under_test;

    AdditionTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {

        }

};

TEST_F(AdditionTestFixture, TestSum)

{

    auto actualResult(this->my_object_under_test.calc(4.5, 6.5));

    EXPECT_EQ(actualResult, 11);

}


//SUB

class SubstractionTestFixture : public testing::Test
{

   protected:

    Substract my_object_under_test;

    SubstractionTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {
            
        }
};

TEST_F(SubstractionTestFixture, TestSum)

{

    auto actualResult(this->my_object_under_test.calc(4.5, 6.5));

    EXPECT_EQ(actualResult, -2);

}


//MULTIPLY

class MultiplicationTestFixture : public testing::Test
{

   protected:

    Multiply my_object_under_test;

    MultiplicationTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {
            
        }

};

TEST_F(MultiplicationTestFixture, TestSum)

{

    auto actualResult(this->my_object_under_test.calc(4.5, 6.5));

    EXPECT_EQ(actualResult, 29.25);

}


//Devide

class DivisionTestFixture : public testing::Test
{

   protected:

    Devision my_object_under_test;

    DivisionTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {
            
        }

};

TEST_F(DivisionTestFixture, TestSum)

{

    auto actualResult(this->my_object_under_test.calc(4.5, 6.5));

    EXPECT_EQ(actualResult, 4.5/6.5);

} 


//converter

class ConvertTestFixture : public testing::Test
{

   protected:

    Converter my_object_under_test;

    ConvertTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {
            
        }
};

TEST_F(ConvertTestFixture, TestSum)

{
    std::string str = "2+3-4+8";
    std::queue<std::string>q;
    auto actualResult(this->my_object_under_test.infixToPostfix(str));
    q.push("2");
    q.push("3");
    q.push("+");
    q.push("4");
    q.push("-");
    q.push("8");
    q.push("+");
    EXPECT_EQ(actualResult, q);
} 


// calculate

class CalculateTestFixture : public testing::Test
{

   protected:
    Calculate my_object_under_test;

    CalculateTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {

        }

};

TEST_F(CalculateTestFixture, TestSum)

{
    auto actualResult(this->my_object_under_test.evaluate());

    EXPECT_EQ(actualResult, 2.0+3.0-4.0+8.0);

}


// OFactory

class OFactoryTestFixture : public testing::Test
{

   protected:
    Ioperation* ptr;
    operationFactory my_object_under_test;

    OFactoryTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {

        }

};

TEST_F(OFactoryTestFixture, TestSumObj)
{
    auto actualResult(this->my_object_under_test.factory('+'));
    ptr = new Sum()-4;
    EXPECT_EQ(actualResult, ptr);
}
TEST_F(OFactoryTestFixture, TestSubObj)
{
    auto actualResult(this->my_object_under_test.factory('-'));
    ptr = new Substract()-4;
    EXPECT_EQ(actualResult, ptr);
}
TEST_F(OFactoryTestFixture, TestMulObj)
{
    auto actualResult(this->my_object_under_test.factory('*'));
    ptr = new Multiply()-4;
    EXPECT_EQ(actualResult, ptr);
}
TEST_F(OFactoryTestFixture, TestDivObj)
{
    auto actualResult(this->my_object_under_test.factory('/'));
    ptr = new Devision()-4;
    EXPECT_EQ(actualResult, ptr);
} 


// Validation

class ValidationTestFixture : public testing::Test
{

   protected:
    Validations my_object_under_test;
    char ch;
    ValidationTestFixture()
        :   ::testing::Test(), my_object_under_test()
        {

        }

};

TEST_F(ValidationTestFixture, precedence)
{   
    ch = '+';
    auto actualResult0(this->my_object_under_test.precedence(ch));
    EXPECT_EQ(actualResult0, 1);
    ch = '-';
    auto actualResult1(this->my_object_under_test.precedence(ch));
    EXPECT_EQ(actualResult1, 1);
    ch = '*';
    auto actualResult2(this->my_object_under_test.precedence(ch));
    EXPECT_EQ(actualResult2, 2);
    ch = '/';
    auto actualResult3(this->my_object_under_test.precedence(ch));
    EXPECT_EQ(actualResult3, 2);
    ch = '^';
    auto actualResult4(this->my_object_under_test.precedence(ch));
    EXPECT_EQ(actualResult4, 3);
    ch = '#';
    auto actualResult5(this->my_object_under_test.precedence(ch));
    EXPECT_EQ(actualResult5, -1);
}
TEST_F(ValidationTestFixture, isNum)
{
    ch = '.';
    auto actualResult(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult, true);
    ch = '0';
    auto actualResult0(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult0, true);
    ch = '1';
    auto actualResult1(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult1, true);
    ch = '2';
    auto actualResult2(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult2, true);
    ch = '3';
    auto actualResult3(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult3, true);
    ch = '4';
    auto actualResult4(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult4, true);
    ch = '5';
    auto actualResult5(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult5, true);
    ch = '6';
    auto actualResult6(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult6, true);
    ch = '7';
    auto actualResult7(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult7, true);
    ch = '8';
    auto actualResult8(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult8, true);
    ch = '9';
    auto actualResult9(this->my_object_under_test.isnum(ch));
    EXPECT_EQ(actualResult9, true);
}





// DB_LITE;            nd
// CALCULATOR;         nd