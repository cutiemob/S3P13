#include <iostream>
#include <string>
#include <cmath>

class Calculator {
private:
    double operand1;
    double operand2;
    std::string operation;
    double result;

public:
    Calculator() : operand1(0), operand2(0), operation(""), result(0) {}

    Calculator(double op1, double op2, const std::string& oper) : operand1(op1), operand2(op2), operation(oper), result(0) {}

    void setOperand1(double op1) { operand1 = op1; }
    void setOperand2(double op2) { operand2 = op2; }
    void setOperation(const std::string& oper) { operation = oper; }

    void calculate() {
        if (operation == "+") {
            result = operand1 + operand2;
        } else if (operation == "-") {
            result = operand1 - operand2;
        } else if (operation == "*") {
            result = operand1 * operand2;
        } else if (operation == "/") {
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                std::cerr << "Error: division by zero!" << std::endl;
                result = NAN;
            }
        } else {
            std::cerr << "Error: unknown operation!" << std::endl;
            result = NAN;
        }
    }

    void changeOperation(const std::string& newOperation) {
        operation = newOperation;
    }

    void displayState() const {
        std::cout << "Operand1: " << operand1 << "\n"
                  << "Operand2: " << operand2 << "\n"
                  << "Operation: " << operation << "\n"
                  << "Result: " << result << "\n";
    }

    double getResult() const {
        return result;
    }
};

void displayMenu() {
    std::cout << "\nMenu:\n"
              << "1. Set the first number\n"
              << "2. Set the second number\n"
              << "3. Set operation (+, -, *, /)\n"
              << "4. Perform the calculation\n"
              << "5. Change operation\n"
              << "6. Show current status\n"
              << "0. Output\n"
              << "Your choice: ";
}

int main() {
    Calculator calc;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double op1;
                std::cout << "Enter the first number: ";
                std::cin >> op1;
                calc.setOperand1(op1);
                break;
            }
            case 2: {
                double op2;
                std::cout << "Enter the second number: ";
                std::cin >> op2;
                calc.setOperand2(op2);
                break;
            }
            case 3: {
                std::string oper;
                std::cout << "Enter the operation (+, -, *, /): ";
                std::cin >> oper;
                calc.setOperation(oper);
                break;
            }
            case 4:
                calc.calculate();
                std::cout << "Calculation performed. Result: " << calc.getResult() << "\n";
                break;
            case 5: {
                std::string newOper;
                std::cout << "Enter a new operation (+, -, *, /): ";
                std::cin >> newOper;
                calc.changeOperation(newOper);
                break;
            }
            case 6:
                calc.displayState();
                break;
            case 0:
                std::cout << "Exiting the program. Final result: " << calc.getResult() << "\n";
                break;
            default:
                std::cout << "Wrong choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
