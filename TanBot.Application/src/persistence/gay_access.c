#include <string.h>
#include <stdio.h>

#include "gay_access.h"
#include "data_access.h"

bool is_user_exists(char* username) {
	SQLHDBC hstmt = get_sql_handler();
	SQLRETURN retcode;

	retcode = SQLPrepare(hstmt, 
		"SELECT COUNT(*) FROM GayCounter WHERE Username=?", 
		10);

	SQLLEN len = SQL_NTS;
	retcode = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 10, 0, username, 0, &len);
	retcode = SQLExecute(hstmt);

	if (SQL_SUCCEEDED(retcode = SQLFetch(hstmt)))
		return true;
	UCHAR errmsg[100];
	if (retcode == SQL_INVALID_HANDLE) {
		SQLError(get_env(), hstmt, SQL_NULL_HSTMT, NULL, NULL,
			errmsg, sizeof(errmsg), NULL);

		/* Assume that print_error is defined */
		printf("Failed SQLAllocStmt %s", errmsg);
	}

	return false;
}