cmake_minimum_required(VERSION 3.14.0)

include(FetchContent)

FetchContent_Declare(
    thread-pool
    URL      https://github.com/bshoshany/thread-pool/archive/refs/tags/v3.0.0.zip
    URL_HASH SHA512=bab8a512467d6c9b964bcab11f4c48b91ce0bc68874d368fa1975a1d8036f9891d47091c6e0a3096c7b5bcb8455997184a438e4f6936a8f8df4d22df8fa8fba6
)
FetchContent_MakeAvailable(thread-pool)
