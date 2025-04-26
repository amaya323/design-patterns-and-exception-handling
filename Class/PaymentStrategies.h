#pragma once

#include <iostream>
#include "Logger.h"

using namespace std;

class PaymentStrategy {
public:
    virtual void pay(int orderId) = 0;
    virtual string getPaymentMethod() = 0;
    static string message() {
        return "\nYou have successfully checked out the products!\n";
    }
};

class Gcash: public PaymentStrategy {
private:
    Logger& logger = Logger::getInstance();

public:
    void pay(int orderId) override{
        string gcashNumber;

        bool isContactValid;
        do {
            isContactValid = true;
            cout << "Enter Gcash number (09XXXXXXXXX): ";
            getline(cin, gcashNumber);

            // Ensure all characters are digits
            for (char c: gcashNumber) {
                if (!isdigit(c)) {
                    isContactValid = false;
                    break;
                }
            }

            // Validate format: exactly 11 digits & starts with "09"
            if ((isContactValid && gcashNumber.length() != 11) || gcashNumber[0] != '0' || gcashNumber[1] != '9') {
                isContactValid = false;
            }

            if (!isContactValid) {
                cout << endl << "Error: Invalid gcash number." << endl;
            }
        } while (!isContactValid);

        logger.logOrder("Order ID: " + to_string(orderId) + " has been successfully checked out and paid using Gcash");
        cout<<Gcash::message();
    }

    string getPaymentMethod() override {
        return "Gcash";
    }
};

class CreditDebitCard: public PaymentStrategy {
private:
    Logger& logger = Logger::getInstance();

public:
    void pay(int orderId) override{
        string creditDebitCardNumber;
        bool isContactValid;
        do {
            isContactValid = true;
            cout << "Enter 16-digit card number: ";
            getline(cin, creditDebitCardNumber);

            // Ensure all characters are digits
            for (char c: creditDebitCardNumber) {
                if (!isdigit(c)) {
                    isContactValid = false;
                    break;
                }
            }

            // Validate format: exactly 16 digits & starts with
            if (isContactValid && creditDebitCardNumber.length() != 16) {
                isContactValid = false;
            }

            if (!isContactValid) {
                cout << endl << "Error: Invalid gcash number." << endl;
            }
        } while (!isContactValid);
        logger.logOrder("Order ID: " + to_string(orderId) + " has been successfully checked out and paid using Credit/Debit Card");
        cout<<CreditDebitCard::message();
    }

    string getPaymentMethod() override {
        return "Credit/Debit Card";
    }
};

class Cash: public PaymentStrategy {
private:
    Logger& logger = Logger::getInstance();
public:
    void pay(int orderId) override{
        logger.logOrder("Order ID: " + to_string(orderId) + " has been successfully checked out and paid using Cash");
        cout<<Cash::message();
    }

    string getPaymentMethod() override {
        return "Cash";
    }

};

class PaymentContext {
private:
    PaymentStrategy* strategy;

public:
    void setPaymentMethod(PaymentStrategy* paymentStarategy) {
        this->strategy = paymentStarategy;
    }

    void payOrder(int orderId) {
        strategy->pay(orderId);
    }

    string getPaymentMethod() {
        return strategy->getPaymentMethod();
    }
};