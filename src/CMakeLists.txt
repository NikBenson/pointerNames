set(LIB_SOURCES
		library.c
		)

set(HEADERS
		${CONFIG_HEADER}
		library.h
		)

set(MAIN_SOURCES
		library.c
		)

add_library(PointerNames STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(pointerNames ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(pointerNames PointerNames)

install(TARGETS PointerNames
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PointerNames.h DESTINATION include)

