#include "ClassRoom.h"
#include "ClassExit.h"
#include "ClassPlayer.h"
#include "ClassCommand.h"
#include <vector>

class World
{
private:

	Room* rooms = nullptr;
	Exit* exits = nullptr;
	Player* adventurer = nullptr;
	bool playing;
	
public:

	World();

	void CheckRoom(int i)const;
	void Execute(char instruction[25], int dir, int &position)const;
	bool Continue()const;

	void CreateWorld();
	void EndGame();

	~World();
};