#pragma once

#include <gtest/gtest.h>

extern "C" {
    #include <text.h>
    #include "../editor/common.h"
}

#define GetOutput(action) \
    testing::internal::CaptureStdout(); \
    { action } \
    output = testing::internal::GetCapturedStdout();

static text txt;

void init_tests() {
    txt = create_text();
    load(txt, INPUTDIR "/input.txt");
}

TEST(shownum, shownum) {
    testing::internal::CaptureStdout();
    shownum(txt);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "0: hello\n1: world|\n");
}

TEST(mcr, can_mcr) {
    std::string output;
    GetOutput(move_crsr(txt, 0, 4); show(txt);)
    ASSERT_EQ(output, "hell|o\nworld\n");
    GetOutput(move_crsr_right(txt); show(txt);)
    ASSERT_EQ(output, "hello|\nworld\n");
}

TEST(mcr, cannot_mcr) {
    std::string output;
    GetOutput(move_crsr(txt, 0, 5); show(txt);)
    ASSERT_EQ(output, "hello|\nworld\n");
    GetOutput(move_crsr_right(txt); show(txt);)
    ASSERT_EQ(output, "hello|\nworld\n");
}

TEST(rh, rh) {
    // Загружаем заново, потому что мы будем его изменять
    text new_txt = create_text();
    load(new_txt, INPUTDIR "/input.txt");
    std::string output;
    GetOutput(remove_first_line(new_txt); show(new_txt);)
    ASSERT_EQ(output, "world|\n");
    GetOutput(remove_first_line(new_txt); show(new_txt);)
    ASSERT_EQ(output, "");
}
