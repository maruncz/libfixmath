#include "tests_lerp.h"
#include "tests.h"

int test_lerp()
{
    ASSERT_EQ_INT(fix16_lerp8(0, 2, 0), (uint32_t)0);
    ASSERT_EQ_INT(fix16_lerp8(0, 2, 127), (uint32_t)0);
    ASSERT_EQ_INT(fix16_lerp8(0, 2, 128), (uint32_t)1);
    ASSERT_EQ_INT(fix16_lerp8(0, 2, 255), (uint32_t)1);
    ASSERT_EQ_INT(fix16_lerp8(fix16_minimum, fix16_maximum, 0), fix16_minimum);
    ASSERT_EQ_INT(fix16_lerp8(fix16_minimum, fix16_maximum, 255),
                  (fix16_maximum - ((int32_t)1 << 24)));
    ASSERT_EQ_INT(fix16_lerp8(-fix16_maximum, fix16_maximum, 128), (uint32_t)0);

    ASSERT_EQ_INT(fix16_lerp16(0, 2, 0), (uint32_t)0);
    ASSERT_EQ_INT(fix16_lerp16(0, 2, 0x7fff), (uint32_t)0);
    ASSERT_EQ_INT(fix16_lerp16(0, 2, 0x8000), (uint32_t)1);
    ASSERT_EQ_INT(fix16_lerp16(0, 2, 0xffff), (uint32_t)1);
    ASSERT_EQ_INT(fix16_lerp16(fix16_minimum, fix16_maximum, 0), fix16_minimum);
    ASSERT_EQ_INT(fix16_lerp16(fix16_minimum, fix16_maximum, 0xffff),
                  (fix16_maximum - ((int32_t)1 << 16)));
    ASSERT_EQ_INT(fix16_lerp16(-fix16_maximum, fix16_maximum, 0x8000), (uint32_t)0);

    ASSERT_EQ_INT(fix16_lerp32(0, 2, 0), (uint32_t)0);
    ASSERT_EQ_INT(fix16_lerp32(0, 2, 0x7fffffff), (uint32_t)0);
    ASSERT_EQ_INT(fix16_lerp32(0, 2, 0x80000000), (uint32_t)1);
    ASSERT_EQ_INT(fix16_lerp32(0, 2, 0xffffffff), (uint32_t)1);
    ASSERT_EQ_INT(fix16_lerp32(fix16_minimum, fix16_maximum, 0), fix16_minimum);
    ASSERT_EQ_INT(fix16_lerp32(fix16_minimum, fix16_maximum, 0xffffffff),
                  (fix16_maximum - 1));
    ASSERT_EQ_INT(fix16_lerp32(-fix16_maximum, fix16_maximum, 0x80000000), (uint32_t)0);
    return 0;
}
