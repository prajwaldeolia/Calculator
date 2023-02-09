#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<math.h>

#include"validations.hpp"

#define pi 3.14;

using namespace std;


class Converter : public Validations
{
protected:
    queue<string>result;
    Validations ec;
public:
    Converter()
    {}
    Converter(string str)
    {
        if(!ec.isValid(str))
        {
            cout<<"invalid"<<endl;
            throw 1;
        }
    }

    queue<string> infixToPostfix(string query)
    {
        stack<string> st;
        string operand;
        string ch;

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
                string ss = "";
                ss += ch;
                st.push(ss);
            }
            else
            {
                string temp = "";
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