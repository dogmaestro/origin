#include "sql_query_builder.h"
#include <cassert>

int main() {

  SqlSelectQueryBuilder query_builder;
  query_builder.AddColumn("name").AddColumn("phone");
  query_builder.AddFrom("students");
  query_builder.AddWhere("id", "42").AddWhere("name", "John");
  assert(query_builder.BuildQuery() ==
         "SELECT name, phone FROM students WHERE id=42 AND name=John;");

  SqlSelectQueryBuilder query_builder2;
  query_builder2.AddColumns({"name", "phone"});
  query_builder2.AddFrom("students");
  assert(query_builder2.BuildQuery() == "SELECT name, phone FROM students;");

  SqlSelectQueryBuilder query_builder3;
  query_builder3.AddColumns({"name", "phone"});
  query_builder3.AddFrom("students");
  std::map<std::string, std::string> where_conditions;
  where_conditions["id"] = "42";
  where_conditions["name"] = "John";
  query_builder3.AddWhere(where_conditions);
  assert(query_builder3.BuildQuery() ==
         "SELECT name, phone FROM students WHERE id=42 AND name=John;");

  return 0;
}
