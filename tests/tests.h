#ifndef TESTS_H
#define TESTS_H

#include <inttypes.h>
#include <libfixmath/fix16.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned stack_depth;

#define delta(a, b) (((a) >= (b)) ? (a) - (b) : (b) - (a))

#define COMMENT(x) printf("\n----" x "----\n");
#define STR(x) #x
#define STR2(x) STR(x)
#define TEST(x)                                                              \
    do                                                                       \
    {                                                                        \
        ++stack_depth;                                                       \
        char space[20];                                                      \
        uint8_t i;                                                           \
        for (i = 0; i <= stack_depth; ++i)                                   \
        {                                                                    \
            space[i] = ' ';                                                  \
        }                                                                    \
        space[i] = '\0';                                                     \
        if ((x))                                                             \
        {                                                                    \
            fflush(stdout);                                                  \
            fflush(stderr);                                                  \
            fprintf(stderr,                                                  \
                    "\033[31;1m FAILED:\033[22;39m%s" #x                     \
                    " \033[0mat: " __FILE__ ":" STR2(__LINE__) " \n",        \
                    space);                                                  \
            --stack_depth;                                                   \
            return 1;                                                        \
        }                                                                    \
        else                                                                 \
        {                                                                    \
            fflush(stdout);                                                  \
            fflush(stderr);                                                  \
            printf("\033[32;1m     OK:\033[22;39m%s" #x "\n\033[0m", space); \
        }                                                                    \
        --stack_depth;                                                       \
    } while (0)

#define ASSERT_NEAR_DOUBLE(a, b, eps, ...)                                  \
    do                                                                      \
    {                                                                       \
        if ((delta((a), (b)) >= (eps)))                                     \
        {                                                                   \
            char space[20];                                                 \
            uint8_t i;                                                      \
            for (i = 0; i <= stack_depth; ++i)                              \
            {                                                               \
                space[i] = ' ';                                             \
            }                                                               \
            space[i] = '\0';                                                \
            fflush(stdout);                                                 \
            fflush(stderr);                                                 \
            fprintf(stderr,                                                 \
                    "\033[31;1m FAILED:\033[22;39m%sASSERT_NEAR a: %f, b: " \
                    "%f, eps: %f\033[0m at: %s(), " __FILE__                \
                    ":" STR2(__LINE__) "\n",                                \
                    space, (a), (b), (eps), __func__);                      \
            fprintf(stdout, "        %s", space);                           \
            fprintf(stdout, __VA_ARGS__);                                   \
            return 1;                                                       \
        }                                                                   \
    } while (0)

#define ASSERT_EQ_INT(a, b)                                                \
    do                                                                     \
    {                                                                      \
        if ((a) != (b))                                                    \
        {                                                                  \
            char space[20];                                                \
            uint8_t i;                                                     \
            for (i = 0; i <= stack_depth; ++i)                             \
            {                                                              \
                space[i] = ' ';                                            \
            }                                                              \
            space[i] = '\0';                                               \
            fflush(stdout);                                                \
            fflush(stderr);                                                \
            fprintf(stderr,                                                \
                    "\033[31;1m FAILED:\033[22;39m%sASSERT_EQ a: %" PRIi32 \
                    ", b: %" PRIi32 "\033[0m at: %s(), " __FILE__          \
                    ":" STR2(__LINE__) "\n",                               \
                    space, (a), (b), __func__);                            \
            return 1;                                                      \
        }                                                                  \
    } while (0)

#define ASSERT_EQ_STR(a, b)                                                  \
    do                                                                       \
    {                                                                        \
        size_t la = strlen(a);                                               \
        size_t lb = strlen(b);                                               \
        if (la != lb)                                                        \
        {                                                                    \
            fflush(stdout);                                                  \
            fflush(stderr);                                                  \
            fprintf(stderr,                                                  \
                    "\033[31;1m FAILED:\033[22;39m%*sASSERT_EQ a: %s, b: "   \
                    "%s\033[0m at: %s(), " __FILE__ ":" STR2(__LINE__) "\n", \
                    stack_depth, "", (a), (b), __func__);                    \
            return 1;                                                        \
        }                                                                    \
        int res = strncmp((a), (b), la);                                     \
        if (res != 0)                                                        \
        {                                                                    \
            fflush(stdout);                                                  \
            fflush(stderr);                                                  \
            fprintf(stderr,                                                  \
                    "\033[31;1m FAILED:\033[22;39m%*sASSERT_EQ a: %s, b: "   \
                    "%s\033[0m at: %s(), " __FILE__ ":" STR2(__LINE__) "\n", \
                    stack_depth, "", (a), (b), __func__);                    \
            return 1;                                                        \
        }                                                                    \
    } while (0)

extern const fix16_t testcases[102];

#define TESTCASES_COUNT (sizeof(testcases) / sizeof(testcases[0]))

#define delta(a, b) (((a) >= (b)) ? (a) - (b) : (b) - (a))

#endif // TESTS_H
