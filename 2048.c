#include <stdio.h>
#include <stdlib.h> //system cls ve exit 0 i�in gerekli k�t�phane
#include <time.h> //random say� i�in gerekli k�t�phane
#include <locale.h> //t�rk�e karakter i�in gerekli k�t�phane
#include <conio.h> //getch i�in gerekli k�t�phane
#include <unistd.h> //usleep i�in gerekli k�t�phane

#define PR 16 //y�klenme �ubu�u ve 2048 yaz�s�ndaki �ekil i�in ascii kodu

int oyunAlani[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; //oyun ekran�nda g�r�nen matris
int yedek[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; //bir �nceki hamleyi g�stermek i�in yapt���m�z yedek matris
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
	remove("kayitlar.txt"); //bir �nceki oyundan kalan kay�tlar� silmek i�in gerekli kod
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
    char s[]="OYUNUMUZA HO� GELD�N�Z";
    char s1[]="Y�KLEN�YOR...";

    char t[]="EME�� GE�ENLER:";
    char t1[]="��imi DEM�RA�";
    char t2[]="Atakan KAPLAN";
    char t3[]="Selin Cansu AKBA�";
    
    char m[]="OYUN TANITIMI";
    char m1[]="Hareket ettirmek i�in W, A, S, D tu�lar�n� kullan�n�z.";
    char m2[]="Bir �nceki hamlenizi g�rmek i�in U tu�una bas�n�z.";
    char m3[]="Oyunu tekrar ba�latmak i�in R tu�una bas�n�z.";
    char m4[]="Oyundan ��kmak i�in Q tu�una bas�n�z.";
    char m5[]="Oyuna ba�lamak i�in herhangi bir tu�a bas�n�z. �yi e�lenceler :)";

    system("color 09");
    printf("\n\n\n\n\n\n\n\t\t\t\t");
    yazdir(s);
    sleep(3);
    system("color 08");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t");
    yazdir(s1);
    printf("\n\n\n\t\t\t\t");
    for(i=0;i<30;i++) //y�klenme �ubu�u
    {
        printf("%c",PR);
        if(i%2!=0 && i<6){ //y�klenme �ubu�unun ekranda belirme s�resi
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
{ //string dizisinin karakterlerini ekrana tek tek bast�rmay� sa�layan fonksiyon
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
{ //s�f�rlar� sayan saya�
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
{ //s�f�r bulunmayan yerlerden rastgele bir yere say� koyan fonksiyon
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
{ //oyunun aray�z�
	int i,j;
	setlocale(LC_ALL,"Turkish");
	system("cls");
	system("color F");
	printf("\n\t\t\t\t\t~~~~~~~~~~~~~~2048~~~~~~~~~~~~~~\n");
	printf("\t\t\t\t\tBir �nceki hamle: U\t\t\t\t\t\n");
    printf("\t\t\t\t\tYeniden ba�latma: R\t\t\t\t\t\n");
    printf("\t\t\t\t\t��k��: Q\t\t\t\t\t\n\n");
    printf("\t\t\t\t\tYukar�: W\t A�a��: S\n\t\t\t\t\t");
    printf("Sa�: A \t\t Sol: D\n\n");
    printf("\t\t\t\t\tPuan�n: %d\n\t\t\t\t\t",puan);
	printf("En Y�ksek Puan: %d\t\t\t\t\t\n",maxpuan);
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
{ //bir �nceki hamleyi g�stermek i�in ana matrisi yedekledi�imiz fonksiyon
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			yedek[i][j]=oyunAlani[i][j];
		}
	}
}

void once()
{ //bir �nceki hamleyi ekrana bast�rmak i�in fonskiyon
	int i,j;
	
	printf("\n\n\t\t\t\t\t");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf(" %4d ",yedek[i][j]);
		}
		printf("\n\n\t\t\t\t\t");
	}
	printf("\n\t\t\t\t\tDevam etmek i�in herhangi bir tu�a bas�n�z!");
}

void donme(int donusSayisi)
{ //oyun alan�n�n saat y�n�n�n tersine d�nmesini sa�layan fonksiyon
	int i,yedek=0;
	for(i=0;i<donusSayisi;i++){
		//k��eler
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
{/*Sola hareketi sa�lamak i�in olan bu fonksiyonda 'l' integer�n�n bulundu�u for d�ng�leri kayd�r�lan sat�rlar�n d�zg�n bir �ekilde tamamen sola dayat�lmas�n� sa�lar.
�rne�in; 0-4-4-0-4 �eklinde olan bir sat�r� sola dayama i�leminde l=0 i�in 4-0-4-4-0, l=1 i�in 4-4-0-4-0, L=2 i�in 4-4-4-0-0 �eklinde olur.
D�zg�n �al��abilmesi i�in, toplamda 3 defa sol taraf ile kontrol edip yer de�i�tirme i�lemi uygulamam�z gerekmektedir.
Bizim 5 s�tunumuz oldu�undan maksimum 5 kontrolde d�zg�n bir �ekilde sola dayama yap�labilmektedir.*/
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
		
	if(puan>=maxpuan) //maxpuan kontrol� yapan kod
		maxpuan=puan;
		
	kazandi();
	
	if(devam==0)
		kaybetti();
}

void kaybetti()
{ //kaybetme ekran�
	char s[]="~~~~~~~~~~~~~~OYUNU KAYBETT�N�Z!~~~~~~~~~~~~~~";
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
{ //kazanma ekran�
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
{ //tekrar oynamak isteyip istemedi�inin soruldu�u biti� ekran�
	char s[]="Oyunumuzu oynad���n�z i�in te�ekk�r ederiz! �yi g�nler~";
	char secim;
    printf("\n\n\t\t\t\t\tBir ele daha ne dersiniz? (E ya da H se�iniz!)\n\t\t\t\t\t");
    secim=getch();
    
    while(secim!= 'h' && secim!= 'H' && secim!= 'e' && secim!= 'E'){
    	printf("\n\n\t\t\t\t\tL�tfen E ya da H se�iniz!\n\n\t\t\t\t\t");
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
{ //oyun alan�n�n s�f�rlanmas� sa�lar
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
{ //ger�ekten ��kmak isteyip istemedi�inin sorguland��� ekran
	char s[]="��kmak istedi�inize emin misiniz? Eminseniz E'ye bas�n�z.";
	char s1[]="De�ilseniz herhangi bir tu�a bas�n�z.";
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
{ //oyuncu bilgilerinin tutulmas� i�in dosyalama i�lemi yapan fonksiyon
	char isim[20],harf,h;
	char s[]="�nceki puanlar�n�z� g�rmek ister misiniz? G�rmek i�in 'E' harfine bas�n�z.";
	char s1[]="Direkt devam etmek i�in herhangi bir tu�a bas�n�z.";
	char i[]="Ad�n�z� giriniz: ";
	
	system("color B");
	yazdir(i);
	scanf("%s",isim);
	system("cls");
	FILE *bilgi;
	bilgi=fopen("kayitlar.txt","a"); //kay�t dosyas�n� a�an kod
	fprintf(bilgi,"Oyuncunun ad�: %s\n",isim);
	fprintf(bilgi,"Puan�n�z: %d\n\n",puan);
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
		do{ //kay�t dosyas�nda bulunan bilgileri ekrana yazd�ran kod
		putchar(fgetc(bilgi));
		} while (!feof(bilgi));
		printf("\b \b"); //ekranda istemsizce beliren y harfini ortadan kald�rmak i�in gerekli kod
		fclose(bilgi);
	}
}
