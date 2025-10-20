cmake_minimum_required(VERSION 3.10)
project(magic_enum_protobuf_repro)

set(CMAKE_CXX_STANDARD 17)

find_package(magic_enum CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)

# Compile protobuf files
set(PROTO_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/proto/example.proto
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# Create a directory for generated files
set(PROTO_GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
file(MAKE_DIRECTORY ${PROTO_GENERATED_DIR})

add_executable(magic_enum_protobuf_repro 
    src/main.cpp
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

target_include_directories(magic_enum_protobuf_repro PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Protobuf_INCLUDE_DIRS}
)

target_link_libraries(magic_enum_protobuf_repro PRIVATE magic_enum::magic_enum protobuf::libprotobuf)