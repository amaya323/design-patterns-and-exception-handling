#pragma once

#include <iostream>
#include "Logger.h"
#include "Order.h"
#include "ShoppingCart.h"
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
        logger.logOrder("Order ID:" + to_string(orderId) + " has been successfully checked out and paid using Gcash");
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
        logger.logOrder("Order ID:" + to_string(orderId) + " has been successfully checked out and paid using Credit/Debit Card");
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
        logger.logOrder("Order ID:" + to_string(orderId) + " has been successfully checked out and paid using Cash");
        cout<<Cash::message();
    }

    string getPaymentMethod() override {
        return "Cash";
    }

};

class paymentContext {
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