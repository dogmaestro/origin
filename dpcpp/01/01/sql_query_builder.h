#pragma once
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class SqlSelectQueryBuilder {
public:
  SqlSelectQueryBuilder &AddColumn(const std::string &column) {
    columns_.push_back(column);
    return *this;
  }

  SqlSelectQueryBuilder &AddFrom(const std::string &table) {
    table_ = table;
    return *this;
  }

  SqlSelectQueryBuilder &AddWhere(const std::string &column,
                                  const std::string &value) {
    where_clauses_.push_back(column + "=" + value);
    return *this;
  }

  std::string BuildQuery() const {
    std::stringstream query;
    query << "SELECT ";

    if (columns_.empty()) {
      query << "*";
    } else {
      for (size_t i = 0; i < columns_.size(); ++i) {
        query << columns_[i];
        if (i < columns_.size() - 1) {
          query << ", ";
        }
      }
    }

    query << " FROM " << table_;

    if (!where_clauses_.empty()) {
      query << " WHERE ";
      for (size_t i = 0; i < where_clauses_.size(); ++i) {
        query << where_clauses_[i];
        if (i < where_clauses_.size() - 1) {
          query << " AND ";
        }
      }
    }

    query << ";";

    return query.str();
  }

private:
  std::vector<std::string> columns_;
  std::string table_;
  std::vector<std::string> where_clauses_;
};
