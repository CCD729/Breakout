#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "GameObject.h"

namespace gm {
	enum SFX {
		levelComplete = 0,
		loseBall = 1, 
		gameOver = 2, 
		bounceWall = 3, 
		bouncePaddle = 4,
		bounceBrick = 5, 
		bounceBrickDamage = 6
	};
	class SoundManager
	{
	protected:
		sf::SoundBuffer levelComplete, loseBall, gameOver, bounceWall, bouncePaddle, bounceBrick, bounceBrickDamage;
		sf::Sound sound;
	public:
		SoundManager();
		void PlaySFX(SFX sfx);
		~SoundManager();
	};
}
#endif