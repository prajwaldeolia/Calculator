#pragma once

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#define pi 3.14;

using namespace std;


class Ioperation
{
public:
    virtual double calc(double a, double b) = 0;
};

class Sum : public Ioperation
{
public:
    Sum(/* args */){}

    double calc(double a, double b)
    {
        return a + b;
    }

    ~Sum(){}
};

class Substract : public Ioperation
{
private:
    /* data */
public:
    Substract(/* args */){}

    double calc(double a, double b)
    {
        return a - b;
    }

    ~Substract(){}
};

class Multiply : public Ioperation
{
private:
    /* data */
public:
    Multiply(/* args */){}

    double calc(double a, double b)
    {
        return a * b;
    }

    ~Multiply(){}
};

class Devision : public Ioperation
{
private:
    /* data */
public:
    Devision(/* args */){}

    double calc(double a, double b)
    {
        if(b == 0)
            throw 0;
        return a / b;
    }

    ~Devision(){}
};