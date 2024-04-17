cmake_minimum_required(VERSION 3.28)
project(LEADS_Arduino)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(LEADS_Arduino
        src/ArrayList.h
        src/Controller.cpp
        src/Controller.h
        src/Device.h
        src/LEADS.h
        src/PredefinedTags.h
        src/Utils.cpp
        src/Utils.h
        src/VoltageSensor.cpp
        src/VoltageSensor.h
        src/WheelSpeedSensor.cpp
        src/WheelSpeedSensor.h)
