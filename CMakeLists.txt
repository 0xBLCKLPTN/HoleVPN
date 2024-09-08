cmake_minimum_required(VERSION 2.6.0)

project(RedDotVPN C)

find_package(OpenSSL)

add_executable(red_dot_vpn_core vpn_client/main.c cryptography/cryptography.c)
add_executable(red_dot_vpn_server vpn_server/main.c cryptography/cryptography.c)
add_executable(red_dot_test vpn_test/main.c cryptography/cryptography.c)

target_link_libraries(red_dot_vpn_core OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(red_dot_vpn_server OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(red_dot_test OpenSSL::SSL OpenSSL::Crypto)
