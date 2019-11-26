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

#define I0 1e-12 // A
#define UT 0.0258563 // V

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
    for (size_t m = 0; m < strlen(argument); m++) { // pre pripad velkosti v inf a nan
      if (argument[m]>64 && argument[m]<91)  //pokud je znak velke pismeno
        {
          argument[m] += ('a'-'A'); // konvertuje v asci na male pismeno
        }
    }

    if ((strcmp(argument,"inf") == 0)||(strcmp(argument,"-inf") == 0)||(strcmp(argument,"nan") == 0)) {
      statement = true; // Akceptuje aj hodnoty inf a nan
    }

    else if ((argument[0] == '+') || (argument[0] == '-') || (isdigit(argument[0])) ) {
      for (unsigned int i = 1; i < strlen(argument); i++) { // prebehne chary v argumente
          if ((argument[i] == 'e') || (isdigit(argument[i]) || (argument[i] == '.')) ) {
            statement = true;         // vyhovuje => true
            if (argument[i] == '.') {
              if (dot == true) {
                fprintf(stderr, "Multiple dot in argument!\n");
                return false;
              }
              dot = true;
            }
            if (argument[i] == 'e') { // osetrenie viacnasobneho exponentu
              if (exponent == true) {
                fprintf(stderr, "Multiple exponent in argument!\n");
                return false;
              }
              exponent = true;
              if ((argument[i+1] == '+') || (argument[i+1] == '-')) { // nasledujuci znak za e moze byt +/-
                i++; // posuniem za +/-
              }
            }
          }
          else {                      // nevyhovujuci charakter
            fprintf(stderr,"Invalid characters in arguments!\n");
            return false;
          }
      }
    }
    else if (statement == false){
      fprintf(stderr,"Invalid characters in arguments!\n");
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

/*@brief Pocita hodnoty s danym napatim
 *
 *@param up Okrajove napatie
 *@param up1 Okrajove napatie
 *@param r Odpor rezistora
 *@param u0 Pociatocne napatie
 */
double schotly(double up,double u0, double r, double up1) {
  double i = (I0*(exp(up / UT) - 1) - ((u0 - up) / r)) - (I0*(exp(up1 / UT) - 1) - ((u0 - up1) / r));
  //printf("%g\n",I0*(exp(up / UT) - 1) - ((u0 - up) / r));
  //printf("%g\n\n",I0*(exp(up1 / UT) - 1) - ((u0 - up1) / r));
  return i;
}

/*@brief Pocita hodnoty s danym napatim
 *
 *@param un Pociatocne napatie
 *@param r Odpor rezistora
 *@param eps Absolutní přesnost (maximální požadovaná odchylka)
 */
double eval_func(double up, double u0, double r) {
  return I0*(exp(up / UT) - 1) - ((u0 - up) / r);
}

/*@brief Pocita Up s danou presnostou
 *
 *@param un Pociatocne napatie
 *@param r Odpor rezistora
 *@param eps Absolutní přesnost (maximální požadovaná odchylka)
 */
double diode(double u0, double r, double eps) {

  double b = u0;
  double a = 0.0;
  double middle= (a + b) / 2; // stred intervalu
  double fmid= eval_func(middle, u0, r); // hodnota v danom intervale
  int counter = 0;

  while ((fabs(schotly(a, u0, r, b)) > eps) && (counter < 20000)) {
    if (eval_func(a, u0, r) * fmid < 0)
      b = middle; // je zaporne, nachadza sa v danom intervale -> prepisem koniec
    else
      a = middle;
    if (fabs(schotly(a, u0, r, b)) > eps){
      middle = (a + b) / 2;
      fmid = eval_func(middle, u0, r);
    }
    counter++;
  }
  if (counter >= 20000) {
  fprintf(stderr, "Breaks to prevent inf loop.\n");
  }
  return middle; //up
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
    fprintf(stderr, "R can not be equal or less than zero!\n");
    return;
  }
  /*if (u0 < 0.0) {
    fprintf(stderr, "U0 can not be less than zero!\n");
    return;
  }*/
  if (eps <= 0.0) {
    fprintf(stderr, "EPS can not be less or EQ than zero!\n");
    return;
  }
  double up = diode(u0, r, eps);

  printf("Up=%g V\nIp=%g A\n",up, (u0-up)/r);
}


// gcc -std=c99 -Wall -Wextra -Werror proj2.c -lm -o proj2

int main(int argc, char *argv[]) {
  if(!argument_check(argc) || !is_number(argc, argv)) {
    return 1;
  }
  string_to_double(argv);

  return 0;
}
