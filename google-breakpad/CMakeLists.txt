cmake_minimum_required ( VERSION 2.8.5 )
project ( google-breakpad )

set ( BREAKPAD_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" )

set ( BREAKPAD_INCLUDES 
  "${BREAKPAD_SOURCE_DIR}/src/common/android/include"
  "${BREAKPAD_SOURCE_DIR}/src"
)

enable_language(ASM)

set ( BREAKPAD_SOURCES
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/crash_generation/crash_generation_client.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/handler/exception_handler.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/handler/minidump_descriptor.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/log/log.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/minidump_writer/linux_dumper.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/minidump_writer/linux_ptrace_dumper.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/linux/minidump_writer/minidump_writer.cc"
  "${BREAKPAD_SOURCE_DIR}/src/client/minidump_file_writer.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/android/breakpad_getcontext.S"
  "${BREAKPAD_SOURCE_DIR}/src/common/convert_UTF.c"
  "${BREAKPAD_SOURCE_DIR}/src/common/md5.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/string_conversion.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/linux/elfutils.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/linux/file_id.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/linux/guid_creator.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/linux/linux_libc_support.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/linux/memory_mapped_file.cc"
  "${BREAKPAD_SOURCE_DIR}/src/common/linux/safe_readlink.cc"
)

file ( GLOB_RECURSE BREAKPAD_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.h" )

add_library(google-breakpad STATIC ${BREAKPAD_SOURCES} ${BREAKPAD_HEADERS})
target_include_directories(google-breakpad PUBLIC ${BREAKPAD_INCLUDES})
target_link_libraries (google-breakpad log)