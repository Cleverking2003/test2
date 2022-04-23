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

static const char *input_file = INPUTDIR "/input.txt";

text init_text(const char *filename) {
    text t = create_text();
    load(t, filename);
    return t;
}

void deinit_text(text t) {
    remove_all(t);
}

TEST(load, no_file) {
    text new_txt = create_text();
    std::string output;
    GetOutput(load(new_txt, "i.txt");)
    ASSERT_EQ(output, "The file i.txt cannot be opened\n");
}

TEST(save, save) {
    auto txt = init_text(input_file);
    save(txt, "o.txt");
    std::ifstream file("o.txt");
    std::stringstream str;
    str << file.rdbuf();
    ASSERT_EQ(str.str(), "hello\nworld\n");
    remove_all(txt);
}

TEST(save, cant_save) {
    auto txt = init_text(input_file);
    std::string output;
    GetOutput(save(txt, "/dev/mem");)
    ASSERT_EQ(output, "The file /dev/mem cannot be opened\n");
    remove_all(txt);
}

TEST(show, show) {
    auto txt = init_text(input_file);
    std::string output;
    GetOutput(show(txt);)
    ASSERT_EQ(output, "hello\nworld|\n");
    remove_all(txt);
}

TEST(shownum, shownum) {
    auto txt = init_text(input_file);
    std::string output;
    GetOutput(shownum(txt);)
    ASSERT_EQ(output, "0: hello\n1: world|\n");
    remove_all(txt);
}

TEST(mcf, can_mcf) {
    auto txt = init_text(input_file);
    std::string output;
    GetOutput(move_crsr(txt, 0, 4); show(txt);)
    ASSERT_EQ(output, "hell|o\nworld\n");
    GetOutput(move_crsr_right(txt); show(txt);)
    ASSERT_EQ(output, "hello|\nworld\n");
    remove_all(txt);
}

TEST(mcf, cannot_mcf) {
    auto txt = init_text(input_file);
    std::string output;
    GetOutput(move_crsr(txt, 1, 5); show(txt);)
    ASSERT_EQ(output, "hello\nworld|\n");
    GetOutput(move_crsr_right(txt); show(txt);)
    ASSERT_EQ(output, "hello\nworld|\n");
    remove_all(txt);
}

TEST(rh, rh) {
    auto txt = init_text(input_file);
    std::string output;
    GetOutput(remove_first_line(txt); show(txt);)
    ASSERT_EQ(output, "world|\n");
    GetOutput(remove_first_line(txt); show(txt);)
    ASSERT_EQ(output, "");
    GetOutput(remove_first_line(txt); show(txt);)
    ASSERT_EQ(output, "");
    remove_all(txt);
}
