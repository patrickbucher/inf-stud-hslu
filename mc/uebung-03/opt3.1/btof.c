/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

float btof(uint8_t[]);

int main()
{
    uint8_t bytes[4];
    float number;

    // 1.875 = 00111111 11110000 00000000 00000000
    bytes[0] = 0x3f;
    bytes[1] = 0xf0;
    bytes[2] = 0x00;
    bytes[3] = 0x00;
    number = btof(bytes);
    printf("%.9f\n", number);

    // -0.9384785 = 10111111 01110000 01000000 00100001
    bytes[0] = 0xbf;
    bytes[1] = 0x70;
    bytes[2] = 0x40;
    bytes[3] = 0x21;
    number = btof(bytes);
    printf("%.9f\n", number);

    return 0;
}

// IEE 754 single precision format
// byte: 0        1        2        3
// bits: SEEEEEEE EMMMMMMM MMMMMMMM MMMMMMMM
// S: sign
// E: exponent
// M: mantisse
float btof(uint8_t bytes[])
{
    bool negative = false;
    int i;
    int8_t exponent = 0;
    uint8_t sign, pos;
    float mantisse = 0.0f;
    float fsign;
    
    negative = bytes[0] & 0x80; // first bit (0x80 = b10000000)

    // exponent: b01111111 1
    exponent = bytes[1] & 0x80 ? 1 : 0; // first bit of second byte
    // first seven bits of first byte
    for (pos = 1, i = 0, sign = 2; i < 7; i++, sign *= 2, pos = pos << 1) {
        exponent += bytes[0] & pos ? sign : 0;
    }
    exponent -= 127; // bias

    // mantisse: 0.5, 0.25, 0.125 etc.

    // second byte: b01111111, b01000000 = 0x40, 
    for (pos = 0x40, i = 6, fsign = 0.5; i >= 0; i--, fsign /= 2.0f, pos = pos >> 1) {
        mantisse += bytes[1] & pos ? fsign : 0;
    }
    // third byte:  b11111111, b10000000 = 0x80,
    for (pos = 0x80, i = 7; i >= 0; i--, fsign /= 2.0f, pos = pos >> 1) {
        mantisse += bytes[2] & pos ? fsign : 0;
    }
    // fourth byte: b11111111, b10000000 = 0x80
    for (pos = 0x80, i = 7; i >= 0; i--, fsign /= 2.0f, pos = pos >> 1) {
        mantisse += bytes[3] & pos ? fsign : 0;
    }
    mantisse += 1;

    if (negative) {
        mantisse *= -1;
    }

    return mantisse * powf(2.0f, exponent);
}
