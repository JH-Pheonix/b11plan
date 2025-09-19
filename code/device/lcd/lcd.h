#ifndef _DEVICE_LCD_H_
#define _DEVICE_LCD_H_

#include "zf_device_tft180.h"
#include "zf_common_font.h"

#define DEFAULT_PEN_COLOR RGB565_MAGENTA
#define DEFAULT_BACKGROUND_COLOR RGB565_WHITE
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16

#define TFT180_WIDTH_MAX 160
#define TFT180_HEIGHT_MAX 128

#ifdef __cplusplus
extern "C"
{
#endif

    void lcd_init(void);
    void lcd_clear(void);

    void lcd_show_string(vuint16 x, vuint16 y, const char *dat);
    void lcd_show_string_color(vuint16 x,
                               vuint16 y,
                               const char *dat,
                               vuint16 pen_color,
                               vuint16 background_color);

    void lcd_show_uint(vuint16 x, vuint16 y, vuint32 dat, vuint8 num);
    void lcd_show_uint_color(vuint16 x,
                             vuint16 y,
                             vuint32 dat,
                             vuint8 num,
                             vuint16 pen_color,
                             vuint16 background_color);

    void lcd_show_int(vuint16 x, vuint16 y, int32 dat, vuint8 num);
    void lcd_show_int_color(vuint16 x,
                            vuint16 y,
                            int32 dat,
                            vuint8 num,
                            vuint16 pen_color,
                            vuint16 background_color);

    void lcd_show_float(vuint16 x,
                        vuint16 y,
                        const double dat,
                        vuint8 num,
                        vuint8 pointnum);
    void lcd_show_float_color(vuint16 x,
                              vuint16 y,
                              const double dat,
                              vuint8 num,
                              vuint8 pointnum,
                              vuint16 pen_color,
                              vuint16 background_color);

    void lcd_show_char(vuint16 x, vuint16 y, char dat);
    void lcd_show_char_color(vuint16 x,
                             vuint16 y,
                             char dat,
                             vuint16 pen_color,
                             vuint16 background_color);

    void lcd_show_grey_image_full(const vuint8 *image, vuint16 width, vuint16 height, vuint8 threshold);

#ifdef __cplusplus
}
#endif

#endif