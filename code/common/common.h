#ifndef _COMMON_H_
#define _COMMON_H_

#define CLAMP(input, max)          \
    do                             \
    {                              \
        if ((input) > (max))       \
        {                          \
            (input) = (max);       \
        }                          \
        else if ((input) < -(max)) \
        {                          \
            (input) = -(max);      \
        }                          \
    } while (0)

typedef struct
{
    float x;
    float y;
} point_2d;

#endif