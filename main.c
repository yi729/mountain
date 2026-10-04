#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);
    int h[n];
    int i;
    for (i=0;i<n;i++) {
        scanf("%d",&h[i]);
    }
    int judge=0;
    for (i=0;i<n-1;i++) {
        if (h[i]<h[i+1])
            judge=1;
    }
    if (judge==0) {
        printf("0.00\n");
    }else {
        i=0;
        double p[10000]={0};
        int t=0;
        int k;
        while (i<n) {
            k=i;
            while (h[k]<h[k+1]) {
                if (h[k+1]>h[k+2]||(k+2)==n) {
                    p[t]=1.0*(h[k+1]-h[i])/(k+1-i);
                    t++;
                    i=k+1+1;
                    break;
                }
                k++;
            }
            if (h[k]>h[k+1]) {
                i++;
            }

        }
        double min=p[0];
        for (i=1;i<1000;i++) {
            if (min>p[i]&&p[i]!=0)
                min=p[i];
            if (p[i+1]==0)
                break;
        }
        printf("%.2f\n",min);
    }
    return 0;
}
