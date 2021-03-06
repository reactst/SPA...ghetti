#include <stdio.h>
#include <malloc.h>
//int* podniz(int *niz, int start, int stop) – vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop. 
int* podniz (int* niz, int start, int stop) {
    int razlika=stop-start;
    int* newarray=(int*)malloc(sizeof(int)*razlika);
    for (int i=0;i<razlika;i++){
        newarray[i]=niz[start];
        start++;
        printf ("%d[%d] newarray\n",newarray[i],i);
    }
    return newarray;
}
/*
int* filtriraj(int *niz, int n, int th, int *nth) – vraća novi niz 
koji sadrži brojeve iz originalnog niza koji su manji od th. 
Originalni niz ima dužinu n. 
Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 
*/
int* filtriraj(int *niz, int n, int th, int *nth) {
    *nth=0;
    int* noviniz;
    for (int i=0;i<=n;i++){
        if (niz[i]<th)
        (*nth)++;
    }
    noviniz=(int*)malloc(sizeof(int)*(*nth));
    int nnbrojac=0;
    for (int i=0;i<n;i++){
        if (niz[i]<th){
            noviniz[nnbrojac]=niz[i];
            nnbrojac++;
        }
    }
    return noviniz;
}
/* 
int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela
 i stvara kopije prvog i drugog dijela. 
Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.
*/
int** podijeli(int *niz, int n){
    if (n==0){
		return NULL;
	}
    int len1,len2;
    if (n%2==0){
	    len1=n/2;
	    len2=n/2;
	}else{
	    len1=n/2;
	    len2=n-(n/2);
	}
    int **returner=((int**)malloc(sizeof(int*)*2));
    int *prviniz=((int*)malloc(sizeof(int)*(len1)));
    int *druginiz=((int*)malloc(sizeof(int)*(len2)));
    for (int i=0;i<len1;i++){
        prviniz[i]=niz[i];
    }
    for (int i=len1;i<n;i++){
        druginiz[i-len2]=niz[i];
    }
    returner[0]=prviniz;
    returner[1]=druginiz;
    return returner;
}
/*
Deklarirati strukturu Tocka koja sadrži dva člana:
 x i y (oba su float). Deklarirati strukturu Poligon 
 koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i broj vrhova n. 
Napisati funkcije za rad sa poligonima 
*/
typedef struct {
    float x,y;
}Tocka;
typedef struct {
    unsigned int n;
    Tocka *niz_t;
}Poligon;
/* 
Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – 
prima niz x i y koordinata i stvara
novi poligon koji će kao vrhove imati parove brojeva iz nizova. 
Nizovi su dužine n (≥ 3).
*/
Poligon* novi_poligon(float *niz_x, float *niz_y, unsigned int n){
    Poligon *poly=((Poligon*)malloc(sizeof(Poligon)));
    Tocka *niz_tck=((Tocka*)malloc(sizeof(Tocka)*n));
    poly->n = n;
	poly->niz_t = niz_tck;
	for (int i = 0; i < n; i++){
		niz_tck[i].x = niz_x[i];
		niz_tck[i].y = niz_y[i];
	}
	return poly;
}
/*
Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača
 na vrhove poligona kojima su obje koordinate pozitivne. 
Broj elemenata u nizu će biti spremljen u np parametar.
*/
Tocka** pozitivni(Poligon *p, int *np){
	Poligon* poly2 = p;
	Tocka* tockica = p->niz_t;
    int temp=0;
	int len = p->n;
	for (int i=0;i<len;i++)
	{
		if (tockica[i].x>0 && tockica[i].y>0)	{
			temp++;
		}
	}
	(*np)=temp;
	Tocka** pozitivnibr=(Tocka**)malloc(temp*sizeof(Tocka*));
	int k=0;
	for (int i=0;i<len;i++)	{
		if (tockica[i].x>0 && tockica[i].y>0)	{
			pozitivnibr[k]=poly2->niz_t;
			k++;
		}
		poly2->niz_t++;
	}
	return pozitivnibr;
}
void main (){
    int niz[]={1,3,15,4,25,6,99,8,9,11,12,10};
    int nizlen=sizeof(niz)/sizeof(niz[0]);
    int th=10;
    int nth;
    int start=3, stop=8;
    int lenn=stop-start;
    int* nn=podniz(niz,start,stop);
    float nizx[]={2.231,1.324,2.123,4.223};
    float nizy[]={-1.521,-2.352,2.241,1.251};
    int n=sizeof(nizx)/sizeof(nizx[0]);
    int np;
    int* nnn=filtriraj(niz,nizlen,th,&nth);
    int** nnnn=podijeli(niz,nizlen);
    Poligon* npoly=novi_poligon(nizx,nizy,n);
    Tocka *tp = npoly->niz_t;
    Tocka** pozitivci = pozitivni(npoly, &np);
    for (int i=0;i<lenn;i++){
        printf ("nn[i]\t%d[%d]\n",nn[i],i);
    }
    printf ("\n");
    for (int i=0;i<nth;i++){
        printf ("nnn[i]\t%d[%d]\n",nnn[i],i);
    }
    printf ("\n");
    for (int i=0;i<nizlen/2;i++){
        printf ("nnnn[0][i] %d[%d]\n",nnnn[0][i],i);
        printf ("nnnn[1][i] %d[%d]\n",nnnn[1][i],i);
    }
    printf ("\n");
    for (int i=0;i<n;i++){
			printf("x=%.2f\ty=%.2f\n",tp[i].x,tp[i].y);
		}
    printf ("\n");
    printf("Pozitivne tocke su:\n");
	for (int i=0;i<np;i++){
			printf("x=%.2f\ty=%.2f\n",pozitivci[i][0].x,pozitivci[i][0].y);
		}
    //FREE SECTION
    free (nnnn);
    free(nnnn[0]);
    free(nnnn[1]);
    free(nn);
    free(nnn);
    free(npoly);
    free(tp);
    free(pozitivci);
}
//GOTOVO