#ifndef OPENAI_H
#define OPENAI_H

#include <string>

class openai{
private:
    //static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    std::string jsonStr;
    std::string TOKEN;
    std::string url = "https://api.openai.com/v1/chat/completions";

public:
    openai();
    std::string getCompletion(std::string prompt);
};

#endif