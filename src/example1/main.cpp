#include <iostream>
#include "../SQLiteC++/SQLiteC++.h"

int main (void)
{
    try
    {
        // Open a database file
        SQLite::Database    db("example.db3");
        std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully\n";

        // Compile a SQL query, containing one parameter (index 1)
        SQLite::Statement   query(db, "SELECT * FROM test WHERE size>?");
        std::cout << "SQLite statement '" << query.getQuery().c_str() << "' compiled (" << query.getColumnCount () << " columns in the result)\n";
        // Bind an integer value "6" to the first parameter of the SQL query
        query.bind(1, 6);

        while (query.executeStep())
        {
            std::cout << "row : (" << query.getColumn(0).getInt() << ", " << query.getColumn(1).getText() << ", " << query.getColumn(2).getInt() << ")\n";
        }
    }
    catch (std::exception& e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
    }

    return 0;
}
