# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(fuzz)

if(CONFIG_ARCH_POSIX_LIBFUZZER)
    target_sources(app PRIVATE src/main.c)
else()
    target_sources(app PRIVATE src/main.c src/fuzz.c)
endif()
