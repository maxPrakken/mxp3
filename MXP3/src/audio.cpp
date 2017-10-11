#include "..\include\audio.h"

Audio* Audio::instance = NULL;

Audio::Audio()
{
	//initialize SDL audio mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	//load audio files
	sound = Mix_LoadWAV(MUS_PATH);
}

Audio::~Audio()
{ 
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
}

void Audio::update()
{
	
}

void Audio::playAudio()
{
	Mix_PlayChannel(-1, sound, 0);
	std::cout << "am i playing sound?" << std::endl;
}


Audio * Audio::getInstance()
{
	if (instance == NULL) {
		instance = new Audio();
	}
	return instance;
}
