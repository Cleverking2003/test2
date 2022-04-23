#pragma once

#include <fstream>
#include <sstream>
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

TEST(load, no_file) {
    text new_txt = create_text();
    std::string output;
    GetOutput(load(new_txt, "i.txt");)
    ASSERT_EQ(output, "The file i.txt cannot be opened\n");
}

TEST(save, save) {
    save(txt, "o.txt");
    std::ifstream file("o.txt");
    std::stringstream str;
    str << file.rdbuf();
    ASSERT_EQ(str.str(), "hello\nworld\n");
}

TEST(save, cant_save) {
    std::string output;
    GetOutput(save(txt, "/dev/mem");)
    ASSERT_EQ(output, "The file /dev/mem cannot be opened\n");
}

TEST(show, show) {
    std::string output;
    GetOutput(show(txt);)
    ASSERT_EQ(output, "hello\nworld|\n");
}

TEST(shownum, shownum) {
    std::string output;
    GetOutput(shownum(txt);)
    ASSERT_EQ(output, "0: hello\n1: world|\n");
}

TEST(mcf, can_mcf) {
    std::string output;
    GetOutput(move_crsr(txt, 0, 4); show(txt);)
    ASSERT_EQ(output, "hell|o\nworld\n");
    GetOutput(move_crsr_right(txt); show(txt);)
    ASSERT_EQ(output, "hello|\nworld\n");
}

TEST(mcf, cannot_mcf) {
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
    GetOutput(remove_first_line(new_txt); show(new_txt);)
    ASSERT_EQ(output, "");
}
