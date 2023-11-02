#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

uint16_t get_bit(uint16_t x,
                 uint16_t n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    uint16_t n_mask = 1 << n;
    uint16_t masked_x = x & n_mask;
    int res = masked_x >> n;
    return res;
}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t cur_num = *reg;
    uint16_t right_shifted_num = cur_num >> 1;
    
    uint16_t left_head = get_bit(cur_num, 0) ^ get_bit(cur_num, 3) ^ 
    get_bit(cur_num, 5) ^ get_bit(cur_num, 2);
    left_head = left_head << 15;
    *reg = left_head | right_shifted_num;
}

