#include "van-emde-boas.h"

int main(void)
{
        struct vEB *v;
        v = vEB_init(16);
        if (v == NULL) {
                pr_info("Allocation failed\n");
                return -1;
        }

        pr_info("%d %d %d\n", v->u, v->max, v->min);
        pr_info("%p\n", v->summary);
        pr_info("%d %d %d\n", v->summary->u, v->summary->max, v->summary->min);
        for (int i = 0; i < root_up(16); i++) {
                pr_info("%p\n", v->cluster[i]);
        }

        return 0;
}