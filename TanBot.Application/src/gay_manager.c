#include <string.h>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "gay_manager.h"
#include "helpers/string_helper.h"
#include "persistence/gay_access.h"

#define MAX_USERNAME_LENGTH 40

char* parse_username(const char* message) {
	if (strlen(message) > MAX_USERNAME_LENGTH)
		return NULL;

	char* msg = (char*)malloc(strlen(message) + 1);
	
	strncpy_s(msg, strlen(message) + 1, message, strlen(message));
	const char* delim = " ";
	char* next_token = NULL;

	char* token = strtok_s(msg, delim, &next_token);
	token = strtok_s(NULL, delim, &next_token);

	return token;
}

void free_username(char* username) {
	free(username);
}

void add_to_gay_counter(const char* message) {
	char* username = parse_username(message);

	if (is_user_exists(username)) {

	}
	else {

	}

	free_username(username);
}