add_executable(tests 
    main.cpp
    ../editor/load.c
    ../editor/save.c
    ../editor/show.c
    ../editor/shownum.c
    "${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest-all.cc"
    "${PROJECT_SOURCE_DIR}/external/googletest/googlemock/src/gmock-all.cc"
    )
target_include_directories(tests PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/text"
    "${PROJECT_SOURCE_DIR}/external/googletest/googletest/include"
    "${PROJECT_SOURCE_DIR}/external/googletest/googlemock/include"
    "${PROJECT_SOURCE_DIR}/external/googletest/googletest/"
    "${PROJECT_SOURCE_DIR}/external/googletest/googlemock/"
    )
target_link_libraries(tests PUBLIC text gcov)

add_custom_command(
        TARGET tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/input.txt)
