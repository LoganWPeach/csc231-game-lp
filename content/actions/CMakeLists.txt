add_library(actions
  rest.cpp
        closedoor.cpp
        castlightning.cpp
        opendoor.cpp
        wander.cpp
        attack.cpp
        move.cpp
        move2.cpp
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
