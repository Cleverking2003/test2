add_executable(editor
    editor.c
    load.c
    save.c
    show.c
    shownum.c)
target_include_directories(editor PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/text"
    )
target_link_libraries(editor PUBLIC text gcov)