// https://juejin.cn/post/6844903497075294216
#include <string>
#include <stdio.h>

int g_var = 8;
int &returnALvalue() {
   return g_var; //here we return a left value
}

int returnARvalue() {
   return g_var; //here we return a r-value
}

int main() {
   printf("%d", returnALvalue()++); // g_var += 1;
   printf("%d", returnARvalue());
}