#include <stdlib.h>
#include <stdio.h>

#include "data_access.h"

static SQLHENV env;
static SQLHDBC dbc;

bool create_data_access_handle() {
	SQLRETURN ret; /* ODBC API return status */
	bool result;

				   /* Allocate an environment handle */
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	/* We want ODBC 3 support */
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);
	/* Allocate a connection handle */
	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
	/* Connect to the DSN mydsn */
	ret = SQLDriverConnect(dbc, NULL, "DSN=TanBot_Development;", SQL_NTS,
		NULL, 0, NULL,
		SQL_DRIVER_COMPLETE);
	if (SQL_SUCCEEDED(ret)) {
		SQLCHAR dbms_name[256], dbms_ver[256];
		SQLUINTEGER getdata_support;
		SQLUSMALLINT max_concur_act;

		printf("Connected\n");
		result = true;

		/*
		*  Find something out about the driver.
		*/
		SQLGetInfo(dbc, SQL_DBMS_NAME, (SQLPOINTER)dbms_name,
			sizeof(dbms_name), NULL);
		SQLGetInfo(dbc, SQL_DBMS_VER, (SQLPOINTER)dbms_ver,
			sizeof(dbms_ver), NULL);
		SQLGetInfo(dbc, SQL_GETDATA_EXTENSIONS, (SQLPOINTER)&getdata_support,
			0, 0);
		SQLGetInfo(dbc, SQL_MAX_CONCURRENT_ACTIVITIES, &max_concur_act, 0, 0);

		printf("DBMS Name: %s\n", dbms_name);
		printf("DBMS Version: %s\n", dbms_ver);
		if (max_concur_act == 0) {
			printf("SQL_MAX_CONCURRENT_ACTIVITIES - no limit or undefined\n");
		}
		else {
			printf("SQL_MAX_CONCURRENT_ACTIVITIES = %u\n", max_concur_act);
		}
		if (getdata_support & SQL_GD_ANY_ORDER)
			printf("SQLGetData - columns can be retrieved in any order\n");
		else
			printf("SQLGetData - columns must be retrieved in order\n");
		if (getdata_support & SQL_GD_ANY_COLUMN)
			printf("SQLGetData - can retrieve columns before last bound one\n");
		else
			printf("SQLGetData - columns must be retrieved after last bound one\n");
	}
	else {
		fprintf(stderr, "Failed to connect\n");
		result = false;
	}

	return result;
}

void free_data_access_handle() {
	SQLDisconnect(dbc);		/* disconnect from driver */
	/* free up allocated handles */
	SQLFreeHandle(SQL_HANDLE_DBC, dbc);
	SQLFreeHandle(SQL_HANDLE_ENV, env);
}

SQLHDBC get_sql_handler() {
	return dbc;
}

SQLHENV get_env() {
	return env;
}