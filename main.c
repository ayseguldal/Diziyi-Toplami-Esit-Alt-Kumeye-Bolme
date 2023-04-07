//1220505011 AYÞE GÜL DAL 
//DÝZÝYÝ TOPLAMI EÞÝT ALT KÜMEYE BÖLME 

#include <stdio.h>
#include <math.h>

   //ALT KÜME OLUÞTURMA FONKSÝYONU 
int altkumeToplam(int arr[], int n, int sum)     //n:dizinin boyutu, sum:elemanlarý toplamý.
{
    int altkume[n+1][sum+1];       // Alt küme toplamlarýný saklamak için bir bool dizisi oluþturulur.
   int i,j;
    for (i = 0; i <= n; i++)  //Alt kümenin birinci sütunu girilen diznin boyutu kadar 1 ile dolduruluyor.
        altkume[i][0] = 1;            
        
    for (i = 1; i <= sum; i++)     //Alt kümenin birinci satýrý gönderilen toplam kadar 1 ile dolduruluyor. 
        altkume[0][i] = 0;
   
   
                   // Toplamý tam olarak i'ye eþitlemek için alt kümeler bulunur.
    for (i = 1; i <= n; i++) {       //Oluþturulan alt kümenin elemanlarýný dolaþýr.
        for (j = 1; j <= sum; j++) {
            if (j < arr[i-1])            //Koþul saðlanýyorsa aþaðýdaki iþlemleri uygular.
                altkume[i][j] = altkume[i-1][j];         // Bu eleman alt kümeye dahil edilebilir mi?
            if (j >= arr[i-1])           //Koþul saðlanýyorsa aþaðýdaki iþlemleri uygular.
              altkume[i][j] = altkume[i-1][j] || altkume[i - 1][j-arr[i-1]];   //Altkümelerden en az birisinin 
        }
    }
            // "toplam" deðerine eþit iki alt küme var mý?
    return altkume[n][sum];       //Oluþan alt kümeyi döndürür.
}

int main()
{
    int n;   //Dizinin eleman sayýsýný tanýmladýk.
    int i;
    printf("Dizi eleman sayisini girin: ");   //Ekrana yazdýrma.
    scanf("%d", &n);  //Dizinin eleman sayýsýný kullanýcýdan aldýk.
    int set[n];   //set adýnda dizi tanýmladýk ve elemanlarýmýzý oraya atadýk.
    int toplam = 0;   //Dizinin elemanlarýnýn toplamýný atayacaðýmýz bir deðiþken atadýk.
    printf("Dizi elemanlarini girin:\n");
    for (i = 0; i < n; i++) {   //Girilen elemanlarýn toplamýný bulan döngü.
        scanf("%d", &set[i]);
        if(set[i]<0){
        	printf("NEGATIF BIR SAYI GIRILEMEZ");
        	return 0;
		}
        toplam += set[i];
    }
    
    if (toplam % 2 == 0 && altkumeToplam(set, n, toplam/2))   //Toplamlarý eþit olacaðý için ikiye bölünmeli ve altkumeToplam fonksiyonu saðlanmalý.
        printf("DIZI IKI ALT KUMESINE BOLUNEBILIR\n");
    else                                                      //Yukarýdaki koþul saðlanmýyorsa bölünemez.
        printf("DIZI IKI ALT KUMESINE BOLUNEMEZ\n");
    return 0;
}
