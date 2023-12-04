cmake_minimum_required(VERSION 3.16)

project(TinyRobotSystem
	VERSION 1.0.0
	DESCRIPTION "A C++ System for Robot Programing"
	HOMEPAGE_URL ""
	LANGUAGES CXX
)

# Cross Platform Support
if(CMAKE_SYSTEM_NAME MATCHES "Linux") 
    set(SC_PUBLIC_PTHREAD PUBLIC pthread)
	add_definitions(-DSC_LINUX)

	add_compile_options(-fconcepts)
	message("You may need add new line in your cmake: 'add_compile_options(-fconcepts)' ")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows") 
    set(SC_PUBLIC_PTHREAD)
	add_definitions(-DSC_WINDOWS)
else()
    message(WARNING "The reliablity of this project on platforms except Windows|Linux are not guranteed")
endif()

aux_source_directory(Sources SentryLibSources)
add_library(${PROJECT_NAME} ${SentryLibSources})
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC Headers)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME}
)

aux_source_directory(Testers TesterSources)
foreach(TesterSource ${TesterSources})
	get_filename_component(TesterName ${TesterSource} NAME)
	message("Found Tester: ${TesterName} -> ${TesterSource}")

	add_executable(${TesterName} ${TesterSource})
	set_target_properties(${TesterName} PROPERTIES CXX_STANDARD 20)
	target_link_libraries(${TesterName} PRIVATE ${PROJECT_NAME})
endforeach()