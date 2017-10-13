#include "..\include\audio.h"

Audio* Audio::instance = NULL;

Audio::Audio()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		printf("mixer initialization error: ", Mix_GetError());
	}
}

Audio::~Audio()
{
	Mix_Quit();
}

void Audio::update()
{

}

void Audio::playAudio(std::string filename)
{
	if (Mix_PlayChannel(-1, getChunk(filename), 0) == -1)
	{
		printf("Audio not working due to: ", Mix_GetError());
	}
}

void Audio::playAudio(std::string filename, int loop, int channel)
{
	if (Mix_PlayChannel(channel, getChunk(filename), loop) == -1)
	{
		printf("Audio not working due to: ", Mix_GetError());
	}
}

void Audio::pauseAudio() {
	Mix_Pause(-1);
}

void Audio::pauseAudio(int channel)
{
	Mix_Pause(channel);
}

void Audio::resumeAudio() {
	Mix_Resume(-1);
}

void Audio::resumeAudio(int channel)
{
	Mix_Resume(channel);
}

Mix_Chunk * Audio::getChunk(std::string filename)
{
	std::string fullpath = SDL_GetBasePath();
	fullpath.append("../Game/assets/audio/" + filename);

	if (sounds[fullpath] == NULL) {
		sounds[fullpath] = Mix_LoadWAV(fullpath.c_str());
		if (sounds[fullpath] == NULL) {
			printf("sounds loading error: File-%s Error -&s", filename.c_str(), Mix_GetError());
		}
	}
	return sounds[fullpath];
}

Audio * Audio::getInstance()
{
	if (instance == NULL) {
		instance = new Audio();
	}
	return instance;
}
