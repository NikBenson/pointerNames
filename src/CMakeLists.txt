set(LIB_SOURCES
		library.c
		)

set(HEADERS
		${CONFIG_HEADER}
		library.h
		)

add_library(PointerNames STATIC ${LIB_SOURCES} ${HEADERS})

target_link_libraries(PointerNames money)

install(TARGETS PointerNames
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/PointerNames.h DESTINATION include)

