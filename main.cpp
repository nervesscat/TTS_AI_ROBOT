#include <string>
#include <string.h>
#include <stdio.h>
#include "voice.h"
#include "openai.h"

#define BUFSIZE 1024

char text[BUFSIZE];

int main(int argc, char* argv[]) {
    VoiceClass voice;
    openai ai;
    std::string response = ai.getCompletion("Hello, I'm Sarah");
    while (true) {
        printf("Enter msg: ");
        fgets(text, BUFSIZE, stdin);
        text[strcspn(text, "\n")] = '\0';
        voice.speak(text);
    }

    return 0;
}