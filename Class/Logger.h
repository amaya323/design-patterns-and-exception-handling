#pragma once

#include <iostream>
#include <cstdio>
using namespace std;

class Logger {
private:
    static Logger instance;
    FILE* log;
    Logger() {
        log = fopen("../Log.txt", "a+");
    }

public:
    void logOrder(const string& message) {
        fputs (message.c_str(), log);
        fputs("\n", log);

    }

    static Logger& getInstance() {
        return instance;
    }

    int getOrderCount() {
        int numberOfLines = 0;
        char c;
        while ((c = fgetc(log)) != EOF) {
            if (c == '\n') {
                numberOfLines++;
            }
        }
        return numberOfLines;
    }

    ~Logger() {
        if (log != nullptr) {
            fclose(log);  // Close the log file
        }
    }
};

Logger Logger::instance;