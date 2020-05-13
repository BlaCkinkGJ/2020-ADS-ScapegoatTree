#include <stdio.h>
#include <stdlib.h>
#include "van-emde-boas.h"

struct vEB *vEB_init(int u)
{
        struct vEB *v = NULL;
        const int nr_cluster = root_up(u);
        const int cluster_size = sizeof(struct vEB *) * nr_cluster;

        v = (struct vEB *)malloc(sizeof(struct vEB) + cluster_size);
        if (v == NULL) {
                pr_info("Allocation failed");
                goto exception;
        }

        pr_info("%p %d\n", v, u);

        v->u = u;
        v->min = v->max = nil;

        if (v->u > 2) {
                v->summary = vEB_init(root_up(u));
                for (int i = 0; i < nr_cluster; i++) {
                        v->cluster[i] = vEB_init(root_down(u));
                }
        }

exception:
        return v;
}