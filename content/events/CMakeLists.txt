add_library(events
        arrow.cpp
        audioevent.cpp
        die.cpp
        hit.cpp
        updatefov.cpp
        lightning.cpp
        thrust.cpp
        swing.cpp
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
