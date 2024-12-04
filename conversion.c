#include "conversion.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void help() {
  puts("\033[32mCLI Converter\033[0m | Version: 0.1");
  puts("Available commands:");
  puts("q        - Exit");
  puts("hex-dec  - Hexidecimal to Decimal");
  puts("dec-bin  - Decimal to Binary");
  puts("bin-dec  - Binary to Decimal (16 bit)");
}

int convertLetterToDecimal(char c) {
  switch (c) {
  case 'A':
    return 10;
  case 'B':
    return 11;
  case 'C':
    return 12;
  case 'D':
    return 13;
  case 'E':
    return 14;
  case 'F':
    return 15;
  default:
    return 0;
  }
}

void reverseCharArray(char *arr) {
  int start = 0;
  int end = strlen(arr) - 1;

  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }
}

void convertHexToDec(char *hex) {
  int res = 0;
  int temp;

  for (int i = 0; i < strlen(hex); i++) {
    if (isdigit(hex[i])) {
      int temp = (hex[i] - '0') * pow(16, i);
      res += temp;
    } else {
      temp = convertLetterToDecimal(hex[i]) * pow(16, i);
      res += temp;
    }
  }
  printf("Decimal: %d\n", res);
}

void hexToDecimal(char *hex) {
  reverseCharArray(hex);
  convertHexToDec(hex);
}

void decimalToBinary(int dec) {

  char binary[16];
  int counter = 0;
  int number = dec;
  do {
    if (counter < 16) {
      int reminder = number % 2;
      if (reminder == 1) {
        binary[counter] = '1';
        counter++;
      } else if (reminder == 0) {
        binary[counter] = '0';
        counter++;
      } else {
        binary[counter] = '0';
      }
      number = (int)(number / 2);
    } else {
      break;
    }
  } while (counter < 16);

  reverseCharArray(binary);

  for (int i = 0; i < strlen(binary); i++) {
    printf("%c", binary[i]);
  }
  printf("\n");
}

void binaryToDecimal(char *bin) {
  reverseCharArray(bin);
  int counter = 0;
  int decimalValue = 0;
  while (counter < 16) {
    if (bin[counter] == '1') {
      decimalValue += pow(2, counter);
    }
    counter++;
  }
  printf("Decimal: %d\n", decimalValue);
}
