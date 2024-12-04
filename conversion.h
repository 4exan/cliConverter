#ifndef CONVERSION_H
#define CONVERSION_H

void hexToDecimal(char *hex);
void decimalToBinary(int dec);
void binaryToDecimal(char *bin);
void help();

typedef struct {
  char command[10];
  int index;
} Command;

#define NUM_COMMANDS 5
#endif
