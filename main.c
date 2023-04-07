//1220505011 AY�E G�L DAL 
//D�Z�Y� TOPLAMI E��T ALT K�MEYE B�LME 

#include <stdio.h>
#include <math.h>

   //ALT K�ME OLU�TURMA FONKS�YONU 
int altkumeToplam(int arr[], int n, int sum)     //n:dizinin boyutu, sum:elemanlar� toplam�.
{
    int altkume[n+1][sum+1];       // Alt k�me toplamlar�n� saklamak i�in bir bool dizisi olu�turulur.
   int i,j;
    for (i = 0; i <= n; i++)  //Alt k�menin birinci s�tunu girilen diznin boyutu kadar 1 ile dolduruluyor.
        altkume[i][0] = 1;            
        
    for (i = 1; i <= sum; i++)     //Alt k�menin birinci sat�r� g�nderilen toplam kadar 1 ile dolduruluyor. 
        altkume[0][i] = 0;
   
   
                   // Toplam� tam olarak i'ye e�itlemek i�in alt k�meler bulunur.
    for (i = 1; i <= n; i++) {       //Olu�turulan alt k�menin elemanlar�n� dola��r.
        for (j = 1; j <= sum; j++) {
            if (j < arr[i-1])            //Ko�ul sa�lan�yorsa a�a��daki i�lemleri uygular.
                altkume[i][j] = altkume[i-1][j];         // Bu eleman alt k�meye dahil edilebilir mi?
            if (j >= arr[i-1])           //Ko�ul sa�lan�yorsa a�a��daki i�lemleri uygular.
              altkume[i][j] = altkume[i-1][j] || altkume[i - 1][j-arr[i-1]];   //Altk�melerden en az birisinin 
        }
    }
            // "toplam" de�erine e�it iki alt k�me var m�?
    return altkume[n][sum];       //Olu�an alt k�meyi d�nd�r�r.
}

int main()
{
    int n;   //Dizinin eleman say�s�n� tan�mlad�k.
    int i;
    printf("Dizi eleman sayisini girin: ");   //Ekrana yazd�rma.
    scanf("%d", &n);  //Dizinin eleman say�s�n� kullan�c�dan ald�k.
    int set[n];   //set ad�nda dizi tan�mlad�k ve elemanlar�m�z� oraya atad�k.
    int toplam = 0;   //Dizinin elemanlar�n�n toplam�n� atayaca��m�z bir de�i�ken atad�k.
    printf("Dizi elemanlarini girin:\n");
    for (i = 0; i < n; i++) {   //Girilen elemanlar�n toplam�n� bulan d�ng�.
        scanf("%d", &set[i]);
        if(set[i]<0){
        	printf("NEGATIF BIR SAYI GIRILEMEZ");
        	return 0;
		}
        toplam += set[i];
    }
    
    if (toplam % 2 == 0 && altkumeToplam(set, n, toplam/2))   //Toplamlar� e�it olaca�� i�in ikiye b�l�nmeli ve altkumeToplam fonksiyonu sa�lanmal�.
        printf("DIZI IKI ALT KUMESINE BOLUNEBILIR\n");
    else                                                      //Yukar�daki ko�ul sa�lanm�yorsa b�l�nemez.
        printf("DIZI IKI ALT KUMESINE BOLUNEMEZ\n");
    return 0;
}
