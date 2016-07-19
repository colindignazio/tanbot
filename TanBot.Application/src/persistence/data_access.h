#pragma once

#include <stdbool.h>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

//const char* DSN = "TanBot_Development";

bool create_data_access_handle();
void free_data_access_handle();
SQLHDBC get_sql_handler();
SQLHENV get_env();


