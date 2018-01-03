cmake_minimum_required(VERSION 2.8)

#if(CMAKE_COMPILER_IS_GNUCXX)
    #add_definitions(-std=gnu++11)
#endif()

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
#add_compile_options(-std=gnu++11)

project(Threading)


add_executable(thread_example src/thread_example.cpp)
add_executable(thread_1 src/thread_1.cpp)
add_executable(thread_2 src/thread_2.cpp)
add_executable(thread_3 src/thread_3.cpp)
add_executable(thread_4 src/thread_4.cpp)
add_executable(thread_5 src/thread_5.cpp)
#add_executable(thread_6 src/thread_6.cpp)

add_executable(threadEx1   src/threadEx1.cpp)
add_executable(threadEx2   src/threadEx2.cpp)
add_executable(threadEx3   src/threadEx3.cpp)
add_executable(threadEx4   src/threadEx4.cpp)
add_executable(threadEx5   src/threadEx5.cpp)

add_executable(introduction src/introduction.cpp)
add_executable(thread_management src/thread_management.cpp)
add_executable(race_condition_mutex src/race_condition_and_mutex.cpp)
add_executable(deadlock src/deadlock.cpp)
add_executable(unique src/unique_lock_and_lazy_initialization.cpp)
add_executable(condition_variable src/condition_variable.cpp)
add_executable(future_promise src/future_promise.cpp)
add_executable(callable_objects src/callable_objects.cpp)
add_executable(packaged_task src/packaged_task.cpp)
#add_executable(time_constraints src/time_constraints.cpp)


