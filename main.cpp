#include <string.h>
#include <stdio.h>
#include "voice.h" 

#define BUFSIZE 1024

char text[BUFSIZE];

int main(int argc, char* argv[]) {
    VoiceClass voice;
    
    while (true) {
        printf("Enter msg: ");
        fgets(text, BUFSIZE, stdin);
        text[strcspn(text, "\n")] = '\0';
        voice.speak(text);
    }

    return 0;
}