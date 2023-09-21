#ifndef OPENAI_H
#define OPENAI_H

#include <string>

class openai{
private:
    std::string jsonStr;
    std::string TOKEN;
    std::string url = "https://api.openai.com/v1/chat/completions";
    openai();
    void print();
};

#endif