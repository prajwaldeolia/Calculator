#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<math.h>

#include"operations.hpp"
#include"converter.hpp"
#include"validations.hpp"

#define pi 3.14;

using namespace std;


class Calculate : public Converter
{
private:
    Ioperation *operate = nullptr;
public:
    Calculate(string query)
    {
        Converter obj(query);
        result = obj.infixToPostfix(query);
    }
    double evaluate()
    {
        stack<double>stk;
        while(!result.empty())
        {
            string fr = result.front();
            result.pop();
            if (ec.isnum(fr))
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
                char oper = fr[0];
                switch (oper)                               // class simpleCalc
                {
                    case '+': operate = new Sum(); break;
                    case '-': operate = new Substract(); break;
                    case '*': operate = new Multiply(); break;
                    case '/': operate = new Devision(); break;
                }
                stk.push(operate->calc(val2, val1));
                delete operate;
            }
        }
        return stk.top();
    }
    ~Calculate(){}
};