#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include "openai.h"
#include "json.hpp"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::cout.write(static_cast<char*>(contents), totalSize);
    return totalSize;
}

openai::openai() {
    TOKEN = std::getenv("OPENAI_API_KEY");
}

std::string openai::getCompletion(std::string prompt) {
    // Create a json object
    nlohmann::json j = nlohmann::json::parse(R"(
        {
            "model": "gpt-3.5-turbo",
            "messages": [
                {"role": "user", "content": "Say this is a test!"}
            ],
            "temperature": 0.7
        }
    )");

    std::cout << j["model"] << std::endl;

    CURL *curl = curl_easy_init();

    std::string content = "";

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        std::string authHeader = "Authorization: Bearer " + TOKEN;
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, authHeader.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, j.dump().c_str());

        std::string response;

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        //nlohmann::json jsonResponse = nlohmann::json::parse(response);

        //std::cout << jsonResponse["choices"][0]["message"] << std::endl;

        //content = jsonResponse["choices"][0]["text"].get<std::string>();

        //std::cout << content << std::endl;

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return content;
}

