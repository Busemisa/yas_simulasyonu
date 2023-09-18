#include <stdio.h>
#include <time.h>

int main() {
    // Geçerli tarihi almak için zamaný al
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int dogumYili, dogumAy, dogumGun;

    printf("Dogum yilinizi girin: ");
    scanf("%d", &dogumYili);

    printf("Dogum ayinizi girin: ");
    scanf("%d", &dogumAy);

    printf("Dogum gununuzu girin: ");
    scanf("%d", &dogumGun);

    if (dogumYili > tm.tm_year + 1900 || (dogumYili == tm.tm_year + 1900 && dogumAy > tm.tm_mon + 1) ||
        (dogumYili == tm.tm_year + 1900 && dogumAy == tm.tm_mon + 1 && dogumGun > tm.tm_mday)) {
        printf("Gelecekte dogmamissiniz!\n");
    } else {
        int yil = tm.tm_year + 1900 - dogumYili;
        int ay = tm.tm_mon + 1 - dogumAy;
        int gun = tm.tm_mday - dogumGun;

        if (gun < 0) {
            ay--;
            gun += 30; // Bir ayýn ortalama gün sayýsý kullanýldý.
        }
        if (ay < 0) {
            yil--;
            ay += 12;
        }

        printf("Su an %d yil, %d ay ve %d gun yasadiginiz.\n", yil, ay, gun);
    }

    return 0;
}

