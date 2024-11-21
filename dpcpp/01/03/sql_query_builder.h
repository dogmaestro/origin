#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>
#include <map>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        columns_.insert(columns_.end(), columns.begin(), columns.end());
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        table_ = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        where_clauses_.push_back(column + "=" + value);
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for (const auto& pair : kv) {
            where_clauses_.push_back(pair.first + "=" + pair.second);
        }
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

protected:
    std::vector<std::string> columns_;
    std::string table_;
    std::vector<std::string> where_clauses_;
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
public:
    AdvancedSqlSelectQueryBuilder& AddWhereGreater(const std::string& column, const std::string& value) {
        where_clauses_.push_back(column + ">" + value);
        return *this;
    }

    AdvancedSqlSelectQueryBuilder& AddWhereLess(const std::string& column, const std::string& value) {
        where_clauses_.push_back(column + "<" + value);
        return *this;
    }
};
