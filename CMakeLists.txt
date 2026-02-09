cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project( InfiniteBlackjackTest )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE InfiniteBlackjackTest )

include_directories( inc )

ADD_EXECUTABLE(InfiniteBlackjack "src/InfiniteBlackjack.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_RandomCardValueTest ${APP_EXECUTABLE} 1)
add_test(${APP_EXECUTABLE}_RandomCardSuitTest ${APP_EXECUTABLE} 2)
add_test(${APP_EXECUTABLE}_ShowCardValueTest ${APP_EXECUTABLE} 3)
add_test(${APP_EXECUTABLE}_ShowCardSuitTest ${APP_EXECUTABLE} 4)
add_test(${APP_EXECUTABLE}_DealCardAndTotalTest ${APP_EXECUTABLE} 5)
add_test(${APP_EXECUTABLE}_HasBlackjackTest ${APP_EXECUTABLE} 6)
add_test(${APP_EXECUTABLE}_HasBustedTest ${APP_EXECUTABLE} 7)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()