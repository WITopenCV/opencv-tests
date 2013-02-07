set(pName ObjectTracking)
set(pSrcs src/ObjectTracking.cpp)

project(${pName})
add_executable(${pName} ${pSrcs})

find_package(OpenCV REQUIRED)
target_link_libraries(${pName} ${OpenCV_LIBS})
