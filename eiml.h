/* Embedded Image Manipulation Library
 * 
 * Include this and base64.h in your project to perform basic image manipulation
 * functions such as scaling, cropping, and color conversion.
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

#ifndef _EIML_H_
#define _EIML_H_

#include "base64.h"

typedef enum
{
    EIML_OK = 0,
    EIML_ERROR = 1
} eiml_ret;

typedef enum
{
    EIML_GRAYSCALE = 0,
    EIML_YUV422 = 1,
    EIML_RGB565 = 2,
    EIML_RGB888 = 3,
} eiml_color_space;

typedef struct
{
    unsigned int width;
    unsigned int height;
    eiml_color_space color_space;
    unsigned char *image;
} eiml_image;

/**
 * @brief Get the number of bytes per pixel based on the provided color space
 * 
 * @param color_space One of the supported color space options
 * @return Number of bytes per pixel
 */
unsigned int eiml_get_bytes_per_pixel(eiml_color_space color_space)
{
    unsigned int bytes_per_pixel;

    switch (color_space) {
        case EIML_GRAYSCALE:
            bytes_per_pixel = 1;
            break;
        case EIML_YUV422:
            bytes_per_pixel = 2;
            break;
        case EIML_RGB565:
            bytes_per_pixel = 2;
            break;
        case EIML_RGB888:
            bytes_per_pixel = 3;
            break;
        default:
            bytes_per_pixel = 0;
    }

    return bytes_per_pixel;
}

/**
 * @brief Allocate memory for the given image struct. Note: uses malloc()
 * 
 * @param image Input/output image struct with all fields filled but *image
 * @return eiml_ret Return status code (EIML_OK or EIML_ERROR)
 */
// eiml_ret eiml_init_image(eiml_image *image)
// {
//     unsigned int bytes_per_pixel;

//     // Check to make sure parameters are set
//     if (image->width == 0) || (image->height == 0)
//     {
//         return EIML_ERROR;
//     }

//     // Get number of bytes per pixel
//     bytes_per_pixel eiml_get_bytes_per_pixel(image->color_space);

//     // Allocate image buffer
//     image->image = (unsigned char *)malloc(image->width * image->height * \
//                                             bytes_per_pixel * \
//                                             sizeof(unsigned char));

//     // Check allocation
//     if (image->image != NULL)
//     {
//         return EIML_OK;
//     }
//     else
//     {
//         return EIML_ERROR;
//     }
// }

/**
 * @brief Crops input image with x/y and width/height, copies to output image
 * 
 * Crops input image at the given (x, y) coordinate. The width and height of
 * the crop comes from the image_out struct parameters. The cropped image is
 * copied to the image buffer in image_out. Note that the color spaces of 
 * image_in and image_out must match. Also, the function will fail (EIML_ERROR)
 * if the crop extends beyond the width or height of image_in.
 * 
 * @param image_in Image to be cropped
 * @param image_out Cropped image
 * @param x Where to crop (x) on input image
 * @param y Where to crop (y) on input image
 * @return eiml_ret 
 */
eiml_ret eiml_crop(eiml_image *image_in, 
                    eiml_image *image_out, 
                    unsigned int x,
                    unsigned int y,
                    unsigned int width,
                    unsigned int height)
{
    // TODO: implement this function

    // Check: color spaces match

    // Check: width/height + x/y does not extend beyond input image



    return EIML_OK;
}

#endif // _EIML_H_