#include <stdlib.h>

#include "message_handler.h"
#include "gay_manager.h"

void handle_message(CLIENT_MESSAGE* message) {
	COMMAND command = parse_command(message->message);

	switch (command) {
	case GAY_COUNT:
		add_to_gay_counter(message->message);
	}
}

CLIENT_MESSAGE* create_client_message(anyID fromID, char* fromName, char* fromUniqueIdentifier, char* message) {
	CLIENT_MESSAGE* new_client_message = (CLIENT_MESSAGE*) malloc(sizeof(CLIENT_MESSAGE));

	new_client_message->fromID = fromID;
	new_client_message->fromName = fromName;
	new_client_message->fromUniqueIdentifier = fromUniqueIdentifier;
	new_client_message->message = message;

	return new_client_message;
}