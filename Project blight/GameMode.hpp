#pragma once

#include"Actor.hpp"
class GameMode {
public:
	void Attack(Actor*, uintptr_t);
	uintptr_t UseItem(uintptr_t*);
};