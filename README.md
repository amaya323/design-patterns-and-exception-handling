# E-Commerce System with Design Patterns
## Description
This project implements a simple e-commerce system for an online store using Object-Oriented Programming principles and design patterns. The system demonstrates the use of Singleton and Strategy patterns for payment processing, along with proper exception handling.

## Features
  - Product Management: View available products and add them to your shopping cart
  - Shopping Cart: Manage selected products before checkout
  - Order Processing: Complete purchases with multiple payment options
  - Order History: View past orders with detailed information
  - Log Order

## Design Patterns Implemented
  - Singleton Pattern: Used for the payment processor to ensure a single instance handles all payments
  - Strategy Pattern: Implemented for different payment methods (Cash, Credit/Debit Card, GCash)

## OOP Principles Applied
  - Encapsulation: Data and methods are properly encapsulated within classes. Provides controlled access to the data inside the class.
  - Abstraction: Complex payment processing is hidden behind simple interfaces
  - Inheritance: Payment strategies inherit from a common interface or abstract class
  - Polymorphism: Different payment methods have the same functions that runs differently
