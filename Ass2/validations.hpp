#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#define pi 3.14;

using namespace std;


class Validations
{
private:
    /* data */
public:
    Validations(/* args */){}

    bool isValid(string query)
    {
        char ch = '0';
        for(auto i : query)
        {
            set<char>x = {'.', '+', '-', '*', '/'};
            if(i >= '0' && i <= '9' || i == '(' || i == ')' || x.count(i) && !x.count(ch))
            {
                ch = i;
            }
            else
                return false;
        }
        return true;
    }

    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    bool isnum(string ch)
    {
        int cnt = 0;
        for(auto i : ch)
        {
            if(i == '.')
                cnt++;
            if((i >= '0' && i <= '9' || i == '.') && cnt <= 1)
                continue;
            else
                return false;
        }
        return true;
    }

    ~Validations(){}
};