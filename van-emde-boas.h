#ifndef _VAN_EMDE_BOAS_H
#define _VAN_EMDE_BOAS_H

#include <stdio.h>
#include <math.h>
#include <time.h>

#define pr_info(msg, ...)                                                      \
        fprintf(stderr, "[{%lfs} %s(%s):%d] " msg,                             \
                ((double)clock() / CLOCKS_PER_SEC), __FILE__, __func__,        \
                __LINE__, ##__VA_ARGS__)

#define nil (-1)

#define root_up(u) ((int)pow(2, ceil(log2(u) / 2.0)))
#define root_down(u) ((int)pow(2, floor(log2(u) / 2.0)))

#define high(u, x) ((int)floor(x / root_down(u)))
#define low(u, y) (x % root_down(u))
#define index(u, x, y) (x * root_down(u) + y)

/**
 * @brief vEB(u)에 해당하는 구조체이다.
 * 
 */
struct vEB {
        int u; /**< 현재 집합의 크기 */
        int min; /**< 1이 표기된 최소 지점 (-1은 Nil과 동일) */
        int max; /**< 1이 표기된 최대 지점 (-1은 Nil과 동일) */
        struct vEB *summary; /**< summary 정보가 들어간다. */
        struct vEB *cluster[0]; /**< 다음 cluster 값이 들어가게 된다. */
};

struct vEB *vEB_init(int u);

#endif