#include "CppUTest/TestHarness.h"

extern "C" {
    #include "eiml.h"
}

// Create test group
TEST_GROUP(eiml_test_group)
{
    void setup()
    {
        // Initialize before each test
    }
    
    void teardown()
    {
        // Deinitialize after each test
    }
};

// Test getting a pixel
TEST(eiml_test_group, get_pixel_test)
{
    // TODO: implement this
    CHECK_EQUAL(1.0, 1.0);
}
