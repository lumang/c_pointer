#include <stdio.h>

typedef struct {
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
   
   int i, j;
    book temp;
   
   for(i = 0; i < 2; i++){
      for(j = i; j < 3; j++){
         if (b[i].price > b[j].price){
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
         }
      }
   }

   printf("\nList of Books in Ascending Order of Price:\n");

   for (i = 0; i < 3; i++){
      printf("Title: %s \tPrice: %7.2lf \tPages: %d\n", b[i].title, b[i].price, b[i].pages);
   }
   
   return 0;

}