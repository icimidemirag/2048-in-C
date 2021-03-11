#include <stdio.h>
#include <stdlib.h> //system cls ve exit 0 için gerekli kütüphane
#include <time.h> //random sayý için gerekli kütüphane
#include <locale.h> //türkçe karakter için gerekli kütüphane
#include <conio.h> //getch için gerekli kütüphane
#include <unistd.h> //usleep için gerekli kütüphane

#define PR 16 //yüklenme çubuðu ve 2048 yazýsýndaki þekil için ascii kodu

int oyunAlani[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; //oyun ekranýnda görünen matris
int yedek[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; //bir önceki hamleyi göstermek için yaptýðýmýz yedek matris
int puan=0, maxpuan=0, syc=0;

void baslama();
void yazdir(char s[]);
void giris();
void sayac();
void ekleSayi();
void ekran();
void onceki();
void once();
void donme(int);
void hareket();
void kaybetti();
void kazandi();
void bitti();
void sifirla();
void cikis();
void kayit();

void main()
{
	setlocale(LC_ALL,"Turkish");
	char yonler;
	remove("kayitlar.txt"); //bir önceki oyundan kalan kayýtlarý silmek için gerekli kod
    baslama();
	ekleSayi();
	ekleSayi();
	ekran();
	while(1){
		yonler=getch();
		if(yonler=='W' || yonler=='w'){
			onceki();
			donme(1);
			hareket();
			ekleSayi();
			ekleSayi();
			donme(3);
			ekran();
		}
		
		else if(yonler=='A' || yonler=='a'){
			onceki();
			hareket();
			ekleSayi();
			ekleSayi();
			ekran();		
		}
		
		else if(yonler=='S'|| yonler=='s'){
			onceki();
			donme(3);
			hareket();
			ekleSayi();
			ekleSayi();
			donme(1);
			ekran();
		}
		
		else if(yonler=='D'|| yonler=='d'){
			onceki();
			donme(2);
			hareket();
			ekleSayi();
			ekleSayi();
			donme(2);
			ekran();
		}
		
		else if(yonler=='R' || yonler=='r'){
			sifirla();
			onceki();
			ekleSayi();
			ekleSayi();
			ekran();
		}
		
		else if(yonler=='Q' || yonler=='q'){
			system("cls");
			cikis();
		}
		
		else if(yonler=='U' || yonler=='u'){
			once();
			getch();
			system("cls");
			ekran();
		}
		
		else{
			printf("\a");
		}
	}
}

void baslama()
{
    int i;
    char s[]="OYUNUMUZA HOÞ GELDÝNÝZ";
    char s1[]="YÜKLENÝYOR...";

    char t[]="EMEÐÝ GEÇENLER:";
    char t1[]="Ýçimi DEMÝRAÐ";
    char t2[]="Atakan KAPLAN";
    char t3[]="Selin Cansu AKBAÞ";
    
    char m[]="OYUN TANITIMI";
    char m1[]="Hareket ettirmek için W, A, S, D tuþlarýný kullanýnýz.";
    char m2[]="Bir önceki hamlenizi görmek için U tuþuna basýnýz.";
    char m3[]="Oyunu tekrar baþlatmak için R tuþuna basýnýz.";
    char m4[]="Oyundan çýkmak için Q tuþuna basýnýz.";
    char m5[]="Oyuna baþlamak için herhangi bir tuþa basýnýz. Ýyi eðlenceler :)";

    system("color 09");
    printf("\n\n\n\n\n\n\n\t\t\t\t");
    yazdir(s);
    sleep(3);
    system("color 08");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t");
    yazdir(s1);
    printf("\n\n\n\t\t\t\t");
    for(i=0;i<30;i++) //yüklenme çubuðu
    {
        printf("%c",PR);
        if(i%2!=0 && i<6){ //yüklenme çubuðunun ekranda belirme süresi
            sleep(1);
        }
	}
    sleep(3);
    
    giris();
    system("cls");
    
    system("color e");
    printf("\n\n\t\t\t\t\t");
    yazdir(t);
    usleep(20000);
    printf("\n\n\n\n\t");
    yazdir(t1);
    printf("\n\n\t");
    yazdir(t2);
    printf("\n\n\t");
    yazdir(t3);
    printf("\n\n\t");
    sleep(3);
    
    system("cls");
    system("color C");
    printf("\n\n\t\t\t\t\t");
    yazdir(m);
    usleep(20000);
    printf("\n\n\n\n\t");
    yazdir(m1);
    printf("\n\n\t");
    yazdir(m2);
    printf("\n\n\t");
    yazdir(m3);
    printf("\n\n\t");
    yazdir(m4);
    printf("\n\n\n\n\n\n\t");
    yazdir(m5);
	printf("\n\n\t");
    getch();
}

void yazdir(char s[])
{ //string dizisinin karakterlerini ekrana tek tek bastýrmayý saðlayan fonksiyon
    int i=0;
    while(s[i]!='\0'){
        printf("%c",s[i]);
		usleep(20000);
        i++;
    }
}

void giris()
{
	int i=1;
    system("cls");
    system("color F");
    printf("\n\n\n\n\n\n\t\t   %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         ",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);
    printf("\t\t\t\t\t\t\t     %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
    printf("\t\t\t\t\t\t\t     %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
    printf("\t\t\t\t\t\t\t     %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
    printf("\t\t\t\t\t\t\t     %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
    printf("\t\t\t\t\t\t   %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);
	printf("\t\t\t\t\t\t   %c",PR);usleep(20000);printf("                     %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t           %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
	printf("\t\t\t\t\t\t   %c",PR);usleep(20000);printf("                     %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t           %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
	printf("\t\t\t\t\t\t   %c",PR);usleep(20000);printf("                     %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t           %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
	printf("\t\t\t\t\t\t   %c",PR);usleep(20000);printf("                     %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);printf("\t\t           %c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("         %c",PR);usleep(20000);
	printf("\t\t\t\t\t\t   %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t  ",PR);usleep(20000);printf("         ",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("\t\t %c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);printf("%c",PR);usleep(20000);
	
    usleep(20000);
    while(i<3)
    {
        system("color 9");
        usleep(20000);
        system("color 1");
        usleep(20000);
        system("color 9");
        usleep(20000);
        system("color A");
        usleep(20000);
        system("color 2");
        usleep(20000);
        system("color A");
        usleep(20000);
        system("color B");
        usleep(20000);
        system("color 3");
        usleep(20000);
        system("color B");
        usleep(20000);
        system("color C");
        usleep(20000);
        system("color 4");
        usleep(20000);
        system("color C");
        usleep(20000);
        system("color D");
        usleep(20000);
        system("color 5");
        usleep(20000);
        system("color D");
        usleep(20000);
        system("color E");
        usleep(20000);
        system("color 6");
        usleep(20000);
        system("color E");
        usleep(20000);
        system("color F");
        i++;
    }
}

void sayac()
{ //sýfýrlarý sayan sayaç
	int i,j;
	syc=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(oyunAlani[i][j]==0){
				syc++;
			}	
		}
	}
}

void ekleSayi()
{ //sýfýr bulunmayan yerlerden rastgele bir yere sayý koyan fonksiyon
	int i,j;
	srand(time(NULL));
	sayac();
	if(syc!=0){
		while(1){
			i=rand()%5;
			j=rand()%5;
 			if(oyunAlani[i][j]==0){
 				oyunAlani[i][j]=2;
 				break;
 				}
		}	
	}
}

void ekran()
{ //oyunun arayüzü
	int i,j;
	setlocale(LC_ALL,"Turkish");
	system("cls");
	system("color F");
	printf("\n\t\t\t\t\t~~~~~~~~~~~~~~2048~~~~~~~~~~~~~~\n");
	printf("\t\t\t\t\tBir önceki hamle: U\t\t\t\t\t\n");
    printf("\t\t\t\t\tYeniden baþlatma: R\t\t\t\t\t\n");
    printf("\t\t\t\t\tÇýkýþ: Q\t\t\t\t\t\n\n");
    printf("\t\t\t\t\tYukarý: W\t Aþaðý: S\n\t\t\t\t\t");
    printf("Sað: A \t\t Sol: D\n\n");
    printf("\t\t\t\t\tPuanýn: %d\n\t\t\t\t\t",puan);
	printf("En Yüksek Puan: %d\t\t\t\t\t\n",maxpuan);
    printf("\t\t\t\t\t---------------------------------\n");
    printf("\n\n\t\t\t\t\t");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf(" %4d ",oyunAlani[i][j]);
		}
		printf("\n\n\t\t\t\t\t");
	}
    printf("\n\t\t\t\t\t---------------------------------\n");
}

void onceki()
{ //bir önceki hamleyi göstermek için ana matrisi yedeklediðimiz fonksiyon
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			yedek[i][j]=oyunAlani[i][j];
		}
	}
}

void once()
{ //bir önceki hamleyi ekrana bastýrmak için fonskiyon
	int i,j;
	
	printf("\n\n\t\t\t\t\t");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf(" %4d ",yedek[i][j]);
		}
		printf("\n\n\t\t\t\t\t");
	}
	printf("\n\t\t\t\t\tDevam etmek için herhangi bir tuþa basýnýz!");
}

void donme(int donusSayisi)
{ //oyun alanýnýn saat yönünün tersine dönmesini saðlayan fonksiyon
	int i,yedek=0;
	for(i=0;i<donusSayisi;i++){
		//köþeler
		yedek=oyunAlani[0][0];
		oyunAlani[0][0]=oyunAlani[0][4];
		oyunAlani[0][4]=oyunAlani[4][4];
		oyunAlani[4][4]=oyunAlani[4][0];
		oyunAlani[4][0]=yedek;
		yedek=0;
		//kenar1
		yedek=oyunAlani[0][1];
		oyunAlani[0][1]=oyunAlani[1][4];
		oyunAlani[1][4]=oyunAlani[4][3];
		oyunAlani[4][3]=oyunAlani[3][0];
		oyunAlani[3][0]=yedek;
		yedek=0;
		//kenar2
		yedek=oyunAlani[0][2];
		oyunAlani[0][2]=oyunAlani[2][4];
		oyunAlani[2][4]=oyunAlani[4][2];
		oyunAlani[4][2]=oyunAlani[2][0];
		oyunAlani[2][0]=yedek;
		yedek=0;
		//kenar3
		yedek=oyunAlani[0][3];
		oyunAlani[0][3]=oyunAlani[3][4];
		oyunAlani[3][4]=oyunAlani[4][1];
		oyunAlani[4][1]=oyunAlani[1][0];
		oyunAlani[1][0]=yedek;
		yedek=0;
		//orta1
		yedek=oyunAlani[1][3];
		oyunAlani[1][3]=oyunAlani[3][3];
		oyunAlani[3][3]=oyunAlani[3][1];
		oyunAlani[3][1]=oyunAlani[1][1];
		oyunAlani[1][1]=yedek;
		yedek=0;
		//orta2
		yedek=oyunAlani[1][2];
		oyunAlani[1][2]=oyunAlani[2][3];
		oyunAlani[2][3]=oyunAlani[3][2];
		oyunAlani[3][2]=oyunAlani[2][1];
		oyunAlani[2][1]=yedek;
		yedek=0;	
	}
}

void hareket() 
{/*Sola hareketi saðlamak için olan bu fonksiyonda 'l' integerýnýn bulunduðu for döngüleri kaydýrýlan satýrlarýn düzgün bir þekilde tamamen sola dayatýlmasýný saðlar.
örneðin; 0-4-4-0-4 þeklinde olan bir satýrý sola dayama iþleminde l=0 için 4-0-4-4-0, l=1 için 4-4-0-4-0, L=2 için 4-4-4-0-0 þeklinde olur.
Düzgün çalýþabilmesi için, toplamda 3 defa sol taraf ile kontrol edip yer deðiþtirme iþlemi uygulamamýz gerekmektedir.
Bizim 5 sütunumuz olduðundan maksimum 5 kontrolde düzgün bir þekilde sola dayama yapýlabilmektedir.*/
	int i,j,L,devam=0;
	for(i=0;i<5;i++){
		
		for(L=0;L<5;L++){
			for(j=4;0<j;j--){
				if(oyunAlani[i][j-1]==0){
					oyunAlani[i][j-1]=oyunAlani[i][j];
					oyunAlani[i][j]=0;
					devam+=1;
				}
			}
		}

		
		for(j=1;j<5;j++){
			if(oyunAlani[i][j]==oyunAlani[i][j-1]){
				oyunAlani[i][j-1]=oyunAlani[i][j]*2;
				oyunAlani[i][j]=0;
				devam+=1;
				puan+=oyunAlani[i][j-1];
			}
		}
		
		for(L=0;L<5;L++){
			for(j=4;0<j;j--){
				if(oyunAlani[i][j-1]==0){
					oyunAlani[i][j-1]=oyunAlani[i][j];
					oyunAlani[i][j]=0;
					devam+=1;
				}
			}
		}
	}
	
	if(devam==0){
		donme(1);
		for(i=0;i<5;i++){
			
			for(j=5;0<j;j--){
				if(oyunAlani[i][j-1]==0)
					devam+=1;
			}
		
			for(j=1;j<5;j++){
				if(oyunAlani[i][j]==oyunAlani[i][j-1])
					devam+=1;
			}
		}
		donme(3);
	}
		
	if(puan>=maxpuan) //maxpuan kontrolü yapan kod
		maxpuan=puan;
		
	kazandi();
	
	if(devam==0)
		kaybetti();
}

void kaybetti()
{ //kaybetme ekraný
	char s[]="~~~~~~~~~~~~~~OYUNU KAYBETTÝNÝZ!~~~~~~~~~~~~~~";
	system("color C");
	system("cls");
	printf("\n\t\t\t\t\t");
    yazdir(s);
    printf("\n\n");
	sleep(2);
	kayit();
	bitti();
	sifirla();
	onceki();
}

void kazandi()
{ //kazanma ekraný
	char s[]="~~~~~~~~~~~~~~OYUNU KAZANDINIZ!~~~~~~~~~~~~~~";
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(oyunAlani[i][j]==2048){
				system("color A");
				system("cls");
				printf("\n\t\t\t\t\t");
			    yazdir(s);
			    printf("\n\n");
				sleep(2);
				kayit();
				bitti();
				sifirla();
				onceki();
			}	
		}
	}
}

void bitti()
{ //tekrar oynamak isteyip istemediðinin sorulduðu bitiþ ekraný
	char s[]="Oyunumuzu oynadýðýnýz için teþekkür ederiz! Ýyi günler~";
	char secim;
    printf("\n\n\t\t\t\t\tBir ele daha ne dersiniz? (E ya da H seçiniz!)\n\t\t\t\t\t");
    secim=getch();
    
    while(secim!= 'h' && secim!= 'H' && secim!= 'e' && secim!= 'E'){
    	printf("\n\n\t\t\t\t\tLütfen E ya da H seçiniz!\n\n\t\t\t\t\t");
    	secim=getch();
    }
    
	switch (secim){
    	case 'E':
       	case 'e':
			sifirla();
			ekran();
			break;
        case 'h':
       	case 'H':
       		system("cls");
       		system("color D");
       		printf("\n\n\t\t\t\t");
			yazdir(s);
			printf("\n\n");
       		exit(0);
	}	
}

void sifirla()
{ //oyun alanýnýn sýfýrlanmasý saðlar
    int i,j;
    for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			oyunAlani[i][j]=0;
		}
	}
	system("cls");
    puan=0;
}

void cikis()
{ //gerçekten çýkmak isteyip istemediðinin sorgulandýðý ekran
	char s[]="Çýkmak istediðinize emin misiniz? Eminseniz E'ye basýnýz.";
	char s1[]="Deðilseniz herhangi bir tuþa basýnýz.";
	char cik;
	system("color 6");
	printf("\n\n\t\t\t\t");
	yazdir(s);
	printf("\n\t\t\t\t");
	yazdir(s1);
	printf("\n\n");
	cik=getch();
	if(cik=='E' || cik=='e'){
		kayit();
		exit(0);
	}
	else{
		ekran();
	}
}

void kayit()
{ //oyuncu bilgilerinin tutulmasý için dosyalama iþlemi yapan fonksiyon
	char isim[20],harf,h;
	char s[]="Önceki puanlarýnýzý görmek ister misiniz? Görmek için 'E' harfine basýnýz.";
	char s1[]="Direkt devam etmek için herhangi bir tuþa basýnýz.";
	char i[]="Adýnýzý giriniz: ";
	
	system("color B");
	yazdir(i);
	scanf("%s",isim);
	system("cls");
	FILE *bilgi;
	bilgi=fopen("kayitlar.txt","a"); //kayýt dosyasýný açan kod
	fprintf(bilgi,"Oyuncunun adý: %s\n",isim);
	fprintf(bilgi,"Puanýnýz: %d\n\n",puan);
	fclose(bilgi);
	
	printf("\n\n\t");
	yazdir(s);
	printf("\n\t");
	yazdir(s1);
	printf("\n");
	harf=getch();
	system("cls");
	if(harf=='E' || harf=='e'){
		bilgi=fopen("kayitlar.txt","r");
		do{ //kayýt dosyasýnda bulunan bilgileri ekrana yazdýran kod
		putchar(fgetc(bilgi));
		} while (!feof(bilgi));
		printf("\b \b"); //ekranda istemsizce beliren y harfini ortadan kaldýrmak için gerekli kod
		fclose(bilgi);
	}
}
