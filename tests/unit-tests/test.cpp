#include "CppUTest/TestHarness.h"

extern "C" {
    #include "eiml.h"
}

// Test image pattern shared among the different tests
static eiml_image test_image;
static unsigned char pattern[] = { 
                                    255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 
                                    255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 
                                    255, 255, 0, 255, 255, 0, 0, 255, 255, 0, 255, 255, 255, 0, 255, 255, 0, 255, 
                                    0, 0, 0, 51, 51, 51, 102, 102, 102, 153, 153, 153, 204, 204, 204, 255, 255, 255, 
                                    100, 0, 0, 50, 50, 0, 20, 20, 0, 0, 10, 10, 1, 2, 3, 1, 1, 2, 
                                    50, 50, 0, 100, 0, 0, 0, 10, 10, 20, 20, 0, 1, 1, 2, 1, 2, 3 
                                };

// Create test group
TEST_GROUP(eiml_test_group)
{
    // Called before each test
    void setup()
    {
        // Define eiml_image
        test_image.width = 6;
        test_image.height = 6;
        test_image.color_space = EIML_RGB888;
        test_image.pixels = pattern;
    }
    
    // Called after each test
    void teardown()
    {
    }
};

// Test getting a pixel
TEST(eiml_test_group, get_pixel_test)
{
    eiml_pixel pix;
    eiml_ret ret;

    // Test: get pixel value
    ret = eiml_get_pixel(&test_image, &pix, 5, 5);

    // Check values
    CHECK_EQUAL(EIML_OK, ret);
    CHECK_EQUAL(1, pix.r);
    CHECK_EQUAL(2, pix.g);
    CHECK_EQUAL(3, pix.b);
}
