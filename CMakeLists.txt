cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
#add_compile_options(-std=c++11)
project(advancedC)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )



add_executable(lambda1 src/lambda1.cpp)
add_executable(const src/const.cpp)
add_executable(const_and_functions src/const_and_functions.cpp)
add_executable(const_logic_bitwise src/const_logic_bitwise.cpp)
add_executable(compiler_generated_function src/compiler_generated_function.cpp)
add_executable(disallow_functions src/disallow_functions.cpp)
add_executable(virtual_destructor src/virtual_destructor.cpp)
add_executable(exception_in_destructor src/exception_in_destructor.cpp)
add_executable(virtual_function_in_constructor src/virtual_function_in_constructor.cpp)
add_executable(self_assignment_operator src/self_assignment_operator.cpp)
add_executable(casting1 src/casting1.cpp)
add_executable(casting2 src/casting2.cpp)

add_executable(debug1 src/debug1.cpp)
add_executable(to_str_and_cstr src/to_str_and_cstr.cpp)


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

#add_executable(7_boost_any src/7_boost_any.cpp )
#target_link_libraries(7_boost_any LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(8_boost_optional src/8_boost_optional.cpp )
target_link_libraries(8_boost_optional LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(9_boost_serialization src/9_boost_serialization.cpp )
target_link_libraries(9_boost_serialization LINK_PUBLIC ${Boost_LIBRARIES} -lboost_serialization )

add_executable(9_boost_serialization_open src/9_boost_serialization_open.cpp )
target_link_libraries(9_boost_serialization_open LINK_PUBLIC ${Boost_LIBRARIES} -lboost_serialization )

add_executable(9_boost_serialization_class src/9_boost_serialization_class.cpp )
target_link_libraries(9_boost_serialization_class LINK_PUBLIC ${Boost_LIBRARIES} -lboost_serialization )

add_executable(10_boost_filesystem src/10_boost_filesystem.cpp )
target_link_libraries(10_boost_filesystem LINK_PUBLIC ${Boost_LIBRARIES}  -lboost_system -lboost_filesystem)


add_executable(11_boost_uBLAS src/11_boost_uBLAS.cpp )
target_link_libraries(11_boost_uBLAS LINK_PUBLIC ${Boost_LIBRARIES})
