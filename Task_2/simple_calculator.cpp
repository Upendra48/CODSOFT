//? Task 2 of C++ Programming Internship at Codsoft

//* Simple Calculator

//todo: Using procedural programming

#include <iostream>
using namespace std;

int main()
{
    float num1, num2, result;
    char choice;
    // clear screen
    system("cls");
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operator (+,-,*,/): ";
    cin >> choice;

    switch (choice)
    {
    case '+':
        
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << "\n\n";
        break;
    case '-':
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << "\n\n";
        break;
    case '*':
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << "\n\n";
        break;
    case '/':
        result = num1 / num2;
        cout << num1 << " / " << num2 << " = " << result << "\n\n";
        break;
    default:
        cout << "Invalid operator";
        break;
    }

    return 0;
}


//todo:  Using object oriented programming

#include <iostream>
using namespace std;

class Calculator
{
private:
    float num1, num2, result;
    char choice;

public:
    
    void getdata()
    {
        system("cls");
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Enter operator (+,-,*,/): ";
        cin >> choice;
    }
    void calculate()
    {
        switch (choice)
        {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << "\n\n";
            break;
        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << "\n\n";
            break;
        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << "\n\n";
            break;
        case '/':
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result << "\n\n";
            break;
        default:
            cout << "Invalid operator";
            break;
        }
    }
};

int main()
{
    Calculator c;
    c.getdata();
    c.calculate();
    return 0;
}