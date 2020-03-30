#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int questao_n1();
int questao_n2();
int questao_n3();
int questao_n4();
void igualdade_AB(int x[], int y[],int index_x,int index_y);
bool subconj_AB(int x[], int y[],int index_x,int index_y);
bool sobrejetora(int x[], int y[],int index_x,int index_y);
bool bijetora(int x[], int y[],int index_x,int index_y);
bool injetora(int x[], int y[],int index_x,int index_y);
void cardinalidade(int index_x);
void produto_cartesiano(int x[], int y[],int index_x,int index_y);
int uniao(int x[], int y[],int index_x,int index_y);
int intersecao(int x[], int y[],int index_x,int index_y);
void diferenca(int x[], int y[],int index_x,int index_y);
void ordenacao_quicksort(int *a, int left, int right);
int transformador_caractere_para_inteiro(char strn_a[], int* cj_A);
void remover_elementos_duplicados(int *conj_x,int *indice);
void sort_m(int x[], int y[],int *uni,int index_x,int index_y);
void naturais_invertidos();
void progressao_aritmetica();
void elevador_potencia_quadrada();
void fibonacci();
int transformador_caractere_para_inteiro(char strn_a[], int *cj_A);
void somatorio_constante(int *conj_x,int index_x);
void somatoria_progressao_aritmetica(int *conj_x,int index_x);
void somatoria_elevado_quadrado(int *conj_x,int index_x);
void somatoria_elevado_cubo(int *conj_x,int index_x);
void somatoria_elevado_quatro(int *conj_x,int index_x);
void somatoria_elevado_cinco(int *conj_x,int index_x);
void somatoria_elevado_seis(int *conj_x,int index_x);

// Data:04/10/2019
// Autor:Matheus Fernandes Oliveira
// Ação: Resolução da lista de exercício número 1 de matemática discreta. Implementação em programação

int main()
{

    questao_n1();
    questao_n2();
    questao_n3();
    questao_n4();
	system ("pause");
    return 0;
}

int questao_n1()
{	
       FILE * arqCSV1 = fopen("anexo1.csv","r");
    char  str_a[12345], str_b[12345];
    int i,j,idA,idB,k,l;
    int setA[12345],setB[12345];

	if(arqCSV1 ==  NULL )
    {
        printf("Nao leu o arquivo\n");
        return 0;
    }

	fgets(str_a,12345,arqCSV1);
	fgets(str_b,12345,arqCSV1);
	fclose(arqCSV1);

    idA = transformador_caractere_para_inteiro(str_a,setA);
    idB = transformador_caractere_para_inteiro(str_b,setB);

     ordenacao_quicksort(setA,0,(idA-1));
     ordenacao_quicksort(setB,0,(idB-1));

     remover_elementos_duplicados(setA,&idA);
     remover_elementos_duplicados(setB,&idB); 

	printf("1)\n");
	printf("Letra A:");
     igualdade_AB(setA,setB,idA,idB);
    printf("Letra B:");
    printf(subconj_AB(setA,setB,idA,idB)? " Esta contido":" Nao esta contido");
    printf("\n");
	printf("\nLetra C:");
    printf(subconj_AB(setB,setA,idB,idA)? " Esta contido":" Nao esta contido");
    printf("\n");
    printf("\nLetra D:");
	 cardinalidade(idA);
	printf("Letra E:");
     cardinalidade(idB);
	printf("Letra F:");
     produto_cartesiano(setA,setB,idA,idB);
    printf("Letra G:");
    k = uniao(setA,setB,idA,idB);
    printf("Letra H:");
	 cardinalidade(k);
    printf("Letra I:");
    l = intersecao(setA,setB,idA,idB);
    printf("Letra J:");
	 cardinalidade(l);
    printf("Letra K:");
    diferenca(setA,setB,idA,idB);
     printf("\n");
	printf("\nLetra L:");
    diferenca(setB,setA,idB,idA);

}

