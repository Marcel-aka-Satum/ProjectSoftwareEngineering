cmake_minimum_required(VERSION 3.6)
project(VerkeersSimulatie)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES tinystr.cpp tinystr.h tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp baan.h baan.cpp verkeerslicht.h
        verkeerslicht.cpp voertuig.h voertuig.cpp voertuiggenerator.h voertuiggenerator.cpp xmlImporter.h DesignByContract.h testVoertuig.h bushalte.cpp bushalte.h kruispunt.cpp kruispunt.h testInput.h simulationUtils.h simulationUtils.cpp xmlImporter.cpp xmlImporter.h)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES TESTS.cpp ${RELEASE_SOURCE_FILES} testBaan.h testGenerator.h testBushalte.h testKruispunt.h testInput.h simulationUtils.h simulationUtils.cpp xmlImporter.cpp testOutput.h)

# Create RELEASE target
add_executable(VS main.cpp ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(VS_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(VS_debug gtest)