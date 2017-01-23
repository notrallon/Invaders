#include "Game.h"

/*
	Made By: Richard Norqvist


	RichardNorqvist_Invaders

	Lives:	🎮🎮🎮	Score: 325

	🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
	🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
	🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
	👾👾👾👾👾👾👾👾👾👾👾👾👾
	👾👾👾👾     💥  👾👾👾👾👾
	👾👾                  👾👾👾
	👾
					⬆️
			
			  

				  ⬆️


				🎮
*/

int32 main(int32 argc, char* argv[]) {
	while (Game::Instance()->IsRunning()) {
		Game::Instance()->HandleEvents();
		Game::Instance()->Update();
		Game::Instance()->Draw();
		Game::Instance()->LateUpdate();
	}
	return 0;
}
