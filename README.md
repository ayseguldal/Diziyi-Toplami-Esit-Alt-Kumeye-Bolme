# Diziyi-Toplami-Esit-Alt-Kumeye-Bolme
Girilen dizinin toplamları eşit olacak şekilde alt kümeye bölünüp bölünemeyeceğini bulur.
#PROJENİN AMACI
 Sadece pozitif tamsayılar içeren boş olmayan bir tamsayı dizisi verildiğinde,dizinin her iki alt kümedeki elemanların toplamı eşit olacak şekilde iki alt kümeye 
 bölünüp bölünemeyeceğini bulur.
 Program önce kullanıcıdan elemanları alarak bir dizi oluşturur.
 Eğer bu dizinin elemanları negatif ise program çalışmaz hata verir ve ekrana "DIZI IKI ALT KUMESINE BOLUNEMEZ" yazdırır. 
 Önce bu elemanların toplamının çift sayı olup olmadığını kontrol eder.Eğer tekse program çalışmaz ve ekrana "DIZI IKI ALT KUMESINE BOLUNEMEZ" yazdırır. 
 Çünkü alt kümelerin toplamı eşit olacağı için dizinin elemanlarının toplamı çift olmalıdır.
 Eğer toplam çift ise program, dizi elemanlarının toplamının yarısına eşit bir toplama sahip iki alt küme oluşturulup oluşturulamayacağını belirlemek için 
 "altkumeToplami" adlı bir fonksiyon kullanır. 
 Bu fonksiyon oluşan alt kümeleri değerlendirir. Eğer bu koşulları sağlayan bir alt küme varsa recursive olarak bunu döndürür.
 
 
 # KOD NASIL KULLANILIR?
 Kodun çalışması için öncelikle kullanıcıdan eleman sayısı girilir.
Daha sonra kullanıcıdan sırayla elemanların girilmesi istenir ve sırasıyla işlemler uygulanır.

Eğer şartlara uymazsa gerekli hatalar verilerek program sonlanır.Örneğin dizinin elemanları toplamı tek olması,girilen elemanların negatif bir sayı olması ve alt
kümeye bölünememesi durumunda.
 
 # KOD TEST ETME...
 
 ÖRNEK:
 Dizinin Boyutunu Girininiz: 4
 
 Dizinin Elemanlarini Giriniz: 5 7 1 4

DIZI TOPLAMI ESİT IKI ALT KUMESINE BOLUNEMEZ

Bu örnekte kullanıcı tarafından 4 elemanlı bir dizi oluşturuluyor. Dizinin toplamı eşit alt kümeye bölünüp bölünemeyeceği kontrol edildi ve toplamları tek sayı
olduğu için "DIZI TOPLAMI ESİT IKI ALT KUMESINE BOLUNEMEZ" yanıtını verdi ve program sonlandı.

Farklı örnek ve elemanla daha fazla test yapılabilir.
