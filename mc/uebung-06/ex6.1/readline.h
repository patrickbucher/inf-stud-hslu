/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifndef _READLINE_H 
#define _READLINE_H

// readline reads a line from the standard input, writes it to buf and returns
// the number of characters read. buf must be of size n. buf won't contain the
// trailing newline character and will be null-terminated. If buf is too small,
// the input will be truncated.
int readline(char *buf, int n);

// freadline is the readline function for other input sources than stdin.
int freadline(FILE *f, char *buf, int n);

// stoi converts the string in buf of length n to an integer.
int stoi(char *buf, int n);

#endif
