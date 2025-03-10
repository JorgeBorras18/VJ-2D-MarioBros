#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE


#include "Sprite.h"
#include "TileMap.h"


// Player is basically a Sprite that represents the player. As such it has
// all properties it needs to track its movement, jumping, and collisions.


class Player
{

public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram);
	void reset();
	void update(int deltaTime, bool gameCompleted, bool couldBeGoingUnderworld, bool wantsToGoOverworld, bool pickingFlag);
	void render();

	int getMarioForm();
	void setMarioForm(int formId);
	void setTileMap(TileMap* tileMap);
	void setPosition(const glm::vec2& pos);
	void stopMarioFromMoving(const glm::vec2& pos);
	void applyBounce();

	glm::vec2 getPosition();
	glm::vec2 getPositioninTM();
	glm::ivec2 getSize();
	bool isFalling();
	bool isInvencible();
	bool inStarMode();
	bool takeDamage();
	void powerUp();
	float getFacingDirection();

private:

	//DEV
	int pressedPCount;
	bool pressedPandReleased;

	//OTHERS
	int actualAnimation;
	int actualForm;

	float actual_speed;
	float initial_jump_xspeed;
	float vertical_speed;
	float max_xspeed_allowed_jumping;
	bool bJumping;
	bool JumpedAndReleased;
	float facingDirection;

	int framesUntilSlowdown;
	int invencibleFrames;
	int starFrames;
	int dyingFrames;

	glm::ivec2 tileMapDispl;
	glm::vec2 posPlayer;
	int jumpAngle, startY;

	Sprite* sprite;
	Sprite* playerIntoCastle;

	TileMap* map;
	glm::ivec2 collision_box_size;

	//Diferent Mario Sprites & SpriteFiles
	Texture smallMarioSpritesheet;
	Texture normalMarioSpritesheet;
	Sprite* smallMarioSprite;
	Sprite* normalMarioSprite;
	Sprite* starMarioSprite;
	
	Sprite* initSmallMarioSprite(Texture* spritesheet, ShaderProgram* shaderProgram);
	Sprite* initNormalMarioSprite(float baseSpriteRow, Texture* spritesheet, ShaderProgram* shaderProgram);
	Sprite* initStarMarioSprite(Texture* spritesheet, ShaderProgram* shaderProgram);
	

};


#endif // _PLAYER_INCLUDE

