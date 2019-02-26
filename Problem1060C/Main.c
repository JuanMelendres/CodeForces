#include <stdio.h>
#include <string.h>

long long t[2000][2000];
int n, m, li;
long long a[2001],b[2001];
long long f[2001],s[2001];

int main(){
    
    scanf("%d %d",&n,&m);
    int i, j, res = 0;
    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));
    a[0] = b[0] = 0;
    for(i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
        for(j = i; j; j--){
            if(f[i - j + 1] == 0 || f[i - j + 1] > a[i] - a[j - 1]){
                f[i - j + 1] = a[i] - a[j - 1];
            }
        }
    }
    for( i = 1; i <= m; i++){
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];
        for(j = i; j; j--){
            if(s[i - j + 1] == 0 || s[i - j + 1] > b[i] - b[j - 1]){
                s[i - j + 1] = b[i] - b[j - 1];
            }
        }
    }
    scanf("%d",&li);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(f[i] * s[j] <= li && i * j > res) 
                res = i * j;
        }
    }
    printf("%d\n",res);
    
    return 0;
}