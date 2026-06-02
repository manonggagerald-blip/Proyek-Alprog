#include <stdio.h>

int main(){
int n;

printf("Masukkan nilai n: ");
scanf("%d",&n);

int arr[n];
printf("Masukkan data array: ");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
printf("%d",arr[i]);
}


return 0;  
}
