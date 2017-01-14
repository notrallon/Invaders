#pragma once

#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <vector>

#include <SFML/Graphics.hpp>

typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

typedef int8_t		int8;
typedef int16_t		int16;
typedef int32_t		int32;
typedef int64_t		int64;

#define	PLAYER_MOVE_SPEED		250
#define ENEMY_SHIP_MOVE_SPEED	250

enum class direction_t {
	UP,
	DOWN,
	LEFT,
	RIGHT
};