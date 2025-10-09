#include <stdio.h>
#include "front.h"
#include "rear.h"
#include "right.h"
#include "left.h"
#include "up.h"
#include "down.h"

struct mobile{
    struct front f;
    struct rear r;
    struct right rt;
    struct left lf;
    struct up up;
    struct down dw;
    float grm;
};

int main()
{
    struct mobile m = {
        .f = f,
        .r = r,
        .rt = rt,
        .lf = lf,
        .up = u,
        .dw = d,
        .grm = 175.0
    };

}
