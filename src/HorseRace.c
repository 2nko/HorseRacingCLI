#include <stdio.h>
#include <stdlib.h>
#include "time.h"

// global index, for simplicity's sake.
int i;

int main(void){
  system("clear");
  for (i = 3; i > 0; i--){
    printf("please make sure that your terminal is on full screen!\n");
    printf("> exit by pressing ctrl+c multiple times.\n");
    printf("- - - - - - - - - - -\n");
    printf("gonna proceed in %d...\n", i);
    system("sleep 1 && clear");
  }

  // initial budget: $750
  int totMoney = 750;
  int bet;
  int inputCheck;
  /*
   * Setting the title:
   __         _   _                       ____            _                     __
  | _|       | | | | ___  _ __ ___  ___  |  _ \ __ _  ___(_)_ __   __ _   _    |_ |
  | (_)____  | |_| |/ _ \| '__/ __|/ _ \ | |_) / _` |/ __| | '_ \ / _` | (_)____| |
  | ||_____| |  _  | (_) | |  \__ \  __/ |  _ < (_| | (__| | | | | (_| |  |_____| |
  | (_)      |_| |_|\___/|_|  |___/\___| |_| \_\__,_|\___|_|_| |_|\__, | (_)    | |
  |__|                                                            |___/        |__|

   */
  char *title = " __         _   _                       ____            _                     __ \n| _|       | | | | ___  _ __ ___  ___  |  _ \\ __ _  ___(_)_ __   __ _   _    |_ |\n| (_)____  | |_| |/ _ \\| '__/ __|/ _ \\ | |_) / _` |/ __| | '_ \\ / _` | (_)____| |\n| ||_____| |  _  | (_) | |  \\__ \\  __/ |  _ < (_| | (__| | | | | (_| |  |_____| |\n| (_)      |_| |_|\\___/|_|  |___/\\___| |_| \\_\\__,_|\\___|_|_| |_|\\__, | (_)    | |\n|__|                                                            |___/        |__|\n\t\t\t\tMade w/ <3 by 2nko\n";

  i = 0;
  printf("%s\n", title);
  printf("Wallet: $%d\n", totMoney);
  do{
    printf("please place your bet! ($100-$1000) ");
    inputCheck = scanf("%d", &bet);
    if (inputCheck != 1){
      printf("not a valid bet.. do not in include decimals, $ or any other character!\n\n");
    }
    else if (bet < 100){
      printf("you cannot bet that low!\n\n");
    }
    else if (bet > totMoney) {
      printf("we appreciate your enthusiasm, however, that is over your budget!!\n");
    }
    else if(bet > 1000){
      printf("we appreciate your enthusiasm, however, you can bet a maximum of $1000 at a time!\n");
    }

    while(getchar() != '\n');
    i++;
    if (i == 4){
      i = 0;
      system("clear");
      printf("%s\n", title);
    }
  } while (bet < 100 || inputCheck != 1);
  if (bet %10 != 0){
    printf("so precise! however.. we are gonna round $%d to ", bet);
    bet /= 10;
    bet *= 10;
    printf("$%d for sempicity's sake.\n", bet);
  }
  
  
  printf("you bet: %d\n", bet);  
}
