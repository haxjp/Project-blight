#include "Level.hpp"
#include "Utils.hpp"
vector<Actor*> Level::getRuntimeActorList() {
	vector<Actor*> ActorList;
	Utils::CallVF<vector<Actor*>, decltype(&ActorList)>(this, 3, &ActorList);
	return ActorList;
}