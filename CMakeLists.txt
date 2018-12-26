cmake_minimum_required(VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.123.tar.gz"
    SHA1 "57d07480686f82ddc916a5980b4f2a18e5954c2b"
)

project(mongo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "tests" OFF)

hunter_add_package (nlohmann_json)
hunter_add_package(BoostProcess)
hunter_add_package(Boost COMPONENTS program_options)
hunter_add_package(Boost COMPONENTS log)

# find_library( PTHREAD_LIBRARY pthread )

find_package ( libbson-1.0 1.7 REQUIRED )
find_package ( libmongoc-1.0 1.7 REQUIRED )
find_package ( nlohmann_json CONFIG REQUIRED )
find_package ( Boost CONFIG REQUIRED COMPONENTS program_options)
find_package ( Boost CONFIG REQUIRED log )
find_package ( BoostProcess CONFIG REQUIRED )

add_executable(
	mongo
	demo/mongo-agent.cpp 
    demo/easylogging++.cc
)

add_executable(
	sta
 	demo/super_agent.cpp
)

target_include_directories (mongo PRIVATE ${BSON_INCLUDE_DIRS})
target_include_directories (mongo PRIVATE "${MONGOC_INCLUDE_DIRS}")
target_link_libraries (mongo 
                       PRIVATE ${BSON_LIBRARIES}
		               PRIVATE "${MONGOC_LIBRARIES}" 
                       nlohmann_json
                       Boost::program_options
                       Boost::log
                      
                       )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/_3rdParty/easylogging++/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/_3rdParty/picosha2/)

target_compile_definitions (mongo PRIVATE ${BSON_DEFINITIONS})
target_compile_definitions (mongo PRIVATE "${MONGOC_DEFINITIONS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(sta BoostProcess::boost_process)


if(BUILD_TESTS)
  
  hunter_add_package(Catch)
  find_package(Catch CONFIG REQUIRED)

  enable_testing()

  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(
	tests-d 
	tests/mongo_agent_nice.cpp
  )
  target_link_libraries(tests-d Catch::Catch )
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
  add_test(NAME test_name COMMAND tests "-s" "-r" "compact" "--use-colour" "yes")

endif()