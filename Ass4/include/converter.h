#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>

#include"validations.h"

class Converter : public Validations
{
protected:
    std::queue<std::string>result;
    Validations ec;
public:
    Converter()
    {}
    Converter(std::string str)
    {
        if(!ec.isValid(str))
        {
            std::cout<<"invalid"<<std::endl;
            throw 1;
        }
    }

    std::queue<std::string> infixToPostfix(std::string query)
    {
        std::stack<std::string> st;
        std::string operand;
        std::string ch;

        for(int i = 0; i < query.size(); i++)
        {
            char ch = query[i];
            if (ch == '(')
                st.push("(");
            else if (ch == ')')
            {
                while (st.top() != "(")
                {
                    result.push(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                while (!st.empty() && (ec.precedence(ch) <= ec.precedence(st.top()[0]))) 
                {
                    result.push(st.top());
                    st.pop();
                }
                std::string ss = "";
                ss += ch;
                st.push(ss);
            }
            else
            {
                std::string temp = "";
                while(query[i] >= '0' && query[i] <= '9' || query[i] == '.')
                {
                    temp += query[i];
                    i++;
                }
                i--;
                result.push(temp);
            }
        }
        while (!st.empty()) 
        {
            result.push(st.top());
            st.pop();
        }
        return result;
    }
    ~Converter()
    {}
};