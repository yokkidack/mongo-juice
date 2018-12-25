#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
#include <typeinfo>
#include <fstream>

#include "mongo_agent_nice.hpp"

TEST_CASE("Length test 0 - get_random_string")
{
    int length = 0;
    std::string a{ get_random_string(length) };
    REQUIRE(a.length() == length);
}


TEST_CASE("Length test 2 - get_random_string")
{
    int length = 2;
    std::string a=get_random_string(length);
    REQUIRE(a.length() == length);
}


TEST_CASE("Length test 3 - get_random_string")
{
    int length = 3;
    std::string a{ get_random_string(length) };
    REQUIRE(a.length() == length);
}


TEST_CASE("Length test 999999 - get_random_string")
{
    int length = 999999;
    std::string a{ get_random_string(length) };
    REQUIRE(a.length() == length);
}

TEST_CASE("Randomness - get_random_string")
{
    int length = 10;
    bool all_test_results_multiplication = true;
    for (int i = 0; i < 10; i++) {
        std::string a{ get_random_string(length) };
        std::string b{ get_random_string(length) };
        if (a == b) {
            all_test_results_multiplication = false;
            break;
        }
    }
    REQUIRE(all_test_results_multiplication);
}

TEST_CASE("write right - doc_string_to_file")
{
    std::string doc{
        "{\"pikachu\" : {\"name\" : \"pikachu\", \"type\" : \"electric\"}}"}; //sorry
    std::string filename{"test_text_file.txt"};
    doc_string_to_file(doc, filename);
    std::ifstream f(filename);
    std::string test_string;
    std::getline(f, test_string);
    REQUIRE( test_string == doc );
}

TEST_CASE("Length test 0 - get_random_key_eq_value_string")
{
    int key_length = 0;
    int value_length = 0;
    std::string a{ get_random_key_eq_value_string(key_length, value_length) };
    REQUIRE(a.length() == key_length + value_length + 1);
}

TEST_CASE("Length test 1 - get_random_key_eq_value_string")
{
    int key_length = 1;
    int value_length = 1;
    std::string a{ get_random_key_eq_value_string(key_length, value_length) };
    REQUIRE(a.length() == key_length + value_length + 1);
}

TEST_CASE("trivial 0 - nicer_file_numbers_from_i")
{
	int i = 0;
	std::string output = nicer_file_numbers_from_i(i);
	REQUIRE( output == "0000000000" );
}

TEST_CASE("trivial 10 - nicer_file_numbers_from_i")
{
	int i = 10;
	std::string output = nicer_file_numbers_from_i(i);
	REQUIRE( output == "0000000010" );
}

TEST_CASE("trivial 10000 - nicer_file_numbers_from_i")
{
	int i = 10000;
	std::string output = nicer_file_numbers_from_i(i);
	REQUIRE( output == "0000010000" );
}

TEST_CASE("trivial 1000000000 - nicer_file_numbers_from_i")
{
	int i = 1000000000;
	std::string output = nicer_file_numbers_from_i(i);
	REQUIRE( output == "1000000000" );
}

TEST_CASE("try 0 - number_length")
{
	int i = 0;
	unsigned int output = number_length(i);
	REQUIRE( output == 1 );
}

TEST_CASE("try 10 - number_length")
{
	int i = 10;
	unsigned int output = number_length(i);
	REQUIRE( output == 2 );
}

TEST_CASE("try 100 - number_length")
{
	int i = 100;
	unsigned int output = number_length(i);
	REQUIRE( output == 3 );
}

TEST_CASE("try 1000000000 - number_length")
{
	int i = 1000000000;
	unsigned int output = number_length(i);
	REQUIRE( output == 10 );
}