int questao_n2()
{
    FILE* arq2;
    char strn_aaa[12345],strn_bbb[12345];
    int index_aaa = 0,index_bbb = 0,set_aaa[12345],set_bbb[12345];

    arq2 = fopen("anexo2.csv","r");

    if(arq2 == NULL)
    {
        printf("Nao foi Possivel abrir o arquivo\n");
        return 1;
    }

  index_aaa = transformador_caractere_para_inteiro(strn_aaa,set_aaa);
  index_bbb = transformador_caractere_para_inteiro(strn_bbb,set_bbb);
  ordenacao_quicksort(set_aaa,0,index_aaa-1);
  ordenacao_quicksort(set_bbb,0,index_bbb-1);

  remover_elementos_duplicados(set_aaa,&index_aaa);
  remover_elementos_duplicados(set_bbb,&index_bbb);

    printf("\n");
    printf("\n2)");
    printf(injetora(set_aaa,set_bbb,index_aaa,index_bbb) ? "\nA funcao e injetora\n":"\nA funcao nao e injetora\n");
    printf(bijetora(set_aaa,set_bbb,index_aaa,index_bbb)? "\nA funcao e bijetora\n":"\nA funcao nao e bijetora\n");
    printf(sobrejetora(set_aaa,set_bbb,index_aaa,index_bbb) ? "\nA funcao e sobrejetora\n":"\nA funcao nao e sobrejetora\n");
    
    }
    
int questao_n3()
{
    FILE * arqCSV3 = fopen("anexo3.csv","r");
    char  str_c[12345];
    int idE;
    int setE[12345];

    if(arqCSV3 ==  NULL )
    {
        printf("Nao leu o arquivo\n");
        return 0;
    }

    fgets(str_c,12345,arqCSV3);
    idE = transformador_caractere_para_inteiro(str_c,setE);

	printf("\n");
    printf("3)\nLetra A:\n");
    somatorio_constante(setE,idE);
    printf("\n");
    printf("Letra B:\n");
    somatoria_progressao_aritmetica(setE,idE);
    printf("\n");
    printf("Letra C:\n");
    somatoria_elevado_quadrado(setE,idE);
    printf("\n");
    printf("Letra D:\n");
    somatoria_elevado_cubo(setE,idE);
    printf("\n");
    printf("Letra E:\n");
    somatoria_elevado_quatro(setE,idE);
    printf("\n");
    printf("Letra F:\n");
    somatoria_elevado_cinco(setE,idE);
    printf("\n");
    printf("Letra G:\n");
    somatoria_elevado_seis(setE,idE);
	
	fclose(arqCSV3);

    return 0;
	
}

    int questao_n4(){

    printf("\n");
    printf("4)\nLetra A: ");
    naturais_invertidos();
    printf("\n");
    printf("Letra B: ");
    progressao_aritmetica();
    printf("\n");
    printf("Letra C: ");
    elevador_potencia_quadrada();
    printf("\n");
    printf("Letra D: ");
    fibonacci();
    printf("\n");

}

void somatorio_constante(int *conj_x,int index_x)
{
    int i;
    for(i=0; i<index_x; i++)
    {
        printf("%d\n",conj_x[i]);

    }

}

void somatoria_progressao_aritmetica(int *conj_x,int index_x)
{
    int i,result,n;
    for(i=0; i<index_x; i++)
    {
    	n = conj_x[i];
        result = (n*(n+1))/2;
        printf("%d\n",result);

    }

}

void somatoria_elevado_quadrado(int *conj_x,int index_x)
{

    int i,result,n;
    for(i=0; i<index_x; i++)
     {
 		n = conj_x[i];
        result = (n*(n+1)*(2*n+1))/6;
        printf("%d\n",result);

    }
}

void somatoria_elevado_cubo(int *conj_x,int index_x){
	 int i,result,n;
    for(i=0; i<index_x; i++)
    {
        n = conj_x[i];
        result =(n*n*(n+1)*(n+1))/4;
        printf("%d\n",result);

    }

}

