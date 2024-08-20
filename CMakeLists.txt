cmake_minimum_required(VERSION 3.8)
project(test_zenoh)

add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wno-format-security
                    -std=c++17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

add_library(subscription_test SHARED src/subscription_test.cpp)

target_include_directories(
  subscription_test
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

ament_target_dependencies(subscription_test PUBLIC rclcpp std_msgs std_srvs)

add_executable(subscription_test_exe src/subscription_test_exe.cpp)

target_link_libraries(subscription_test_exe subscription_test)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

install(TARGETS subscription_test_exe DESTINATION lib/${PROJECT_NAME})

install(TARGETS subscription_test EXPORT subscription_testTargets)

install(DIRECTORY include/ DESTINATION include)

ament_package()
