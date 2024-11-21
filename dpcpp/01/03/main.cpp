#include "sql_query_builder.h"
#include <cassert>

int main() {

    AdvancedSqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({"name", "phone"});
    query_builder.AddFrom("students");
    query_builder.AddWhereGreater("id", "42"); 
    assert(query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id>42;");

    return 0;
}
