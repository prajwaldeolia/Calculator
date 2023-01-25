// #pragma once

#include"/home/phoenix/cpp_project/C++/Ass4/include/headers.h"
#include"/home/phoenix/cpp_project/C++/Ass4/tests/test.cpp"
#include<gtest/gtest.h>
#define pi 3.14

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    std::string query;
    std::cout << "simple calc only use : + , - , * , /, () " << std::endl;
    while(true)
    {
        std::cout << "Enter Query : ";
        std::cin >> query;
        CALCULATOR::Get().calulate(query);
        lable:
        std::cout<<"for continue press 1\nfor exit press 0"<<std::endl;
        int response;
        std::cin>>response;
        if(response == 1)
            continue;
        else if(response == 0)
            break;
        else
        {
            std::cout<<"enter correct choice\n";
            goto lable;
        }
    }
    std::cout<<"check History -> press 1\nto exit hit 'enter'";
    int a = 0;
    std::cin>>a;
    if(a == 1)
        CALCULATOR::Get().showHistory();
    std::cin.get();
    return RUN_ALL_TESTS();
}





// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
    
//     return RUN_ALL_TESTS();
// }
