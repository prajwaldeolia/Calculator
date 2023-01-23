#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <sqlite3.h>


class DB_LITE
{
	private:
		// Pointer to SQLite connection
    	sqlite3 *my_db;

    	// Save any error messages
    	char *my_zErrMsg;

    	// Save the result of opening the file
    	int my_rc;

    	// Saved SQL
    	std::string my_sql;

    	// Compiled SQLite Statement
    	sqlite3_stmt *my_stmt;

		// boolean to save id
		bool my_id = false;
		
	private:
    	// Create a callback function  
		static int my_callback(void *NotUsed, int argc, char **argv, char **azColName)
        {
		    // int argc: holds the number of results
		    // (array) azColName: holds each column returned
		    // (array) argv: holds each value

		    for(int i = 0; i < argc; i++)
                std::cout << azColName[i] << ": " << argv[i] << std::endl;
                // Show column name, value, and newline
		    std::cout<<std::endl;
		    // Return successful
		    return 0;
		}

		void my_checkDBErrors()
        {
			if( my_rc )
            {
		        // Show an error message
		        std::cout << "DB Error: " << sqlite3_errmsg(my_db) << std::endl;    
		        closeDB();
    		}

		}



		DB_LITE(const DB_LITE& ) = delete;

		DB_LITE()
        {
			// Save the result of opening the file
    		my_rc = sqlite3_open("history.db", &my_db);

    		my_checkDBErrors();
		}


	public:

		static DB_LITE& Get()
		{
			static DB_LITE instance;
			return instance;
		}

		void createTable()
        {

		    // Save SQL to create a table
		    my_sql = "CREATE TABLE HISTORY (ID INTEGER PRIMARY KEY AutoIncrement, QUERY TEXT NOT NULL, RESULT REAL);";
		    
		    // Run the SQL
		    my_rc = sqlite3_exec(my_db, my_sql.c_str(), my_callback, 0, &my_zErrMsg);

		}

		void insertData(const char* QUERY, const char* RESULT)
        {
			char* query;

			// Build a string using asprintf()
			if(my_id)
				asprintf(&query, "INSERT INTO HISTORY (QUERY, RESULT) VALUES  ('%s', '%s');", QUERY, RESULT);
			else
			{
				my_id = true;
				asprintf(&query, "INSERT INTO HISTORY (ID, QUERY, RESULT) VALUES ('%s', '%s', '%s');", "1", QUERY, RESULT);
			}

			// Prepare the query
		    sqlite3_prepare(my_db, query, strlen(query), &my_stmt, NULL);

		    // Test it
			my_rc = sqlite3_step(my_stmt);

			// Finialize the usage
			sqlite3_finalize(my_stmt); 

		}

		void showTable()
        {
			// Save SQL insert data
    		my_sql = "SELECT * FROM HISTORY";
    
   			// Run the SQL
    		my_rc = sqlite3_exec(my_db, my_sql.c_str(), my_callback, 0, &my_zErrMsg); 
		}

		void deleteRow(const char* ID)
        {
			char* query;

			// Build a string using asprintf()
			asprintf(&query, "DELETE FROM 'HISTORY' WHERE ID = '%s';", ID);

			// Prepare the query
		    sqlite3_prepare(my_db, query, strlen(query), &my_stmt, NULL);

		    // Test it
			my_rc = sqlite3_step(my_stmt);

			// Finialize the usage
			sqlite3_finalize(my_stmt);     

		}

		void closeDB()
        {
			// Close the SQL connection
    		sqlite3_close(my_db);
		}
};