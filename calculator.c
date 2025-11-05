#include <stdio.h>
int main() {
  
  int num1, num2;
  char operation;
  
  printf("Enter two integers. Press return after each integer.\n");
  scanf("%d", &num1);
  scanf("%d", &num2);
  
  printf("Enter an operation (+,-,*,/, or %%). Then press return.\n");
  scanf(" %c", &operation);
  
  if (operation =='+'){
    printf("%d\n",num1+num2);}
  if (operation =='-'){
    printf("%d\n",num1-num2);}
  if (operation == '*') {
    printf("%d\n", num1 * num2);}
  if (operation == '/') {
    printf("%d\n", num1 / num2);}
  if (operation == '%') {
    printf("%d\n", num1 % num2);}
  else {
        return 0; }
  
  return 0;
}
