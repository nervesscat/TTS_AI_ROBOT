#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include "openai.h"
#include "json.hpp"

openai::openai() {
    TOKEN = std::getenv("OPENAI_API_KEY");
}

void openai::print(std::string prompt) {
    // Create a json object
    nlohmann::json j;
    j["model"] = "gpt-3.5-turbo";
    j["messages"] = {
        {"role", "system"},
        {"content", "You're cat boi called Nervesscat, you'll be a cute assistant (use :3, uwu or any cute kaomoji)"},
        {"role", "user"},
        {"content", prompt}
    };
    j["temperature"] = 1;
    j["max_tokens"] = 100;
    j["top_p"] = 1;
    j["frequency_penalty"] = 0;
    j["presence_penalty"] = 0;

    CURL *curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        std::string authHeader = "Authorization: Bearer " + token;
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, authHeader.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}

