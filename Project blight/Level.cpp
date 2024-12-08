#include "Level.hpp"
#include "Utils.hpp"
vector<Actor*> Level::getRuntimeActorList() {
	vector<Actor*> ActorList;
	Utils::CallVF<void,vector<Actor*>&>(this, 306,ActorList);
	
	return ActorList;
}