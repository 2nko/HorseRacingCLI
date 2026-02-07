// (C) 2nko, under the MPL License (see LICENSE)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// global index, for simplicity's sake.
int i;

int main(void){
  system("clear");
  for (i = 3; i > 0; i--){
    printf("please make sure that your terminal is on full screen!\n");
    printf("> you can exit by pressing ctrl+c.\n");
    printf("- - - - - - - - - - -\n");
    printf("gonna proceed in %d...\n", i);
    sleep(1);
    system("cls");
  }

  // initial budget: $750
  int totMoney = 750;
  int bet;
  int inputCheck;
  /*
   * I have used figlet for this.
   * Setting the title:
   __        _   _                     ____            _              ____ _     ___        __
  | _|      | | | | ___  _ __ ___  ___|  _ \ __ _  ___(_)_ __   __ _ / ___| |   |_ _|      |_ |
  | (_)____ | |_| |/ _ \| '__/ __|/ _ \ |_) / _` |/ __| | '_ \ / _` | |   | |    | |  ____(_) |
  | ||_____||  _  | (_) | |  \__ \  __/  _ < (_| | (__| | | | | (_| | |___| |___ | | |_____|| |
  | (_)     |_| |_|\___/|_|  |___/\___|_| \_\__,_|\___|_|_| |_|\__, |\____|_____|___|     (_) |
  |__|                                                         |___/                       |__|

   */
  char *title = " __        _   _                     ____            _              ____ _     ___        __ \n| _|      | | | | ___  _ __ ___  ___|  _ \\ __ _  ___(_)_ __   __ _ / ___| |   |_ _|      |_ |\n| (_)____ | |_| |/ _ \\| '__/ __|/ _ \\ |_) / _` |/ __| | '_ \\ / _` | |   | |    | |  ____(_) |\n| ||_____||  _  | (_) | |  \\__ \\  __/  _ < (_| | (__| | | | | (_| | |___| |___ | | |_____|| |\n| (_)     |_| |_|\\___/|_|  |___/\\___|_| \\_\\__,_|\\___|_|_| |_|\\__, |\\____|_____|___|     (_) |\n|__|                                                         |___/                       |__|\n\t\t\t\t\tMade w/ <3 by 2nko\n";

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
    else if(bet > 1000){
      printf("we appreciate your enthusiasm, however, you can bet a maximum of $1000 at a time!\n");
    }
    else if (bet > totMoney) {
      printf("we appreciate your enthusiasm, however, that is over your budget!!\n");
    }

    while(getchar() != '\n');
    i++;
    if (i == 4){
      i = 0;
      system("cls");
      printf("%s\n", title);
    }
  } while (bet < 100 || inputCheck != 1);
  if (bet %10 != 0){
    printf("so precise! however.. we are gonna round $%d to ", bet);
    bet /= 10;
    bet *= 10;
    printf("$%d for sempicity's sake.\n", bet);
  }
  printf("\nand now, let the game begin!");

  printf("you bet: %d\n", bet);
}
