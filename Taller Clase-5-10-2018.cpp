/*
*Programa: menu que permita ingresar la edad de la persona y mostrar diferentes opciones
*Fecha: 28/10/2018
*Creador: Juan Diego Rios Ballesteros
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Prototipo del menu
int menu();
// prototipo  calcular tiempo 
int calculartiempo(int dia, int me, int anno);

// Estructura para el ingreso de fecha de nacimiento
struct fecha{
	int dia;
	int mes;
	int anno;
};
// Structura para el registro de la persona
struct registro{
	char name[30];
	char identificacion[30];
	char ciudad[30];
	struct fecha lista;
}persona[8];

// Funcion menu
int menu(){
	int seleccion;
	printf("MENU\n");
	printf("1. Ingreso de un registro.\n");
	printf("2. Ingreso de dias, mes y año de nacimiento.\n");
	printf("3. Presentar informacion de la persona y nacimiento.\n");
	printf("4. Presentar años vividos.\n");
	printf("5. Presentar meses vividos.\n");
	printf("6. Presentar dias vividos.\n");
	printf("7. Presentar si la persona es mayor de edad.\n");
	printf("8. Presentar si la persona es menor de edad.\n");
	printf("0. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &seleccion);
	return seleccion;
}

int main() {	
	
	int seleccion, n = 0, m = 0, dia, mes, anno, tanno = 0, tmes = 0, tdia = 0;
	
	printf("Ingrese el dia actual: ");
	scanf("%d", &dia);
	printf("Ingrese el mes actual: ");
	scanf("%d", &mes);	
	printf("Ingrese el año actual: ");
	scanf("%d", &anno);	
	do{
		system("cls");		
		seleccion = menu();		
		switch(seleccion){
			case 1:{
				system("cls");
				if(n < 8){
					printf("Registro %d\n", n+1);
					printf("Ingrese el nombre: ");
					fflush(stdin);
					gets(persona[n].name);
					printf("Ingrese la identificacion: ");
					fflush(stdin);
					gets(persona[n].identificacion);
					printf("Ingrese la ciudad de nacimiento: ");
					fflush(stdin);
					gets(persona[n].ciudad);				
					n++;					
				}else{
					printf("Maxima capacidad de registros realizados, por favor mirar las otras opciones");
				}
				getch();
				break;
			}
			case 2: {		
				system("cls");		
				if(m < 8){
					if(n > m)
					{
						printf("Registro de nacimiento %d\n", m +1);
						printf("Ingrese el dia de nacimiento: ");
						scanf("%d", &persona[m].lista.dia);
						printf("Ingrese el mes de nacimiento: ");
						scanf("%d", &persona[m].lista.mes);
						printf("Ingrese el año de nacimiento: ");
						scanf("%d", &persona[m].lista.anno);
						m++;
					}else if(n <= m){
						printf("No se ha ingresado el registro %d, vuelva a intentarlo\n", n+1);
					}		
				}else{
					printf("Maxima capacidad de registros realizados, por favor mirar las otras opciones");
				}				
				getch();
				break;
			}
			case 3:{
				system("cls");		
				if(n == 0){
					printf("No se ha ingresado ningun registro.");
				}else{
					printf("Datos completos\n");
					for(int i=0; i<n;i++){
						printf("registro %d\n", i+1);
						printf("Nombre: %s\n", persona[i].name);
						printf("Identificacion: %s\n", persona[i].identificacion);
						printf("Ciudad de nacimiento: %s\n", persona[i].ciudad);
						printf("Fecha de nacimiento(dd/mm/yyyy): %d/%d/%d\n", persona[i].lista.dia, persona[i].lista.mes, persona[i].lista.anno);
					}
				}
				getch();
				break;
			}
			case 4:{
					system("cls");					
					if(n == 0){
						printf("No se ha ingresado ningun registro.");
					}else{
						for(int i=0; i<n;i++){
							int bandera = 0;
							for(int a = persona[i].lista.anno; a <= anno; a++){								
								if(bandera == 0){	
									if(a%4==0){
										tdia++;
									}
										if(a < anno){
											for(int m = persona[i].lista.mes; m <= 12; m++){
												tmes++;
												if(m == 2){
													tdia+= 28;
												}else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
													tdia+=31;
												}else if(m == 4 || m == 6 || m == 9 || m == 11){
													tdia+=30;
												};		
											};
												
										}else if(a == anno){	
												for(int m = persona[i].lista.mes; m <= mes; m++){
													if(m < mes){
														tmes++;
														if(m == 2){
															tdia+= 28;
														}else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
															tdia+=31;
														}else if(m == 4 || m == 6 || m == 9 || m == 11){
															tdia+=30;
														};
													}else if(m == mes){
														tmes++;
														
														if(dia >= persona[i].lista.dia){
																tmes-=1;																
														};
														for(int m = 1; m <= dia; m++){
															tdia++;		
															if(m >= persona[i].lista.dia){
																tanno = (anno - persona[i].lista.anno);
															}else{
																tanno = (anno - persona[i].lista.anno);
															}
														}
													}			
												};											
										}
										printf("años vividos: %d\n", tanno);								
										printf("meses vividos: %d\n", tmes);
										printf("dias vividos: %d\n", tdia);
										  
									}
									bandera = 1;
								}							
							}
						
						
						
						
						
//						printf("años vividos\n");
//						for(int i = 0; i<n; i++){
//							printf("registro %d\n", i+1);
//							printf("Nombre: %s\n", persona[i].name);
//							printf("Identificacion: %s\n", persona[i].identificacion);
//							printf("Fecha de nacimiento(dd/mm/yyyy): %d/%d/%d\n", persona[i].lista.dia, persona[i].lista.mes, persona[i].lista.anno);
//							tanno = anno - persona[i].lista.anno;
//							if(mes <= persona[i].lista.mes){
//								tanno+=1;
//							}
//							printf("años vividos: %d\n", tanno);
//						}					
					}	
				getch();
				break;
			}
			case 5: {
					system("cls");
				
					if(n == 0){
						printf("No se ha ingresado ningun registro.");
					}else{
						printf("años vividos\n");
						for(int i = 0; i<n; i++){
							printf("registro %d\n", i+1);
							printf("Nombre: %s\n", persona[i].name);
							printf("Identificacion: %s\n", persona[i].identificacion);
							printf("Fecha de nacimiento(dd/mm/yyyy): %d/%d/%d\n", persona[i].lista.dia, persona[i].lista.mes, persona[i].lista.anno);
							tanno = anno - persona[i].lista.anno;
							tmes = (12 * tanno) + (mes - persona[i].lista.mes);
							
							printf("meses vividos: %d\n", tmes );
						}
						tanno = 0;
						tmes = 0;
						tdia = 0;
					}	
					getch();		
				break;
			}	
			case 6: {
				system("cls");
				if(n == 0){
					printf("No se ha ingresado ningun registro.");
				}else{
					printf("dia vividos\n");
					for(int i = 0; i<n; i++){
						printf("registro %d\n", i+1);
						printf("Nombre: %s\n", persona[i].name);
						printf("Identificacion: %s\n", persona[i].identificacion);
						printf("Fecha de nacimiento(dd/mm/yyyy): %d/%d/%d\n", persona[i].lista.dia, persona[i].lista.mes, persona[i].lista.anno);
						tanno = anno - persona[i].lista.anno;
						tmes = (12 * tanno) + (mes - persona[i].lista.mes);
						tdia = (365 * tanno) + ((mes - persona[i].lista.mes)*30);
						printf("dias vividos: %d\n", tdia);
						
					}
					tanno = 0;
					tmes = 0;
					tdia = 0;
				}	
				getch();
			
			break;
			}
			case 7: {
				system("cls");
				if(n == 0){
					printf("No se ha ingresado ningun registro.");
				}else{
					printf("dia vividos\n");
					for(int i = 0; i<n; i++){
						printf("registro %d\n", i+1);
						printf("Nombre: %s\n", persona[i].name);
						printf("Identificacion: %s\n", persona[i].identificacion);
						printf("Fecha de nacimiento(dd/mm/yyyy): %d/%d/%d\n", persona[i].lista.dia, persona[i].lista.mes, persona[i].lista.anno);
						tanno = anno - persona[i].lista.anno;
						if(tanno >= 18){
							printf("La persona es mmayor de edad\n");
						}
					}
					tanno = 0;
					tmes = 0;
					tdia = 0;
				}	
				getch();
				break;				
			}
			case 8: {
				system("cls");
				if(n == 0){
					printf("No se ha ingresado ningun registro.");
				}else{
					printf("dia vividos\n");
					for(int i = 0; i<n; i++){
						printf("registro %d\n", i+1);
						printf("Nombre: %s\n", persona[i].name);
						printf("Identificacion: %s\n", persona[i].identificacion);
						printf("Fecha de nacimiento(dd/mm/yyyy): %d/%d/%d\n", persona[i].lista.dia, persona[i].lista.mes, persona[i].lista.anno);
						tanno = anno - persona[i].lista.anno;
						if(tanno < 18){
							printf("La persona es menor de edad\n");
						}
					}					
				}	
				getch();
				break;
			}	
			default: {
				system("cls");	
				printf("La opcion no existe, vuelva a intentarlo\n");			
				getch();
			};			
		}
	} while(seleccion != 0);
	
}

