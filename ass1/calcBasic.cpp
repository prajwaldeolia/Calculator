#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>

using namespace std;




inline int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

inline bool isnum(char ch)
{
    return (ch >= '0' && ch <= '9' || ch == '.');
}

void infixToPostfix(string query, queue<string>&result)
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
            while (!st.empty() && (prec(ch) <= prec(st.top()[0]))) 
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
            while(isnum(query[i]))
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
}

double evaluatePostfix(queue<string> &exp)
{
    stack<double>stk;
    while(!exp.empty())
    {
        string fr = exp.front();
        exp.pop();
        if (isnum(fr[0]))
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
                case '+': stk.push(val2 + val1); break;
                case '-': stk.push(val2 - val1); break;
                case '*': stk.push(val2 * val1); break;
                case '/': if(val1 != 0)
                            stk.push(val2 / val1);
                          else
                            throw 0;
                          break;    
            }
        }
    }
    return stk.top();
}

double calc(string query)
{
    queue<string>result;
    infixToPostfix(query, result);
    return evaluatePostfix(result);
}

int main()
{
    string query;
    cout<<" + , - , * , / "<<endl;
    cout<<"Enter Query : ";
    cin>>query;
    try
    {
        cout<<calc(query);
    }
    catch(int e)
    {
        cout<<"devisor cannot be "<<e;
    }
}