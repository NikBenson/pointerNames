message("testing ${PROJECT_NAME}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# If pkg-config is not installed on the system, then the
# CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may
# be: C:/Program Files/check
#set(CHECK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../check-0.15.0/)


LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

set(TEST_SOURCES
        check_convert.c
        )

add_executable(check_convert ${TEST_SOURCES})
target_link_libraries(check_convert PRIVATE ${LIBCHECK_LDFLAGS})
