cmake_minimum_required ( VERSION 2.8.5 )
project ( moai-hockeyapp-android )

set ( PLUGIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

set ( MOAI_HOCKEYAPP_ANDROID_INCLUDES 
    ${PLUGIN_ROOT}/../
    ${PLUGIN_ROOT}/google-breakpad/src
)

# Use all cpp files in directory as source code
file ( GLOB_RECURSE MOAI_HOCKEYAPP_ANDROID_SRC "${PLUGIN_ROOT}/*.cpp" )
file ( GLOB_RECURSE MOAI_HOCKEYAPP_ANDROID_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" )

add_library ( moai-hockeyapp-android STATIC ${MOAI_HOCKEYAPP_ANDROID_SRC} ${MOAI_HOCKEYAPP_ANDROID_HEADERS} )
target_include_directories( moai-hockeyapp-android PUBLIC ${MOAI_HOCKEYAPP_ANDROID_INCLUDES})
target_link_libraries (moai-hockeyapp-android moai-core google-breakpad)