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


	//standard playaudio.
	void playAudio(std::string filename);
	//playaudio function,
	//filename is just the name of the file + the type.
	//loop is 0 on default. that means it plays once. -1 is infinite loop, 
	//and all above 0 is the amount it will loop.
	//channel is the channel, default -1. -1 it the next available channel.
	void playAudio(std::string filename, int loop, int channel);

	//pauses audio. -1 to pause all audio channels. all above 1 to pause seperate channels
	void pauseAudio(int channel);
	//resumes audio. -1 to resume all audio channels. all above 1 to resume seperate channels
	void resumeAudio(int channel);

	std::map<std::string, Mix_Chunk*> sounds;

	Mix_Chunk * getChunk(std::string filename);

private:
	static Audio* instance;

	Audio();
	virtual ~Audio();
};
