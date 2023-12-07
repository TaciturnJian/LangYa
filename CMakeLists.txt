cmake_minimum_required(VERSION 3.16)

project(TinyRobotSystem
	VERSION 1.0.0
	DESCRIPTION "A C++ Program for Robots"
	HOMEPAGE_URL ""
	LANGUAGES CXX
)

add_subdirectory(SentryLib)

# Cross Platform Support
if(CMAKE_SYSTEM_NAME MATCHES "Linux") 
    set(SC_PUBLIC_PTHREAD PUBLIC pthread)
	add_definitions(-DSC_LINUX)

	add_compile_options(-fconcepts)
	message("${PROJECT_NAME}> Added -fconecpts in compile options")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows") 
    set(SC_PUBLIC_PTHREAD)
	add_definitions(-DSC_WINDOWS)
else()
    message(WARNING "The reliablity of this project on platforms except Windows|Linux are not guranteed")
endif()

aux_source_directory(Sources TinyRobotSystemSources)
add_executable(${PROJECT_NAME} ${TinyRobotSystemSources})
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC Headers)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME}
	SentryLib
)

aux_source_directory(Testers TesterSources)
foreach(TesterSource ${TesterSources})
	get_filename_component(TesterName ${TesterSource} NAME_WLE)
	message("Found Tester: ${TesterName} -> ${TesterSource}")

	add_executable(${TesterName} ${TesterSource})
	set_target_properties(${TesterName} PROPERTIES CXX_STANDARD 20)
	target_link_libraries(${TesterName} PRIVATE ${PROJECT_NAME})
endforeach()
