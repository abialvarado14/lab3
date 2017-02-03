#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
void evaluarMatriz(string);
string calcularDia(int, int, int);
int main(){
	
	int num;
	
	string cadena, fecha, dia;
	string year="",month="",day="";
	char resp = 's';
	int y,m,d,a1,a2;
	string c1, c2;
	string meses[13];

	meses[1] = "Enero";
	meses[2] = "Febrero";
	meses[3] = "Marzo";
	meses[4] = "Abril";
        meses[5] = "Mayo";
        meses[6] = "Junio";
	meses[7] = "Julio";
        meses[8] = "Agosto";
        meses[9] = "Septiembre";
        meses[10] = "Octubre";
        meses[11] = "Noviembre";
        meses[12] = "Diciembre";




	cout << "Menu\nIngrese el programa que desea\n1.Programa de Balance\n2.Programa de fechas ";
	cin >> num;

	switch(num){
	
	case 1:
		cout << "Ingrese la cadena: ";
		cin >> cadena;
		

		for (int i=0;i<cadena.size();i++){
		while (cadena[i]!='{' && cadena[i] != '}' && cadena[i] != '(' && cadena[i] != ')' && cadena[i] != '[' && cadena[i] != ']'){
                        cout << "En la cadena se encontraron valores que no son validos, ingrese de nuevo";
                        cin >> cadena;
                        i=0;
                }
		}
		evaluarMatriz(cadena);
	break;
	
	case 2:
		while (resp == 's' || resp == 'S'){

		cout << "Ingrese la fecha: ";
		cin >> fecha;
		
		for (int i; i<fecha.size(); i++){

			if (i<4)
			year = year+fecha[i];
			
			if (i>3&&i<6)
			month = month+fecha[i];
			
			if (i>5 && i<9)
			day = day+fecha[i];
		}
		cout << "Year" << year;
		y = atoi(year.c_str());
		m = atoi(month.c_str());
		d = atoi(day.c_str());
		
		while (m<0 || m>12 || d<0||d>32){//validación

			cout << "FECHA INCORRECTA";
			cout << "\nIngrese la fecha:";
			cin >> fecha;
			
		  for (int i; i<fecha.size(); i++){
                        if (i<4)
                        	year = year+fecha[i];
                        if (i>3&&i<6)
                        	month = month+fecha[i];
                        if (i>5 && i<9)
                        	day = day+fecha[i];
                  }

                	y = atoi(year.c_str());
                	m = atoi(month.c_str());
                	d = atoi(day.c_str());

		}
		cout << "Fecha" << d;
		dia = calcularDia(y,m,d);
		cout << dia << ", " << d << " de " << meses[m] << " del " << y;
		cout << "Desea seguir ingresando fechas?[s/n]: ";
		cin >> resp;

		}//fin while respuesta de usuario
	break;
	}

return 0;
}

void evaluarMatriz(string cadena){
	int cparentesis=0,ccorchetes=0,cllaves=0,cparentesis2=0,ccorchetes2=0,cllaves2=0;
	for (int i=0;i<cadena.size();i++){
		char c = cadena[i];
		if (c == '(')
			cparentesis++;
		if (c == ')')
			cparentesis2++;
		if (c == '{')
			cllaves++;
		if (c == '}')
			cllaves2++;
		if (c == '[')
			ccorchetes++;
		
		if (c == ']')
			ccorchetes2++;

		}
	if (cparentesis == cparentesis2 && ccorchetes  == ccorchetes2  && cllaves  == cllaves2)
		cout << "Balanceado";
	else
		cout << "No Balanceado";
	
	}
string calcularDia(int y, int m, int d){
	
	int dia;
	string dias[8];
        dias [0] = "Domingo";
	dias[1]="Lunes";
        dias[2]="Martes";
        dias[3]="Miercoles";
        dias[4]="Jueves";
        dias[5]="Viernes";
        dias[6]="Sabado";

	dia = d + (((m+1)*26)/10 + y%100 + (y%100/4)+5-y/100)%7-4;

	return dias[dia];
	
}

