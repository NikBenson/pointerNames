cmake_minimum_required(VERSION 3.16)
project(PointerNames LANGUAGES C VERSION 1.0.1 DESCRIPTION "give your pointers names")

set(CMAKE_C_STANDARD 99)

###############################################################################
# Set build features
set(DEFAULT_BUILD_TYPE Release)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

if(false)
###############################################################################
include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

###############################################################################
# Check headers
set(INCLUDES "")
macro(ck_check_include_file header var)
	check_include_files("${INCLUDES};${header}" ${var})
	if(${var})
		set(INCLUDES ${INCLUDES} ${header})
	endif(${var})
endmacro(ck_check_include_file)

ck_check_include_file("stdlib.h" HAVE_STDLIB_H)

###############################################################################
# Check functions
# (Nothing to check for the money example)

###############################################################################
# Check defines
# (Nothing to check for the money example)

###############################################################################
# Check struct members
# (Nothing to check for the money example)

###############################################################################
# Check for integer types
# (The following are used in check.h. Regardless if they are used in
# the project, they will need to be checked in order to use Check).
check_type_size(intmax_t INTMAX_T)
check_type_size(uintmax_t UINTMAX_T)

check_type_size(pid_t PID_T)
if(NOT HAVE_PID_T)
	if(WIN32)
		set(pid_t "int")
	else(WIN32)
		MESSAGE(FATAL_ERROR "pid_t doesn't exist on this platform?")
	endif(WIN32)
endif(NOT HAVE_PID_T)

###############################################################################
# Check libraries

###############################################################################
# Generate "config.h" from "cmake/config.h.cmake"
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
		${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

###############################################################################

ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(tests)

#ENABLE_TESTING()
#ADD_TEST(NAME check_convert COMMAND check_convert)
#endif()

include(GNUInstallDirs)

add_library(PointerNames SHARED src/PointerNames.h src/library.c)
set_target_properties(PointerNames PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION 1
		PUBLIC_HEADER api/PointerNames.h)
install(TARGETS PointerNames
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
configure_file(cmake/PointerNames.pc.in PointerNames.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/PointerNames.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

#install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PointerNames.h DESTINATION include)

endif()

include(GNUInstallDirs)

# Find source files
set(SOURCE_FILES src/PointerNames.h)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES
		LINKER_LANGUAGE C
		VERSION ${PROJECT_VERSION}
		SOVERSION 1)

install(TARGETS ${PROJECT_NAME} EXPORT PointerNamesConfig
		ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
		LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT PointerNamesConfig DESTINATION share/PointerNames/cmake)

export(TARGETS ${PROJECT_NAME} FILE PointerNamesConfig.cmake)
