cmake_minimum_required(VERSION 3.12)
project(boost-python-test)

find_package(Python COMPONENTS Development)
find_package(Boost COMPONENTS python36 numpy36 REQUIRED)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${Boost_LIBRARIES} ${Python_LIBRARIES})