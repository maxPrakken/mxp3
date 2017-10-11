#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_mixer.h>
#include <iostream>
#include <map>

//singleton audio
class _declspec(dllexport) Audio {
public:
	static Audio* getInstance();

	virtual void update();

	void playAudio(std::string filename, int loop = -1, int channel = 0);
	void pauseAudio();
	void resumeAudio();

	std::map<std::string, Mix_Chunk*> sounds;

	Mix_Chunk * getChunk(std::string filename);

private:
	static Audio* instance;

	Audio();
	virtual ~Audio();
};