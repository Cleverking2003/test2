add_library(text
    append_line.c
    create_text.c
    move_crsr_r.c
    move_crsr.c
    process_forward.c
    remove_all.c
    remove_first_line.c)
target_link_libraries(text gcov)
