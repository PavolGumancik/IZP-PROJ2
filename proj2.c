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
#include <string.h>
#include <ctype.h>

const double I0 = 0.00000000001; // A
const double UT = 0.0258563; // V

/*@brief Kontrola, ci su argumenty validne
 *
 *@param argc pocet argumentoc
 *@param argv argumenty programu
 */
bool is_number(int argc, char *argv[]) {
  bool statement = false;

  for (int j = 1; j < argc; j++) {     // prebehne argumenty
    bool exponent = false;
    bool dot = false;
    char *argument = argv[j];
    if ((argument[0] == '+') || (argument[0] == '-') || (isdigit(argument[0])) ) {
      for (unsigned int i = 1; i < strlen(argument); i++) { // prebehne chary v argumente
          if ((argument[i] == 'e') || (isdigit(argument[i]) || (argument[i] == '.')) ) {
            statement = true;         // vyhovuje => true
            if (argument[i] == '.') {
              if (dot == true) {
                fprintf(stderr, "Multiple dot in argument!");
                return false;
              }
              dot = true;
            }
            if (argument[i] == 'e') { // osetrenie viacnasobneho exponentu
              if (exponent == true) {
                fprintf(stderr, "Multiple exponent in argument!");
                return false;
              }
              exponent = true;
              if ((argument[i+1] == '+') || (argument[i+1] == '-')) { // nasledujuci znak za e moze byt +/-
                i++; // posuniem za +/-
              }
            }
          }
          else {                      // nevyhovujuci charakter
            fprintf(stderr,"Invalid characters in arguments!");
            return false;
          }
      }
    }
    else {
      fprintf(stderr,"Invalid characters in arguments!");
      return false;
    }
  }
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
    fprintf(stderr, "Invalid number of arguments! Alloved 4, entered %d\n",argc);
  }
  return statement;
}

/*@brief Iterace volana rekurzi
 *
 *@param u0 Hodnota vstupního napětí ve Voltech
 *@param r Odpor rezistoru v Ohmech
 *@param eps
 */
void iteration(double u0, double r, double eps) {



  /*if ((-) == eps) {
    printf("Up=%gV\nIp=%g A\n", );
  }*/
}

/*@brief Konvertuje argumenty na double a skontroluje intervaly
 *
 *@param argv Argumenty programu
 */
void string_to_double(char *argv[]) {
  double u0 = 0.0;
  double r = 0.0;
  double eps = 0.0;

  sscanf(argv[1], "%lf", &u0);  //conver to double
  sscanf(argv[2], "%lf", &r);   //conver to double
  sscanf(argv[3], "%lf", &eps); //conver to double

  if (r <= 0.0) {
    fprintf(stderr, "R can not be equal or less than zero!");
    return;
  }
  if (u0 < 0.0) {
    fprintf(stderr, "U0 can not be less than zero!");
    return;
  }
  if (eps < 0.0) {
    fprintf(stderr, "EPS can not be less than zero!");
    return;
  }

  iteration(u0, r, eps);

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
  string_to_double(argv);
  return 0;
}
