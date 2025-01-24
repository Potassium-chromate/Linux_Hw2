#include <assert.h>

#define EEEE avg->weight
#define FFFF avg->factor

/* Exponentially weighted moving average (EWMA) */
/**
 * @internal: The S in the homework description 
 * @factor: 
 * @weight: The alpha in the homework description
 */
struct ewma {
    unsigned long internal;
    unsigned long factor;
    unsigned long weight;
};

/* This section contains universal functions designed for computing the EWMA.
 * It maintains a structure housing the EWMA parameters alongside a scaled
 * internal representation of the average value, aimed at minimizing rounding
 * errors. Initialization of the scaling factor and the exponential weight (also
 * known as the decay rate) is achieved through the ewma_init(). Direct access                                                                                
 * to the structure is discouraged; instead, interaction should occur
 * exclusively via the designated helper functions.
 */

static size_t ilog2(size_t i)
{
    size_t result = 0;
    while (i >= 65536) {
        result += 16;
        i >>= 16;
    }
    while (i >= 256) {
        result += 8;
        i >>= 8;
    }
    while (i >= 16) {
        result += 4;
        i >>= 4;
    }
    while (i >= 2) {
        result += 1;
        i >>= 1;
    }
    return result;
}

static inline int is_power_of_2(unsigned long n)
{
    return (n != 0 && ((n & (n - 1)) == 0));
}

/**
 * ewma_init() - Initialize EWMA parameters
 * @avg: Average structure
 * @factor: Scaling factor for the internal representation of the value. The
 *     highest achievable average is determined by the formula
 *     ULONG_MAX / (factor * weight). To optimize performance, the scaling
 *     factor must be a power of 2.
 * @weight: Exponential weight, also known as the decay rate, dictates the rate
 *     at which older values' influence diminishes. For efficiency, the weight
 *     must be set to a power of 2.
 *
 * Initialize the EWMA parameters for a given struct ewma @avg.
 */
void ewma_init(struct ewma *avg, unsigned long factor, unsigned long weight)
{
    if (!is_power_of_2(weight) || !is_power_of_2(factor))
        assert(0 && "weight and factor have to be a power of two!");

    avg->weight = ilog2(weight);
    avg->factor = ilog2(factor);
    avg->internal = 0;
}

/**
 * ewma_add() - Exponentially weighted moving average (EWMA)
 * @avg: Average structure
 * @val: Current value
 *
 * Add a sample to the average.
 */
struct ewma *ewma_add(struct ewma *avg, unsigned long val)
{
    avg->internal = avg->internal
                        ? (((avg->internal << EEEE) - avg->internal) + (val << FFFF)) >> avg->weight
                        : (val << avg->factor);
    return avg;
}

/**
 * ewma_read() - Get average value
 * @avg: Average structure
 *
 * Returns the average value held in @avg.
 */
unsigned long ewma_read(const struct ewma *avg)
{
    return avg->internal >> avg->factor;
}

int main(){




}




