#include "Sigs.hpp"
//dont forget adding SPACE at end start and end of string ex " 4C 8B 41 ? 4C "
/*1.21.30*/string getentitylist = " 48 89 5C 24 ? 57 48 81 EC 30 01 00 00 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 48 8B 19 ";
/*1.21.30*/string getplayer = " 48 83 EC 58 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 48 8D 91 ? ? ? ? 48 8D 4C 24 ? E8 ? ? ? ? 80 7C 24 ? ? 74 ? 4C 8B 5C 24 ";
/*1.21.30*/string getkeymap = " 48 83 EC 48 0F B6 C1 4C 8D 05 ";
/*1.21.30*/string update = " 48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC 20 03 00 00 ";
/*1.21.30*/string connectionrequest = " 40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC 18 02 00 00 0F 29 B4 24 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 49 8B D9 ";
/*1.21.30*/string getcurrentswingduration = " 48 89 5C 24 ? 57 48 83 EC ? 48 8B 15 ? ? ? ? 48 8B F9 ";
/*1.21.30*/string baseuseitem = " 48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 48 8B F2 48 8B F9 45 33 F6 4C 89 75 ? 48 8D 4D ? E8 ? ? ? ? 90 48 8B 5F ";
/*1.21.30*/string getitemhanded = " 48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 0F 29 B4 24 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 44 88 45 ? 4C 8B F2 ";


