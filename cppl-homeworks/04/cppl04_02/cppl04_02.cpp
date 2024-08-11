#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "list.h"

TEST_CASE("List PushBack") {
    List list;

    list.PushBack(1);
    REQUIRE(list.Size() == 1);

    list.PushBack(2);
    REQUIRE(list.Size() == 2);

    list.PushBack(3);
    REQUIRE(list.Size() == 3);
    
    list.PushBack(4);
    REQUIRE(list.Size() == 4);
    
    list.PushBack(5);
    REQUIRE(list.Size() == 5);
}

TEST_CASE("List PushFront") {
    List list;

    list.PushFront(1);
    REQUIRE(list.Size() == 1);
    
    list.PushFront(2);
    REQUIRE(list.Size() == 2);

    list.PushFront(3);
    REQUIRE(list.Size() == 3);

    list.PushFront(4);
    REQUIRE(list.Size() == 4);
    
    list.PushFront(5);
    REQUIRE(list.Size() == 5);
}

TEST_CASE("List PopBack") {
    List list;

    CHECK_THROWS(list.PopBack());

    REQUIRE(list.Empty() == true);

    list.PushBack(1);
    list.PushBack(2);
    list.PopBack();
    REQUIRE(list.Size() == 1);
}

TEST_CASE("List PopFront") {
    List list;

    CHECK_THROWS(list.PopFront());

    REQUIRE(list.Empty() == true);

    list.PushBack(1);
    list.PushBack(2);
    list.PopFront();
    REQUIRE(list.Size() == 1);
}


