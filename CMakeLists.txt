cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
#add_compile_options(-std=c++11)
project(advancedC)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )



add_executable(lambda1 src/lambda1.cpp)


add_executable(1_boost_macro src/1_boost_macro.cpp )
target_link_libraries( 1_boost_macro LINK_PUBLIC ${Boost_LIBRARIES} )


add_executable(2_shared_pointer src/2_boost_shared_pointer.cpp )
target_link_libraries(2_shared_pointer LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(3_boost_distributions src/3_boost_distributions.cpp )
target_link_libraries(3_boost_distributions LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(4_boost_random_number src/4_boost_random_number.cpp )
target_link_libraries(4_boost_random_number LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(5_boost_function src/5_boost_function.cpp )
target_link_libraries(5_boost_function LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(6_boost_bind src/6_boost_bind.cpp )
target_link_libraries(6_boost_bind LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(7_boost_any src/7_boost_any.cpp )
target_link_libraries(7_boost_any LINK_PUBLIC ${Boost_LIBRARIES} )
