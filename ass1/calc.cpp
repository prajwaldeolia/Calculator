#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<math.h>
#define pi 3.14;

using namespace std;

class Display
{
public:
    virtual void showResult() = 0;
    virtual void clear() = 0;
};
template<class T>
class Calculate : public Display
{
private:
    int calcId;
protected:
    string query;
public:
    Calculate()         //default constructor
    {
        calcId = 1;
    }
    Calculate(int calcId)
    {
        this->calcId = calcId;
    }

    virtual int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    virtual bool isnum(char ch)
    {
        return (ch >= '0' && ch <= '9' || ch == '.');
    }
    
};
template<class T>
class simpleCalc : public Calculate
{
private:
    T val1;
    T val2;
public:

    T add()
    {
        return val2 + val1;
    }
    T diff()
    {
        return val2 - val1;
    }
    T product()
    {
        return val2 * val1;
    }
    T devide()
    {
        if(val1 == 0)
            throw 0;
        return val2 / val1;
    }
};
template<class T>
class Scientific_calc : public Calculate
{
private:
    T num;
    int power;
public:
    T powOf()
    {
        return pow(num, power);
    }

    T root()
    {
        T tmp = 1/power;
        return pow(num, tmp);
    }

    T fact()
    {
        T ans = 1;
        for(int i = 2; i <= num; i++)
            ans *= i
        return ans;
    }
};
template<class T>
class Area_calc : public Calculate
{
private:
    T length;
    T breadth;
    T radius;
public:
    T area(double radius)
    {
        return radius*radius*pi;
    }
    T area(double breadth, double length)
    {
        return length*breadth;
    }
    T area(double length)
    {
        return length*length;
    }
};


int main()
{
    cout<<"Calculator \n";
    cout<<endl;
    cout<<"Choose calculator \n \t simple calculator \n \t Area calculator \n \t scientific calculator";
    Calculate<int> *p;

    string query;
    cout<<" + , - , * , / "<<endl;
    cout<<"Enter Query : ";
    cin>>query;
    // cout<<calc(query);
}