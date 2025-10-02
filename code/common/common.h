#ifndef _COMMON_H_
#define _COMMON_H_

#define CLAMP_ABS(input, max)      \
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

#define CLAMP(input, min, max)    \
    do                            \
    {                             \
        if ((input) > (max))      \
        {                         \
            (input) = (max);      \
        }                         \
        else if ((input) < (min)) \
        {                         \
            (input) = (min);      \
        }                         \
    } while (0)

#define CLAMP_MAX(input, max) \
    do                        \
    {                         \
        if ((input) > (max))  \
        {                     \
            (input) = (max);  \
        }                     \
    } while (0)

#define CLAMP_MIN(input, min) \
    do                        \
    {                         \
        if ((input) < (min))  \
        {                     \
            (input) = (min);  \
        }                     \
    } while (0)

#define SWAP(a, b) \
    do             \
    {              \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    } while (0)

typedef struct
{
    float x;
    float y;
} point_2d;

#endif