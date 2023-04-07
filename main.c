//1220505011 AYŞE GÜL DAL 
//DİZİYİ TOPLAMI EŞİT ALT KÜMEYE BÖLME 

#include <stdio.h>
#include <math.h>

   //ALT KÜME OLUŞTURMA FONKSİYONU 
int altkumeToplam(int arr[], int n, int sum)     //n:dizinin boyutu, sum:elemanları toplamı.
{
    int altkume[n+1][sum+1];       // Alt küme toplamlarını saklamak için bir bool dizisi oluşturulur.
   int i,j;
    for (i = 0; i <= n; i++)  //Alt kümenin birinci sütunu girilen diznin boyutu kadar 1 ile dolduruluyor.
        altkume[i][0] = 1;            
        
    for (i = 1; i <= sum; i++)     //Alt kümenin birinci satırı gönderilen toplam kadar 1 ile dolduruluyor. 
        altkume[0][i] = 0;
   
   
                   // Toplamı tam olarak i'ye eşitlemek için alt kümeler bulunur.
    for (i = 1; i <= n; i++) {       //Oluşturulan alt kümenin elemanlarını dolaşır.
        for (j = 1; j <= sum; j++) {
            if (j < arr[i-1])            //Koşul sağlanıyorsa aşağıdaki işlemleri uygular.
                altkume[i][j] = altkume[i-1][j];         // Bu eleman alt kümeye dahil edilebilir mi?
            if (j >= arr[i-1])           //Koşul sağlanıyorsa aşağıdaki işlemleri uygular.
              altkume[i][j] = altkume[i-1][j] || altkume[i - 1][j-arr[i-1]];   //Altkümelerden en az birisinin sağlaması yeterlidir.
        }
    }
            // "toplam" değerine eşit iki alt küme var mı?
    return altkume[n][sum];       //Oluşan alt kümeyi döndürür.
}

int main()
{
    int n;   //Dizinin eleman sayısını tanımladık.
    int i;
    printf("Dizi eleman sayisini girin: ");   //Ekrana yazdırma.
    scanf("%d", &n);  //Dizinin eleman sayısını kullanıcıdan aldık.
    int set[n];   //set adında dizi tanımladık ve elemanlarımızı oraya atadık.
    int toplam = 0;   //Dizinin elemanlarının toplamını atayacağımız bir değişken atadık.
    printf("Dizi elemanlarini girin:\n");
    for (i = 0; i < n; i++) {   //Girilen elemanların toplamını bulan döngü.
        scanf("%d", &set[i]);
        if(set[i]<0){
        	printf("NEGATIF BIR SAYI GIRILEMEZ");
        	return 0;
		}
        toplam += set[i];
    }
    
    if (toplam % 2 == 0 && altkumeToplam(set, n, toplam/2))   //Toplamları eşit olacağı için ikiye bölünmeli ve altkumeToplam fonksiyonu sağlanmalı.
        printf("DIZI IKI ALT KUMESINE BOLUNEBILIR\n");
    else                                                      //Yukarıdaki koşul sağlanmıyorsa bölünemez.
        printf("DIZI IKI ALT KUMESINE BOLUNEMEZ\n");
    return 0;
}
