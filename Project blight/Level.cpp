#include "Level.hpp"
#include "Utils.hpp"
vector<Actor*> Level::getRuntimeActorList() {
	vector<Actor*> ActorList;
	Utils::CallVF<vector<Actor*>, decltype(&ActorList)>(this, 308, &ActorList);
	return ActorList;
}