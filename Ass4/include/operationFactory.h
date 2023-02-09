#pragma once

#include<iostream>
#include<math.h>
#include<iomanip>


class Ioperation
{
public:
    virtual double calc(double a, double b) = 0;
};

class Sum : public Ioperation
{
public:
    Sum(){}

    double calc(double a, double b)
    {
        return a + b;
    }

    ~Sum(){}
};

class Substract : public Ioperation
{
public:
    Substract(){}

    double calc(double a, double b)
    {
        return a - b;
    }

    ~Substract(){}
};

class Multiply : public Ioperation
{
public:
    Multiply(){}

    double calc(double a, double b)
    {
        return a * b;
    }

    ~Multiply(){}
};

class Devision : public Ioperation
{
public:
    Devision(){}

    double calc(double a, double b)
    {
        if(b == 0)
            throw 0;
        return a / b;
    }

    ~Devision(){}
};

class operationFactory
{
protected:
    Ioperation* optr;
public:
    operationFactory()
    {
        optr = nullptr;
    }

    Ioperation* factory(char ch)
    {
        switch (ch)                               // class simpleCalc
        {
            case '+': optr = new Sum(); break;
            case '-': optr = new Substract(); break;
            case '*': optr = new Multiply(); break;
            case '/': optr = new Devision(); break;
        }
        return optr;
    }

    ~operationFactory()
    {
        // cout<<"distructor"<<endl;
        // delete optr;
    }
};