#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <unordered_map>

class HashMap {
private:
    std::unordered_map<std::string, int> map;

public:
    void insert(std::string key, int value) {
        map[key] = value;
    }

    int get(std::string key) {
        return map[key];
    }

    void remove(std::string key) {
        map.erase(key);
    }
};

// Test cases 
/*int main() {
    HashMap hm;
    hm.insert("a", 1);
    hm.insert("b", 2);
    hm.insert("c", 3);

    int a = hm.get("a");
    int b = hm.get("b");
    int c = hm.get("c");

    if (a == 1 && b == 2 && c == 3) {
        std::cout << "insert, get: success" << std::endl;
    }
    else {
        std::cout << "insert, get: fail" << std::endl;
    }

    hm.remove("b");
    if (hm.get("b") == 0) {
        std::cout << "remove: success" << std::endl;
    }
    else {
        std::cout << "remove: fail" << std::endl;
    }
    return 0;
}*/
TEST_CASE("HashMap test") {
    HashMap hm;
    hm.insert("a", 1);
    hm.insert("b", 2);
    hm.insert("c", 3);

    SUBCASE("insert, get") {
        REQUIRE(hm.get("a") == 1);
        REQUIRE(hm.get("b") == 2);
        REQUIRE(hm.get("c") == 3);
    }

    SUBCASE("remove") {
        hm.remove("b");
        REQUIRE(hm.get("b") == 0);
    }
}

TEST_CASE("Remove non-existent key") {
    HashMap hm;
    hm.insert("a", 1);
    hm.insert("b", 2);
    hm.insert("c", 3);

    hm.remove("d"); // key "d" does not exist

    REQUIRE(hm.get("a") == 1);
    REQUIRE(hm.get("b") == 2);
    REQUIRE(hm.get("c") == 3);
}
TEST_CASE("Insert and overwrite values") {
    HashMap hm;
    hm.insert("a", 1);
    hm.insert("b", 2);
    hm.insert("c", 3);
    hm.insert("a", 4);

    REQUIRE(hm.get("a") == 4);
    REQUIRE(hm.get("b") == 2);
    REQUIRE(hm.get("c") == 3);
}
