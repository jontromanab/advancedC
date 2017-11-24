cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
#add_compile_options(-std=c++11)
project(advancedC)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )



add_executable(lambda1 src/lambda1.cpp)


add_executable(1_boost_macro src/1_boost_macro.cpp )
target_link_libraries( 1_boost_macro LINK_PUBLIC ${Boost_LIBRARIES} )
