#include "sigs.hpp"

vector<int> gametick = { 0x48, 0x89, 0x5C, 0x24, -1, 0x48, 0x89, 0x6C, 0x24, -1, 0x48, 0x89, 0x7C, 0x24, -1, 0x41, 0x56, 0x48, 0x83, 0xEC, 0x30, 0x49, 0x8B, 0x00 };
vector<int> entitylist = { 0x4C, 0x8B, 0x41, -1, 0x4C, 0x8B, 0xC9, 0x48, 0x8B, 0x41, -1, 0x4C, 0x8B, 0x51, -1, 0x49, 0x2B, 0xC0, 0x48, 0xC1, 0xF8, 0x03, 0x48, 0xFF, 0xC8, 0x25, 0x18, 0x58, 0x2A, 0x13 };