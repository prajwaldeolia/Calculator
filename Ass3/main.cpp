// #pragma once

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <math.h>

#include "calculate.hpp"
#include "operationFactory.hpp"

#define pi 3.14;

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string query;
    cout << "simple calc only use : + , - , * , /, () " << endl;
    cout << "Enter Query : ";
    cin >> query;
    Calculate simpleCalc(query);
    try
    {
        cout << simpleCalc.evaluate();
    }
    catch (int e)
    {
        if (e == 0)
            cout << "devisor cannot be " << e;
    }
    return 0;
}