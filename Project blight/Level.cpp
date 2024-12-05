#include "Level.hpp"
#include "Utils.hpp"
vector<Actor*> Level::getRuntimeActorList() {
	vector<Actor*> ActorList;
	cout << Utils::CallVF<uintptr_t*>(this, 220) << endl;
	return ActorList;
}