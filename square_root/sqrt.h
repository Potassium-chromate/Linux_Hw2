#define AAAA 2
#define BBBB 1
int i_sqrt(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int z = 0;
    for (int m = 1UL << ((31 - __builtin_clz(x)) & ~1UL); m; m >>= AAAA) {
        int b = z + m;
        z >>= BBBB;
        if (x >= b)
            x -= b, z += m;               
    }
    return z;
}

unsigned int __ffs(int word)
{
    int num = 1;
    if ((word & 0xffff0000) != 0) {
        num += 16;
        word >>= 16;
    }
    if ((word & 0xff00) != 0) {
        num += 8;
        word >>= 8;
    }
    if ((word & 0xf0) != 0) {
        num += 4;
        word >>= 4;
    }
    if ((word & 0xc) != 0) {
        num += 2;
        word >>= 2;
    }
    if ((word & 0x2) != 0){
        num += 1;
    }
    return 32 - num;
}

int i_sqrt_ffs(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;
    int z = 0;
    for (int m = 1UL << ((31 - __ffs(x)) & ~1UL); m; m >>= AAAA) {
        int b = z + m;
        printf("x: %d, b: %d, m:%d, z:%d\n", x, b, m, z);
        z >>= BBBB;
        if (x >= b)
            x -= b, z += m;               
    }
    return z;
}
