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
public:
    Validations(){}

    bool isValid(string query)
    {
        set<char>x = {'.', '+', '-', '*', '/', '(', ')'};
        for(auto i : query)
            if(!isnum(i) && !x.count(i))
                return false;
        return true;
    }

    int precedence(char ch)
    {
        if (ch == '^')
            return 3;
        else if (ch == '/' || ch == '*')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }

    bool isnum(char ch)
    {
        return ((ch >= '0' && ch <= '9') || ch == '.');
    }

    ~Validations(){}
};