void somatoria_elevado_quatro(int *conj_x,int index_x){
	int i;
	long long int result,n;
    for(i=0; i<index_x; i++)
    {
    	n=conj_x[i];
        result = (n*(n+1)*(2*n+1)*(3*n*n +3*n -1))/30;
        printf("%lld\n",result);

    }

}

void somatoria_elevado_cinco(int *conj_x,int index_x){

	int i;
	long long int result,n;
    for(i=0; i<index_x; i++)
    {
    	n=conj_x[i];
        result = (n*n*((n+1)*(n+1))*(2*n*n+2*n -1))/12;
        printf("%lld\n",result);

    }

}

void somatoria_elevado_seis(int *conj_x,int index_x){

	int i;
	long long int result,n;
    for(i=0; i<index_x; i++)
    {
    	n=conj_x[i];
        result = (n*(n+1)*(2*n+1)*(3*n*n*n*n+6*n*n*n -3*n +1))/42;
        printf("%lld\n",result);

    }

}

void naturais_invertidos()
{
    int natural,n=20;

    for(natural=1; natural <=n; natural++)
    {

        printf("1/%d ",natural);
    }

}

void progressao_aritmetica()
{
    int natural,n=39;

    for(natural=1; natural<=39; natural=natural+2)
    {
        printf("%d ",natural);

    }

}

void elevador_potencia_quadrada()
{
    int n=20,natural;
    for(natural=1; natural<=20; natural++)
    {

        printf("%d ",(int)(pow(natural,2)));

    }

}

void fibonacci()
{

    int n=20,cont=0,aux1=1,aux2=0,aux=1;

    while(cont!=n)
    {

        if(aux==0)
        {
            printf("%d",aux);
        }

        aux=aux1;

        aux1=aux1+aux2;

        aux2=aux;

        cont++;

        printf("%d ",aux);
    }
    printf("\n");
}

void igualdade_AB(int x[], int y[],int index_x,int index_y)
{

    bool ok;

    int i,j;
    if(index_x!=index_y)
    {
        ok=false;

    }
    else
    {
        for(i=0; i<index_x; i++)
        {
            if(x[i] != y[i])
            {
                ok=false;
                break;

            }

        }

    }

    printf(ok ? " Sao iguais\n":" Nao sao iguais\n");
    printf("\n");
}

bool subconj_AB(int x[], int y[],int index_x,int index_y)
{
    int i,j,cont=0;
if(index_x>index_y){
  return false;
}
   else{
   for(i=0;i<index_x;i++){
     for(j=0;j<index_y;j++){
        if(x[i] == y[j]){
           cont++;

        }

     }

  }

 }

if(cont==index_x){
    return true;
}else{
  return false;
}

}

void cardinalidade(int index_x)
{
    printf(" Cardinalidade: %d\n",index_x);
    printf("\n");

}

void produto_cartesiano(int x[], int y[],int index_x,int index_y)
{
    int i,j;
    printf(" Produto Cartesiano: ");
    printf("{ ");
    for(i=0; i<index_x; i++)
    {
        for(j=0; j<index_y; j++)
        {

            printf("(%d,%d)",x[i],y[j]);
        }
        printf("\n");

    }
    printf(" }\n");
    printf("\n");

}

int uniao(int x[], int y[],int index_x,int index_y)
{
    int i;

    int indexn = index_x+index_y;

    int uniaoxy[indexn];
    sort_m(x,y,uniaoxy,index_x,index_y);

    remover_elementos_duplicados(uniaoxy,&indexn);

    printf(" Uniao:");

    for(i=0; i<indexn; i++)

    {

        printf("%d ",uniaoxy[i]);

    }

    printf("\n");
    printf("\n");
  return indexn;
}

