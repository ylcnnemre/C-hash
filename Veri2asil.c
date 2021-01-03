#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
int musteri_no;
char ad[20], soyad[20];
} Musteri;


int main()
{
	
	
	while(1)
	{
		FILE *dosya=fopen("datalar.txt","r");
	int musteri_no;
	char ad[20];
	char soyad[20];
	Musteri *veri_liste[10];
	
	int hash_tablo[10][2];
		int i=0;
	int k=0;
	int input;
	printf("\n eklemek icin 1 e basiniz \n");
	printf(" aramak icin 2 ye basiniz \n");
	printf(" silmek icin 3 e basiniz \n");
	printf(" hash tablosunu yazdirmak icin 4 e basiniz \n");
	printf("listeyi yazdirmak icin 5 e tiklayiniz \n");
	scanf("%d",&input);
		
		
		
		switch(input)
	{
		case 1 :
	
	
	for(i;i<10;i++)
	{
		for(k;k<2;k++)
		{
			hash_tablo[i][k]=-1;
			
		}
		k=0;
	}
	int r=0;
	for(r;r<10;r++)
	{
		veri_liste[r]=(Musteri*)malloc(sizeof(Musteri));
	}
	
	if(dosya==NULL)
	{
		printf("txt dosyasý bulunamadý");
	}
	else{
		int i=0;
		for(i;i<10;i++)
		{
			fscanf(dosya,"%d",&musteri_no);
			fscanf(dosya,"%s",&ad);
			fscanf(dosya,"%s",&soyad);
			int hash_indeks=musteri_no%10;
			
			if(hash_tablo[hash_indeks][0]==-1)
			{
			hash_tablo[hash_indeks][0]=musteri_no;
			veri_liste[hash_indeks] = (Musteri*)malloc(sizeof(Musteri));
			veri_liste[hash_indeks]->musteri_no=musteri_no;
			strcpy(veri_liste[hash_indeks]->ad,ad);
			strcpy(veri_liste[hash_indeks]->soyad,soyad);	
			}
			else{
				int k=0;
				for(k;k<10;k++)
				{
					if(hash_tablo[k][0]==-1)
					{
						hash_tablo[k][0]=musteri_no;
						veri_liste[k]=(Musteri*)malloc(sizeof(Musteri));
						veri_liste[k]->musteri_no=musteri_no;
						strcpy(veri_liste[k]->ad,ad);
						strcpy(veri_liste[k]->soyad,soyad);	
						
						if(hash_tablo[hash_indeks][1]==-1)
						{
							hash_tablo[hash_indeks][1]=k;
						}
						else
						{
							int deger=hash_tablo[hash_indeks][1];
							
							hash_tablo[deger][1]=k;
							
						}
						break;
					}
					
				}
			}
		}
		
		int sayac=0;
	
		printf("ekleme islemi tamamlandi \n");
		
	}
	
		int musteri_numarasi;
		int adim=0;
		int kontrol=0;
		break;
		case 2 :
			
				
				printf("musteri numarasi giriniz \n");		
				scanf("%d",&musteri_numarasi);
				int hash_index=musteri_numarasi%10;
				int iter=0;
					int next=hash_tablo[hash_index][1];
				for(iter=0;i<10;i++)
				{
					if(hash_tablo[hash_index][0]==musteri_numarasi)
					{
						adim++;
						printf("aranilan deger %d \n",musteri_numarasi);
						printf("%d %s %s \n",veri_liste[hash_index]->musteri_no,veri_liste[hash_index]->ad,veri_liste[hash_index]->soyad);
						printf("%d adimda bulundu ",adim);
						break;
					}
					
					else{
						adim++;
						while(1)
						{
							
							if(hash_tablo[next][0]==musteri_numarasi)
							{
									kontrol=1;
									
									printf("aranilan deger %d \n",musteri_numarasi);
									printf("%d %s %s \n",veri_liste[next]->musteri_no,veri_liste[next]->ad,veri_liste[next]->soyad);
									printf("%d adimda bulundu \n",adim);
									break;
							}
							else if(hash_tablo[next][0]!=musteri_numarasi&&hash_tablo[next][1]==-1)
							{
								kontrol=1;
								printf("aradiginiz deger bulunamadi");
								break;
							}
							else{
								next= hash_tablo[next][1];
								adim++;
							}
							
						}
						if(kontrol==1)
						{
							break;
						}
					}
				}
			int index=0;	
			int silinecek_numara=0;
			break;
		case 3:
			
		    
		    printf("silincek numarayý giriniz \n");
		    scanf("%d",&silinecek_numara);
		    for(index;index<10;index++)
		    {
		    	if(hash_tablo[index][0]==silinecek_numara)
		    	 {
		    	 	hash_tablo[index][0]=-1;
		    	 	
		    	 	veri_liste[index]=NULL;
		    	 	printf("silme iþlemi tamamlandi \n");
		    	 	break;
				 }
			}
			int x=0;
		int m=0;	
		break;
		case 4 :
			
		for(x=0;x<10;x++)
		{
			for( m=0;m<2;m++)
			{
				printf("%d ",hash_tablo[x][m]);
			}
			printf("\n");
		}
		break;
		int indeks=0;
		case 5 :
		   	for(indeks;indeks<10;indeks++)
		   	{
		   		printf("%d %s %s \n",veri_liste[indeks]->musteri_no,veri_liste[indeks]->ad,veri_liste[indeks]->soyad );
			}
			   break;
	}	
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	

	
	
	
	
}
