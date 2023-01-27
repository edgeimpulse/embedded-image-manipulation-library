/**
 * @file eiml.h
 * @brief Embedded Image Manipulation Library include file
 * 
 * Include this file in your project to perform basic image manipulation
 * functions, such as scaling, cropping, and color conversion.
 * 
 * @author Shawn Hymel (EdgeImpulse Inc.)
 * @copyright Copyright (c) 2023 EdgeImpulse Inc. (Apache-2.0)
 * @see https://www.apache.org/licenses/LICENSE-2.0
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
    EIML_RGB888 = 3
} eiml_color_space;

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} eiml_pixel;


typedef struct
{
    unsigned int width;
    unsigned int height;
    eiml_color_space color_space;
    unsigned char *pixels;
} eiml_image;

// Public functions
unsigned int eiml_get_bytes_per_pixel(eiml_color_space color_space);
eiml_ret eiml_convert(eiml_image *image_in, eiml_image *image_out);
eiml_ret eiml_crop(eiml_image *image_in, 
                    eiml_image *image_out, 
                    unsigned int x,
                    unsigned int y,
                    unsigned int width,
                    unsigned int height);
eiml_ret eiml_get_pixel(eiml_image *image_in,
                                    eiml_pixel *pixel_out,
                                    unsigned int x, 
                                    unsigned int y);

/**
 * @brief Get the number of bytes per pixel based on the provided color space
 * 
 * @param color_space One of the supported color space options
 * @return int Number of bytes per pixel
 */
unsigned int eiml_get_bytes_per_pixel(eiml_color_space color_space)
{
    unsigned int bytes_per_pixel;

    switch (color_space) 
    {
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
 * @brief Convert one image color space format to another
 * 
 * @param image_in Image in original color format
 * @param image_out Output image after color space conversion
 * @return eiml_ret EIML_ERROR on error, EIML_OK otherwise
 */
eiml_ret eiml_convert(eiml_image *image_in, eiml_image *image_out)
{
    // Check that input and output dimensions match
    if ((image_in->width != image_out->width) || 
        (image_in->height != image_out->height))
    {
        return EIML_ERROR;
    }

    // TODO: Use get_pixel to get RGB, convert to appropriate target format
    return EIML_ERROR;
}

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
 * @return eiml_ret EIML_ERROR on error, EIML_OK otherwise
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

/**
 * @brief Get RGB values from a pixel given at (x, y)
 * 
 * @param image_in Input image
 * @param pixel_out Pixel (R, G, B) values
 * @param x X coordinate of pixel value
 * @param y Y coordinate of pixel value
 * @return eiml_ret EIML_ERROR on error, EIML_OK otherwise
 */
eiml_ret eiml_get_pixel(eiml_image *image_in,
                        eiml_pixel *pixel_out,
                        unsigned int x, 
                        unsigned int y)
{
    unsigned int bytes_per_pixel;
    unsigned int offset;
    eiml_ret ret_val = EIML_OK;

    // Check for out of bounds access
    if ((x > image_in->width) || (y > image_in->height))
    {
        return EIML_ERROR;
    }

    // Get bytes per pixel
    bytes_per_pixel = eiml_get_bytes_per_pixel(image_in->color_space);

    switch (image_in->color_space)
    {
        // Grayscale: copy pixel values to each channel
        case EIML_GRAYSCALE:
            pixel_out->r = image_in->pixels[(y * image_in->width) + x];
            pixel_out->g = pixel_out->r;
            pixel_out->b = pixel_out->r;
            break;

        // YUV422
        case EIML_YUV422:
            // TODO
            ret_val = EIML_ERROR;
            break;

        // RGB565
        case EIML_RGB565:
            // TODO
            ret_val = EIML_ERROR;
            break;

        // RGB888: copy out individual pixel values
        case EIML_RGB888:
            offset = ((y * image_in->width) + x) * bytes_per_pixel;
            pixel_out->r = image_in->pixels[offset + 0];
            pixel_out->g = image_in->pixels[offset + 1];
            pixel_out->b = image_in->pixels[offset + 2];
            break;

        // Default case: unsupported format
        default:
            ret_val = EIML_ERROR;
    }

    return ret_val;
}

#endif // _EIML_H_
