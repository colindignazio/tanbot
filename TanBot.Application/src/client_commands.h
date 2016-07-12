#pragma once

#include <string.h>

typedef enum {
	GAY_COUNT
} COMMAND;

COMMAND parse_command(char* message);