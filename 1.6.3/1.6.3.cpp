/*Integrantes:
    -Eleazar Vasquez
    -Manuel Jaramillo
    -Patricio Canales
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
 
 int students, counter=0;
 double payments[1000], total=0, deficits[1000], surplus[1000];
 
 while(1)
 {
 cin >> students;
 total = 0;
 if (students == 0)
 {
 for (int i=0; i<counter; i++)
 {
 if (deficits[i] < surplus[i]) deficits[i] = surplus[i];
 
 cout << '$' << setprecision(2) << fixed << deficits[i] << endl;
 }
 
 return 0;
 }
 
 for (int i=0; i<students; i++) {cin >> payments[i]; total+= payments[i];}
 
 total /= students;
 
 deficits[counter] = 0;
 surplus[counter] = 0;
 for (int i=0; i<students; i++)
 if (payments[i] < total) deficits[counter] += (floor((total - payments[i])*100))/100;
 else if (payments[i] > total) surplus[counter] += (floor((-total + payments[i])*100))/100;
 
 counter++;
 }
 
 return 0;

}