#pragma once

#include "teamspeak/public_definitions.h"

#include "client_commands.h"

typedef struct {
	anyID fromID;
	char* fromName;
	char* fromUniqueIdentifier;
	char* message;
} CLIENT_MESSAGE;

void handle_message(CLIENT_MESSAGE* message);
CLIENT_MESSAGE* create_client_message(anyID fromID, char* fromName, char* fromUniqueIdentifier, char* message);
void free_client_message(CLIENT_MESSAGE* message);