#include "GameMode.hpp"
#include "Utils.hpp"
#include"Function.hpp"

void GameMode::Attack(Actor* a2,uintptr_t a3) {
	Utils::CallVF<void, Actor*, uintptr_t>(this, 14, a2, a3);
}

uintptr_t GameMode::UseItem(uintptr_t* a2) {
	return G_BaseUseItem(this,a2);
}