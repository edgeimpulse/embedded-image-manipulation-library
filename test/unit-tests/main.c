/* Test for Embedded Image Manipulation Library
 * 
 * Copyright (c) 2023 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>

#include "../../eiml.h"

int main (int argc, char *argv[])
{
    // Define test image pattern
    unsigned char img[] = { 
                            255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 
                            255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 255, 
                            255, 255, 0, 255, 255, 0, 0, 255, 255, 0, 255, 255, 255, 0, 255, 255, 0, 255, 
                            0, 0, 0, 51, 51, 51, 102, 102, 102, 153, 153, 153, 204, 204, 204, 255, 255, 255, 
                            100, 0, 0, 50, 50, 0, 20, 20, 0, 0, 10, 10, 1, 2, 3, 1, 1, 2, 
                            50, 50, 0, 100, 0, 0, 0, 10, 10, 20, 20, 0, 1, 1, 2, 1, 2, 3 
                            };

    // Define eiml_image
    eiml_image test_image;
    test_image.width = 6;
    test_image.height = 6;
    test_image.color_space = EIML_RGB888;
    test_image.image = img;

    // Test: get pixel value
    eiml_pixel pix;
    eiml_get_pixel(&test_image, &pix, 5, 5);
    printf("%i, %i, %i\r\n", pix.r, pix.g, pix.b);

    return 0;
}