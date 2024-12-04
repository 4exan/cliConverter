#include "conversion.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  bool appWork = true;
  int choice;

  Command commandTable[] = {
      {"q", 0}, {"hex-dec", 1}, {"bin-dec", 2}, {"dec-bin", 3}, {"h", 4}};

  do {
    printf("\033[92mconv:>\033[0m ");
    char input[20];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    for (int i = 0; i < NUM_COMMANDS; i++) {
      if (strcmp(input, commandTable[i].command) == 0) {
        if (commandTable[i].index == 0) {
          printf("\033[91mExit converter...\033[0m\n");
          return 0;
        }
        switch (commandTable[i].index) {
        case 1:
          char hex[10];
          printf("hex -> dec\033[92m:>\033[0m ");
          scanf("%s", hex);
          hexToDecimal(hex);
          getchar();
          break;
        case 3:
          int dec;
          printf("dec -> bin\033[92m:>\033[0m ");
          scanf("%d", &dec);
          decimalToBinary(dec);
          getchar();
          break;
        case 2:
          char bin[16];
          printf("bin -> dec\033[92m:>\033[0m ");
          scanf("%s", bin);
          binaryToDecimal(bin);
          getchar();
          break;
        case 4:
          help();
          break;
        }
      }
    }
  } while (appWork);

  return 0;
}
