cmake_minimum_required(VERSION 3.20)
project(E_Commerce
        VERSION 1.0
        DESCRIPTION "E-Commerce System with Design Patterns"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List all source files
set(SOURCE_FILES
        main.cpp
        # Add additional .cpp files here when you create them
)

# List all header files
set(HEADER_FILES
        Class/ShoppingCart.h
        Class/Logger.h
        Class/PaymentStrategies.h
        Class/Product.h
        Class/Order.h
        Class/Product.h
        Class/CartItem.h
        Class/ProductCatalog.h
        Class/Function.h
        Class/Shop.h
)

# Create the executable
add_executable(E_Commerce ${SOURCE_FILES} ${HEADER_FILES})

# For better IDE support (optional)
target_include_directories(E_Commerce PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Enable more warnings (optional)
if(MSVC)
    target_compile_options(E_Commerce PRIVATE /W4 /WX)
else()
    target_compile_options(E_Commerce PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# C++20 features (optional)
target_compile_features(E_Commerce PRIVATE cxx_std_20)