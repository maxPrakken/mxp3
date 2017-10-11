#pragma once

//#include <SDL2\SDL_audio.h>
#include <SDL2\SDL_mixer.h>
#include <iostream>

#define MUS_PATH "test.wav"

//singleton audio
class _declspec(dllexport) Audio {
public:
	static Audio* getInstance();
	Audio();
	virtual void update();

	Audio* getAudio() {
		return audio;
	}

	Mix_Chunk* sound;

	void playAudio();

private:
	static Audio* instance;

	//Audio();
	virtual ~Audio();
	Audio* audio;
};