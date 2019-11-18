/**************************************
 *              Projekt 2             *
 *          Iterační výpočty          *
 *                                    *
 *      author: Pavol Gumancik        *
 *      login: xguman01               *
 *      date: Nov 18. 2019            *
 *                                    *
 *************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*@brief Kontrola, ci su argumenty validne
 *
 *@param argc pocet argumentoc
 *@param argv argumenty programu
 */
bool is_number(int argc, char *argv[]) {
  bool statement = false;

  return statement;
}

/*@brief Kontrola poctu argumentov
 *
 *@param argc pocet argumentoc
 */
bool argument_check(int argc) {
  bool statement = false;
  if (argc == 4) {
    statement = true; // Valid number of arguments
  }
  else {
    fprintf(stderr, "Invalid number of arguments! Alloved 4, entered %d",argc);
  }
  return statement;
}

// ./proj2 U0 R EPS
// gcc -std=c99 -Wall -Wextra -Werror proj2.c -lm -o proj2
// U0 je hodnota vstupního napětí ve Voltech,
// R je odpor rezistoru v Ohmech a
// EPS je absolutní chyba/přestnost/odchylka (epsilon),
int main(int argc, char *argv[]) {
  if(!argument_check(argc) || !is_number(argc, argv)) {
    return 1;
  }
  printf("ide%d\n",argc);
  return 0;
}