int intersecao(int x[], int y[],int index_x,int index_y)
{
int i,j=0,sec=0;
int intersec[index_x+index_y];
 for(i=0;i<index_x;i++){
     while((j<index_y)&&(x[i]>=y[j])){

       if(x[i]==y[j]){
        intersec[sec++]=y[j];
        j++;
        break;
        }
        j++;
    }

 }
 printf(" Intersecao:");
 for(i=0;i<sec;i++){

    printf("%d ",intersec[i]);
 }
printf("\n");
printf("\n");

return sec;

}

void diferenca(int x[], int y[],int index_x,int index_y)
{
  int i,j,vet[index_x+index_y],id=0,dif[index_x+index_y],idf=0;

  printf(" Diferenca: ");
  for(i=0;i<index_x;i++){
    for(j=0;j<index_y;j++){
        if(x[i] == y[j]){
            vet[id++] = x[i];
		}

    }

  }
  j=0;
  i=0;
while(i<index_x){
    if(vet[j]==x[i]||vet[j]<x[i]){
		   j++;
    }else{
	  dif[idf++]= x[i];
		}

	i++;

}
remover_elementos_duplicados(dif,&idf);

for(i=0;i<idf;i++){
    printf("%d ",dif[i]);

}

}

void ordenacao_quicksort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j)
    {
        while(a[i] < x && i < right)
        {
            i++;
        }
        while(a[j] > x && j > left)
        {
            j--;
        }
        if(i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left)
    {
        ordenacao_quicksort(a, left, j);
    }
    if(i < right)
    {
        ordenacao_quicksort(a, i, right);
    }
}

int transformador_caractere_para_inteiro(char str_a[], int *set_a)
{


    int j=0,soma=0,y,exp=0,indice=0;


    while(j<(int)strlen(str_a)+1)
    {
        y=j;

        if(str_a[y]==';'||str_a[y]=='\n')
        {

            y--;
            while(y>=0&&str_a[y]!=';')
            {

                soma+=(str_a[y] - '0')*pow(10,exp++);

                y--;

            }

            set_a[indice++]=soma;
        }

        j++;
        exp=0;
        soma=0;

    }

    return indice;
}

void remover_elementos_duplicados(int *conj_x,int *indice)
{
    int i, j, k;

    for( i = 0; i < *indice; i++ )
    {
        for( j = i + 1; j < *indice; )
        {
            if( conj_x[j] == conj_x[i] )
            {
                for( k = j; k < *indice; k++ )
                    conj_x[k] = conj_x[k + 1];

                (*indice)--;
            }
            else
            {
                j++;
            }
        }
    }


}

void sort_m(int x[], int y[], int *uniao,int index_x,int index_y)
{

    int indexuniao=0;
    int j=0,i;

    for(i=0; i<index_x; i++)
    {

        while(j<index_y && y[j]<x[i])
        {

            uniao[indexuniao++] = y[j];

            j++;
        }

        uniao[indexuniao++]=x[i];
    }

    while(j<index_y)
    {


        uniao[indexuniao++]=y[j];
        j++;
    }

}

bool sobrejetora(int x[], int y[],int index_x,int index_y){

  int i,j=0,result,n,sob[5000];

  for(i=0;i<index_x;i++){

  	  n = x[i];
  	  result = n+5;
  	  sob[j++] = result;

  }

  if(subconj_AB(x,sob,index_x,index_y)){

     return true;
  }
  else{

     return false;
  }

}

bool injetora(int x[], int y[],int index_x,int index_y){
  int i,j=0,result,n,inj[5000],cp[5000],cont=0;
  for(i=0;i<index_x;i++){

  	  n = x[i];
  	  result = n+5;
  	  inj[j++] = result;
  	  cp[cont++] = result;

  }
	remover_elementos_duplicados(inj,&j);

   if(cont==j){return true;}

   return false;

}

bool bijetora(int x[], int y[],int index_x,int index_y){

   if(sobrejetora(x,y,index_x,index_y)&&injetora(x,y,index_x,index_y)) {

    return true;
    }

    return false;
    
}
