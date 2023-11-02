#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    unsigned n_mask = 1 << n;
    unsigned masked_x = x & n_mask;
    int res = masked_x >> n;
    return res;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    unsigned n_mask = 1 << n;
    unsigned neg_n_mask = ~ n_mask;
    unsigned clear_nth_x = neg_n_mask & *x;
    unsigned v_mask = v << n;
    *x = clear_nth_x | v_mask;
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    unsigned nth_bit_val = get_bit(*x, n);
    unsigned target_val = nth_bit_val ^ 1; // correct way to reverse a single bit
    set_bit(x, n, target_val);
}

