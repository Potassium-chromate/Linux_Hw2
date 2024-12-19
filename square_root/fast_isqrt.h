#include <stdio.h>
#include <stdint.h>

// Precomputed square roots for numbers 0-255
static const unsigned char sqrt_table[256] = {
    0,  1,  1,  1,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,
    4,  4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,
    5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
    6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,
    8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
    8,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
    9,  9,  9,  9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
};

// Fast integer square root using lookup table and NR refinement
int fast_i_sqrt(int x) {
    if (x <= 1)
        return x;

    // Use table for numbers in the 8-bit range
    if (x < 256)
        return sqrt_table[x];

    // Determine the offset by shifting right in chunks of 8 bits
    int offset = 0;
    int temp = x;
    while (temp >= 256) {
        temp >>= 8;
        offset += 8;
    }

    // Get the high byte and initial approximation
    int high_bytes = (x >> offset) & 0xff;  // Extract high byte
    int approx = sqrt_table[high_bytes] << (offset >> 1);  // Scale the approximation

    // Newton-Raphson refinement
    int y = approx;
    y = (y + x / y) >> 1;  // First iteration
    y = (y + x / y) >> 1;  // Second iteration
    y = (y + x / y) >> 1;
    y = (y + x / y) >> 1;

    // Ensure the result is not overestimated
    
    if (y * y > x)
        y--;
    

    return y;
}



