add_library(actions
  rest.cpp
        attack.cpp
        closedoor.cpp
        castlightning.cpp
        opendoor.cpp
        move.cpp
        move2.cpp
        shoot.cpp
        wander.cpp
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
