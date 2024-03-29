#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>

#include"operationFactory.h"
#include"converter.h"
#include"validations.h"

#define debug 1
#if debug == 1
#define tcons Calculate()\
    {\
        result.push("2");\
        result.push("3");\
        result.push("+");\
        result.push("4");\
        result.push("-");\
        result.push("8");\
        result.push("+");\
    }
#else
#define tcons
#endif

class Calculate : public Converter, operationFactory
{
private:
    std::queue<std::string>result;
public:
tcons
    Calculate(std::string query)
    {
        try
        {
            Converter obj(query);
            result = obj.infixToPostfix(query);
        }
        catch (int e)
        {
            if (e == 1)
                std::cout << "Please enter valid expression";
        }
    }
    double evaluate()
    {
        std::stack<double>stk;
        while(!result.empty())
        {
            std::string fr = result.front();
            result.pop();
            if (ec.isnum(fr[0]))
            {
                double num = stod(fr);
                stk.push(num);
            }
            else
            {
                double val1 = stk.top();
                stk.pop();
                double val2 = stk.top();
                stk.pop();
                operationFactory op;
                optr = op.factory(fr[0]);
                stk.push(optr->calc(val2, val1));
            }
        }
        return stk.top();
    }
    ~Calculate(){}
};