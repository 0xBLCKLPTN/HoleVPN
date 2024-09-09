cmake_minimum_required(VERSION 2.6.0)

project(RedDotVPN C)

include(FetchContent)
find_package(OpenSSL)

find_program(CARGO_EXECUTABLE cargo)
find_package(CURL REQUIRED)
if (NOT CARGO_EXECUTABLE)
  message(FATAL ERROR "cargo not found!")
elseif (NOT CURL_FOUND)
  message(FATAL ERROR "libcurl not found!")
endif()


set(SCRIPT_PATH ${CMAKE_SOURCE_DIR}/scripts/rdapi_bin.sh)

if(UNIX)
  set(CARGO_TARGET_DIR ${CMAKE_BINARY_DIR}/bin/linux)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/linux)
elseif(WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/win)
elseif(MSVC)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/msvc)
endif(MSVC)


#SET(MY_VARIABLE "option_value" CACHE STRING "Some user-specified option")
add_executable(RedDotClient vpn_client/main.c cryptography/cryptography.c rdapi/c_includes/rdapi_connect.c)
add_executable(RedDotServer vpn_server/main.c cryptography/cryptography.c rdapi/c_includes/rdapi_connect.c)
add_executable(RedDotTest vpn_test/main.c cryptography/cryptography.c rdapi/c_includes/rdapi_connect.c)

target_link_libraries(RedDotClient OpenSSL::SSL OpenSSL::Crypto CURL::libcurl)
target_link_libraries(RedDotServer OpenSSL::SSL OpenSSL::Crypto CURL::libcurl)
target_link_libraries(RedDotTest OpenSSL::SSL OpenSSL::Crypto CURL::libcurl)


add_custom_target(run_script
  COMMAND ${SCRIPT_PATH}
  COMMEND "Building rdapi.."
  VEBRATIM
)
add_dependencies(RedDotServer run_script)
