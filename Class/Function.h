#pragma once
#include <iostream>
using namespace std;

//Prints a formatted title with a border
void printTitle(const string &title) {
    system("cls"); //Clear console screen (Windows-specific)
    int length = title.length(); //Get the length of the title
    int padding = max(10, 30 - length); //Calculate padding
    string border(padding, '=');
    cout << "\n" << border << " " << title << " " << border << "\n" << endl; //Print the title
}

//Function to get string input of user
string getInput(string prompt) {
    string input;
    cout << prompt; //Print the prompt
    getline(cin, input); //Get user input
    return input;
}

int getInputInt(string prompt, int minVal, int maxVal) {
    string input = getInput(prompt);
    int output;
    bool isValid = false;
    do {
        try{
            output = stoi(input);
            if (output < minVal || output > maxVal) { //Check if the input is out of range
                throw out_of_range("Please enter a number between " + to_string(minVal) + " and " + to_string(maxVal) + ".");
            }
            isValid = true;
        }catch (invalid_argument& e) {
            cout << "Error: Please enter a valid number." << endl << endl;
        }catch (out_of_range& e) {
            cout << "Error: " << e.what() << endl << endl;
        }
    }while (!isValid);
    return output;
}

int getInputInt(string prompt) {
    string input = getInput(prompt);
    int output;
    bool isValid = false;
    do {
        try{
            output = stoi(input);
            isValid = true;
        }catch (invalid_argument& e) {
            cout << "Error: Please enter a valid number." << endl << endl;
        }catch (out_of_range& e) {
            cout << "Error: " << e.what() << endl << endl;
        }
    }while (!isValid);
    return output;
}

//Asks the user a Yes/No question and validates input
void askYesOrNo(string question, char &yOrN) {
    string placeholder;
    do {
        cout << endl << question; //Print the question
        getline(cin, placeholder); //Get user input
        yOrN = tolower(placeholder[0]);
    } while (placeholder.length() != 1 || (yOrN != 'y' && yOrN != 'n')); //Loop until the input is valid
}



