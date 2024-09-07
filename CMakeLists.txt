cmake_minimum_required(VERSION 2.6.0)

project(RedDotVPN C)

add_executable(red_dot_vpn_core vpn_client/main.c cryptography/cryptography.c)
add_executable(red_dot_vpn_server vpn_server/main.c cryptography/cryptography.c)
