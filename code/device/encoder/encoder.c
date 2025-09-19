#include "encoder.h"

encoder_obj_t encoder_init(encoder_index_enum index, encoder_channel1_enum pin_a, encoder_channel2_enum pin_b)
{
    encoder_obj_t obj;
    obj.index = index;
    encoder_dir_init(index, pin_a, pin_b);
    return obj;
}

vint16 encoder_get_data(encoder_obj_t *obj)
{
    return encoder_get_count(obj->index);
}

void encoder_reset(encoder_obj_t *obj)
{
    encoder_clear_count(obj->index);
}
