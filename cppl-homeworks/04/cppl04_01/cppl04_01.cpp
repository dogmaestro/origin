#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "list.h"

TEST_CASE("List Empty") {
    List list;
    REQUIRE(list.Empty() == true);
    
    list.PushBack(1);
    REQUIRE(list.Empty() == false);
}

TEST_CASE("List Size") {
    List list;
    REQUIRE(list.Size() == 0);
    
    list.PushBack(1);
    REQUIRE(list.Size() == 1);
    
    list.PushBack(2);
    REQUIRE(list.Size() == 2);
    
    list.PushFront(0);
    REQUIRE(list.Size() == 3);

    list.PopFront();
    REQUIRE(list.Size() == 2);
}

TEST_CASE("List Clear") {
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushFront(0);
    
    REQUIRE(list.Size() == 3);
    
    list.Clear();
    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}
