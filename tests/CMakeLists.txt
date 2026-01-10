file(GLOB TEST_SOURCES "*.cpp")

add_executable(TaskManagerTests ${TEST_SOURCES})

target_link_libraries(
    TaskManagerTests
    TaskManagerLib
    gtest
    gtest_main
)

add_test(NAME TaskManagerTests COMMAND TaskManagerTests)
