#include "Game.h"


/*
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

int32 main() {
	Game game;

	while (game.IsRunning()) {
		game.HandleEvents();
		game.Update();
		game.Draw();
		game.LateUpdate();
	}

	return 0;
}
