#pragma once
#include "Product.h"
#include "Order.h"
#include "PaymentStrategies.h"
#include "Function.h"
#include "ProductCatalog.h"
#include "ShoppingCart.h"

class Shop {
private:
    Order* orders[10];
    ShoppingCart& cart = ShoppingCart::getInstance();
    int orderId = 1;

public:
    void addToCart() {
        int productId;
        int quantity;
        bool isValid = false;
        productId = getInputInt("Enter product ID: ", 1, 10);
        quantity = getInputInt("Enter quantity: ");

        for (int i = 0; i < 10; i++) {
            if (catalog.products[i].getId() == productId) {
                cart.addToCart(productId, quantity);
                break;
            }
        }
    }

    void viewCart() {
        printTitle ("Shopping Cart");
        cart.printCart();
        bool checkout = askYesOrNo("Do you want to checkout all the products? (y/n): ");
        if (checkout) {
            printTitle("Checkout");
            cart.printCart();
            cout << "Total: " << fixed << setprecision(2) << cart.getTotal() << endl << endl;

            int paymentMethod;
            cout << "Select payment method: " << endl;
            cout << "\t[1] Cash" << endl;
            cout << "\t[2] Credit / Debit Card" << endl;
            cout << "\t[3] Gcash" << endl;
            paymentMethod = getInputInt("Enter payment method: ", 1, 3);

            paymentContext payment;
            switch (paymentMethod) {
                case 1: payment.setPaymentMethod(new Cash());
                case 2: payment.setPaymentMethod(new CreditDebitCard());
                case 3: payment.setPaymentMethod(new Gcash());
                default: cout << "Invalid payment method" << endl;
            }

            orders[orderId-1] = new Order(orderId, cart, cart.getTotal(), paymentMethod);

            payment.payOrder(orderId);
            orderId++;
        }
    }
};