#include "Sigs.hpp"
#include "Class.hpp"
#include "Function.hpp"

Utils::Fn<Player*, ClientInstance*, uintptr_t*> GetPlayer = Utils::CreateFastCall<Player*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getplayer));
Utils::Fn<uintptr_t*, ClientInstance*, uintptr_t*> GetEntityList = Utils::CreateFastCall<uintptr_t*, ClientInstance*, uintptr_t*>(Utils::GetAddressfromSignature(getentitylist));