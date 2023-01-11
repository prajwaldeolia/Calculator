#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<math.h>

#include"operationFactory.hpp"
#include"converter.hpp"
#include"validations.hpp"

#define pi 3.14;

using namespace std;


class Calculate : public Converter, operationFactory
{
// private:
//     Ioperation *operate;
public:
    Calculate(string query)
    {
        // operate = nullptr;
        Converter obj(query);
        obj.infixToPostfix(query);
    }
    double evaluate()
    {
        stack<double>stk;
        while(!result.empty())
        {
            string fr = result.front();
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