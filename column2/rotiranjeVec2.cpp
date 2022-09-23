#include <iostream>
#include <cstring>

// rotdist = times

int nzd (int a,int b) {
    if (b==0) return a; 
    return nzd(b,a%b);
}

void rotateNtimes(char *str, int times) {
    char tmp;
    int n = strlen(str);

    // nzd(times, n) je broj puta koliko ce se razmena morati dogoditi
    for(int i=0; i<nzd(times, n); i++) {
        int j = i;
        tmp = str[i];

        // overview algoritma: 
        // tmp <- str[0]; str[0] <- str[n]; str[n] <- str[2n]; ...; str[xn] <- tmp
        // NOTE: indeks ne ide od 0 do kraja stringa, nego od pocetka
        //       dok ne treba da se opet uzme od nultog clana

        while(1) {
            int k = j + times;  // nova pozicija karaktera kojeg treba da pomerimo u levo
            if(k >= n) k -= n;  // ako smo prosli ceo string, vrtimo se nazad od pocetka
            if(k == i) break;   // treba da se uzme od str[0] => zavrsavamo loop

            str[j] = str[k];
            j = k;
        }
        str[j] = tmp;
    }
}

int main(void) {

    char str[] = "abcdef";

    rotateNtimes(str, 3);
    puts(str);

    return 0;
}
