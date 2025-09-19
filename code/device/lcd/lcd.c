#include "lcd.h"

void lcd_init()
{
    tft180_set_dir(TFT180_PORTAIT);
    tft180_set_color(DEFAULT_PEN_COLOR, DEFAULT_BACKGROUND_COLOR);
    tft180_init();
}

void lcd_clear()
{
    tft180_clear();
}

void lcd_show_string(vuint16 x, vuint16 y, const char *dat)
{
    tft180_show_string(x * CHAR_WIDTH, y * CHAR_HEIGHT, dat);
}

void lcd_show_string_color(vuint16 x,
                           vuint16 y,
                           const char *dat,
                           vuint16 pen_color,
                           vuint16 background_color)
{
    tft180_set_color(pen_color, background_color);
    lcd_show_string(x, y, dat);
    tft180_set_color(DEFAULT_PEN_COLOR, DEFAULT_BACKGROUND_COLOR);
}
void lcd_show_uint(vuint16 x, vuint16 y, vuint32 dat, vuint8 num)
{
    tft180_show_uint(x * CHAR_WIDTH, y * CHAR_HEIGHT, dat, num);
}

void lcd_show_uint_color(vuint16 x,
                         vuint16 y,
                         vuint32 dat,
                         vuint8 num,
                         vuint16 pen_color,
                         vuint16 background_color)
{
    tft180_set_color(pen_color, background_color);
    lcd_show_uint(x, y, dat, num);
    tft180_set_color(DEFAULT_PEN_COLOR, DEFAULT_BACKGROUND_COLOR);
}

void lcd_show_int(vuint16 x, vuint16 y, int32 dat, vuint8 num)
{
    tft180_show_int(x * CHAR_WIDTH, y * CHAR_HEIGHT, dat, num);
}

void lcd_show_int_color(vuint16 x,
                        vuint16 y,
                        int32 dat,
                        vuint8 num,
                        vuint16 pen_color,
                        vuint16 background_color)
{
    tft180_set_color(pen_color, background_color);
    lcd_show_int(x, y, dat, num);
    tft180_set_color(DEFAULT_PEN_COLOR, DEFAULT_BACKGROUND_COLOR);
}

void lcd_show_float(vuint16 x,
                    vuint16 y,
                    const double dat,
                    vuint8 num,
                    vuint8 pointnum)
{
    tft180_show_float(x * CHAR_WIDTH, y * CHAR_HEIGHT, dat, num, pointnum);
}

void lcd_show_float_color(vuint16 x,
                          vuint16 y,
                          const double dat,
                          vuint8 num,
                          vuint8 pointnum,
                          vuint16 pen_color,
                          vuint16 background_color)
{
    tft180_set_color(pen_color, background_color);
    lcd_show_float(x, y, dat, num, pointnum);
    tft180_set_color(DEFAULT_PEN_COLOR, DEFAULT_BACKGROUND_COLOR);
}

void lcd_show_char(vuint16 x, vuint16 y, char dat)
{
    tft180_show_char(x * CHAR_WIDTH, y * CHAR_HEIGHT, dat);
}

void lcd_show_char_color(vuint16 x,
                         vuint16 y,
                         char dat,
                         vuint16 pen_color,
                         vuint16 background_color)
{
    tft180_set_color(pen_color, background_color);
    lcd_show_char(x, y, dat);
    tft180_set_color(DEFAULT_PEN_COLOR, DEFAULT_BACKGROUND_COLOR);
}

void lcd_show_grey_image_full(const vuint8 *image, vuint16 width, vuint16 height, vuint8 threshold)
{
    float scale_w = (float)tft180_width_max / width;
    float scale_h = (float)tft180_height_max / height;

    float scale = scale_w < scale_h ? scale_w : scale_h;

    uint16 display_w = (uint16)(width * scale);
    uint16 display_h = (uint16)(height * scale);

    uint16 start_x = (tft180_width_max - display_w) / 2;
    uint16 start_y = (tft180_height_max - display_h) / 2;

    // 调用底层显示函数：在计算出的目标区域显示原始灰度图（带阈值二值化）
    tft180_show_gray_image(start_x, start_y, image, width, height, display_w, display_h, threshold);
}