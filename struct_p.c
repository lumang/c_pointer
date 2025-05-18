#include <stdio.h>

typedef struct  {
   char title[15];
   double price;
   int pages;
}book;

int main(){

    book b[3] = {
      {"Learn C", 650.50, 325}, 
      {"C Pointers", 175, 225}, 
      {"C Pearls", 250, 250}
   };

    book *ptr = b;

   for(int i = 0; i < 3; i++){
      printf("Title: %s \tPrice: %7.2lf \tPages: %d\n", ptr -> title, ptr -> price, ptr -> pages);
      ptr++;
   }
   
   return 0;
}