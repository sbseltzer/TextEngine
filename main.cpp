#include "include/NEngine.hpp"
#include "include/CGame.hpp"
#include <stdio.h>

class MyGame : public Game {
	void OnStart() {
		printf("Starting...\n");
	}
	void OnTerminate() {
		printf("Terminating...\n");
	}
	void OnRender(Canvas canvas) {}
	void OnUpdate(const float delta) {
		printf("Updated: %f %f\n", delta, CurTime());
	}
	void OnKeyDown(char key) {
		if (key == 'q')
			Terminate();
	}
	void OnKeyUp(char key) {}
	void OnMouseDown(char button, unsigned int x, unsigned int y) {}
	void OnMouseUp(char button, unsigned int x, unsigned int y) {}
};

int main(int argc, char **argv) {
	MyGame *game = new MyGame();
	game->Initialize(argc, argv, "My Awesome Game", 512, 512);
	game->Start();
	delete game;
}