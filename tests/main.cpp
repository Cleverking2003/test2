#include "tests.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    init_tests();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
