cmake_minimum_required(VERSION 3.8)
project(NetworkingProject LANGUAGES CXX)

# Enable C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers (optional)
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
        "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,\
        $<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,\
        $<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# --------------------------
# Source files
# --------------------------
add_executable(NetworkingProject
    "ServerApplicationTCP.cpp"
    "NetworkingProject.h"
    "ClientApplicationTCP.cpp"
    "ServerApplicaionUDP.cpp"
    "ClientApplicaitonUDP.cpp"
    "IpConfigServer.cpp"
    "IpConfigClient.cpp"
    "HTTPClient.cpp"
    "HTTPClientSecure.cpp"
    "FTPConnection.cpp"
 "SMTP.cpp" "DNSQuery.cpp" "AsynchonousProgramming.cpp" "MultiThreadedServer.cpp" "MutiThreadedClient.cpp" "PerformanceTestTCPServer.cpp" "StressTest.cpp")

# --------------------------
# Include directories
# --------------------------
include_directories("C:/boost/boost_1_89_0")

# POCO
set(POCO_INCLUDE_DIR "C:/poco-1.14.2/poco-1.14.2/Foundation/include")
set(POCO_LIB_DIR "C:/poco-1.14.2/poco-1.14.2/lib")
include_directories(${POCO_INCLUDE_DIR})

# OpenSSL
set(OPENSSL_DIR "C:/dev/vcpkg/installed/x64-windows")
include_directories(${OPENSSL_DIR}/include)

# cURL
set(CURL_DIR "C:/dev/vcpkg/installed/x64-windows")
include_directories(${CURL_DIR}/include)

# --------------------------
# Libraries (link order matters)
# --------------------------
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(NetworkingProject PRIVATE
        "${POCO_LIB_DIR}/PocoFoundationd.lib"
        "${POCO_LIB_DIR}/PocoUtild.lib"
        "${OPENSSL_DIR}/debug/lib/libssl.lib"
        "${OPENSSL_DIR}/debug/lib/libcrypto.lib"
        "${CURL_DIR}/debug/lib/libcurld.lib"
        ws2_32.lib
        wldap32.lib
        winmm.lib
        crypt32.lib
    )
else()
    target_link_libraries(NetworkingProject PRIVATE
        "${POCO_LIB_DIR}/PocoFoundation.lib"
        "${POCO_LIB_DIR}/PocoUtil.lib"
        "${OPENSSL_DIR}/lib/libssl.lib"
        "${OPENSSL_DIR}/lib/libcrypto.lib"
        "${CURL_DIR}/lib/libcurl.lib"
        ws2_32.lib
        wldap32.lib
        winmm.lib
        crypt32.lib
    )
endif()
