#define VOICE_H

#include <malloc.h>
#include <espeak/speak_lib.h>

class VoiceClass{
private:
    espeak_POSITION_TYPE position_type;
    espeak_AUDIO_OUTPUT output;
    char *path=NULL;
    int Buflength = 1000, Options=0;
    void* user_data;
    t_espeak_callback *SynthCallback;
    espeak_PARAMETER Parm;

    char Voice[8] = {"English"};

    unsigned int Size,position=0, end_position=0, flags=espeakCHARS_AUTO, *unique_identifier;
public:
    VoiceClass();
    void speak(char* text);
};