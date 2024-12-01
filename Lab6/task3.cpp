#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "StackHeaderFile.h"

using namespace std;

float calculate(float operand1, float operand2, const string &operatorType)
{
    if (operatorType == "+")
    {

        return operand1 + operand2;
    }
    else if (operatorType == "-")
    {
        return operand1 - operand2;
    }
    else if (operatorType == "*")
    {
        return operand1 * operand2;
    }
    else if (operatorType == "/")
    {
        return operand1 / operand2;
    }

    return 0;
}

string calculateAns(const string &expression)
{
    stringstream inputStream(expression); //took help from net to understand stringstream
    string currChar;
    Stack<string> numStack;
    Stack<string> opStack;

    while (inputStream >> currChar)
    {
        if (isdigit(currChar[0]) || (currChar[0] == '-' && currChar.size() > 1))
        {
            numStack.push(currChar);
        }
        else if (currChar == "+" || currChar == "-" || currChar == "*" || currChar == "/")
        {
            opStack.push(currChar);
        }
        else if (currChar == "(")
        {
            opStack.push(currChar);
        }
        else if (currChar == ")")
        {
            while (opStack.peek() != "(")
            {
                double operand2 = stod(numStack.peek());
                numStack.pop();
            double operand1 = stod(numStack.peek());

                numStack.pop();
                string operation = opStack.peek();

                opStack.pop();
                float result = calculate(operand1, operand2, operation);




                numStack.push(to_string(result));
            }
            opStack.pop();
        }
    }

    while (!opStack.isEmpty())
    {
        double operand2 = stod(numStack.peek());
        numStack.pop();
        double operand1 = stod(numStack.peek());
        numStack.pop();
        string operation = opStack.peek();
        opStack.pop();
        float result = calculate(operand1, operand2, operation);
        numStack.push(to_string(result));
    }

    return numStack.peek();
}

int main()
{
    string expression = "12 + 13 + 1 - 5 * ( 0.5 + 0.5 )";

    string result = calculateAns(expression);
    cout<<"Expression was "<<expression<<endl;
    cout << "Result is: " << stod(result) << endl;

    return 0;
}