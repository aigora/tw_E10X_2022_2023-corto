#include <stdio.h>
#include <string.h>
typedef struct
{
	char mes[20];
	char tipos[20];
}emision;
typedef struct
{
	float carbon;
	float ciclo;
	float coge;
	float resi;
}datos;
emision meses[5];
emision tips[5];
datos mes[5];
float Max(float a, float b);
float Min(float a, float b);
int main()
{
	float total_tipos[4];
	float total_mes[4];
	int i;
	float max_carbon,max_ciclo,max_coge,max_resi,min_carbon,min_resi,min_ciclo,min_coge;
	strcpy(tips[0].tipos,"Carbon");
	strcpy(tips[1].tipos,"Ciclo Combinado");
	strcpy(tips[2].tipos,"Cogeneracion");
	strcpy(tips[3].tipos,"Residuos no renovables");
	strcpy(meses[0].mes,"Enero");
	strcpy(meses[1].mes,"Febrero");
	strcpy(meses[2].mes,"Marzo");
	strcpy(meses[3].mes,"Abril");
		//carbon
		mes[0].carbon=289120.200;
		mes[1].carbon=403070.529;
		mes[2].carbon=407632.865;
		mes[3].carbon=244126.197;
		//ciclo
		mes[0].ciclo=811289.317;
		mes[1].ciclo=1416302.980;
		mes[2].ciclo=960700.659;
		mes[3].ciclo=883449.381;
		//coge
		mes[0].coge=447374,074;
		mes[1].coge=631186,441;
		mes[2].coge=633520,195;
		mes[3].coge=575809,676;
		//resi
		mes[0].resi=22935,751;
		mes[1].resi=28500,343;
		mes[2].resi=26486,563;
		mes[3].resi=19215,440;
	for(i=0;i<5;i++)
	{
		total_mes[i]=mes[i].carbon + mes[i].ciclo + mes[i].coge + mes[i].resi;
		total_tipos[0] += mes[i].carbon;
        total_tipos[1] += mes[i].ciclo;
        total_tipos[2] += mes[i].coge;
        total_tipos[3] += mes[i].resi;
	}
	max_carbon = Max(Max(Max(mes[0].carbon, mes[1].carbon), mes[2].carbon), mes[3].carbon);
	max_ciclo = Max(Max(Max(mes[0].ciclo, mes[1].ciclo), mes[2].ciclo), mes[3].ciclo);
    max_coge = Max(Max(Max(mes[0].coge, mes[1].coge), mes[2].coge), mes[3].coge);
    max_resi = Max(Max(Max(mes[0].resi, mes[1].resi), mes[2].resi), mes[3].resi);
    min_carbon = Min(Min(Min(mes[0].carbon, mes[1].carbon), mes[2].carbon), mes[3].carbon);
	min_ciclo = Min(Min(Min(mes[0].ciclo, mes[1].ciclo), mes[2].ciclo), mes[3].ciclo);
    min_coge = Min(Min(Min(mes[0].coge, mes[1].coge), mes[2].coge), mes[3].coge);
    min_resi = Min(Min(Min(mes[0].resi, mes[1].resi), mes[2].resi), mes[3].resi);
	printf("%.3f",min_coge);
	//representar max min media porcentaje y tabla;
	
	
	return 0;
}
float Max(float a, float b) 
{
    if (a > b) 
	{
        return a;
    } 
	else
	{
        return b;
    }
}
float Min(float a, float b) 
{
    if (a < b) 
	{
        return a;
    } 
	else
	{
        return b;
    }
}

