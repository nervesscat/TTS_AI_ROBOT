#include "voice.h"
#include <string.h>

VoiceClass::VoiceClass() {
    output = AUDIO_OUTPUT_PLAYBACK;
    int I, Run = 1, L;    
    espeak_Initialize(output, Buflength, path, Options ); 
    espeak_SetParameter(espeakRATE, 100, 0);
    espeak_SetVoiceByName(Voice);
    const char *langNativeString = "en"; //Default to US English
    espeak_VOICE voice;
        memset(&voice, 0, sizeof(espeak_VOICE)); // Zero out the voice first
        voice.languages = langNativeString;
        voice.name = "US";
        voice.variant = 1;
        voice.gender = 1;
        espeak_SetVoiceByProperties(&voice);
    unique_identifier = (unsigned int*) malloc(sizeof(unsigned int));
};

void VoiceClass::speak(char* text) {
    Size = strlen(text)+1;    
    espeak_Synth( text, Size, position, position_type, end_position, flags,
    unique_identifier, user_data );
    espeak_Synchronize( );
}