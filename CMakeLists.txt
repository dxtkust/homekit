cmake_minimum_required(VERSION 3.10.0)
project(pro VERSION 0.1.0 LANGUAGES C)

add_executable(pro calculator.c leap_year.c)
add_executable(sensor_monitor sensor_monitor.c sensor_utils.c)

