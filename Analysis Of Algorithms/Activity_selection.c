//activity selection
#include <stdio.h>
#include <stdlib.h>

void greedy_activity_selector(int s[], int f[], int n){
    int k = 0;
    printf("%d ", k);
    for(int i = 1; i <= n; i++ ){
        if(s[i] >= f[k]){
            printf("%d ", i);
            k = i;
        }
    }
}

int main() {
    int s[] = {1, 3, 0, 5, 3, 5};
    int f[] = {4, 5, 6, 7, 8, 9};
    int n = sizeof(s) /sizeof(s[0]);

      printf("Selected activities: ");
  greedy_activity_selector(s, f,n);

    return 0;
}
