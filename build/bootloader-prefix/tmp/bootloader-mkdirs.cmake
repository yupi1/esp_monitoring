# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/mr_robot/esp/esp-idf/components/bootloader/subproject"
  "/home/mr_robot/Desktop/esp_monitor/build/bootloader"
  "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix"
  "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix/tmp"
  "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix/src/bootloader-stamp"
  "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix/src"
  "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/mr_robot/Desktop/esp_monitor/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
