/*Con base al código SueldosEmpleados ubicado en el repositorio tutorias FP validar las siguientes condiciones.
*Validar que el nombre del cliente o usuario de la planilla pueda tener espacios por ejemplo:
(Salvador Marcelo Mejía Hernández) puede usar el código Getline como base o la validación de su preferencia.  
(Consejo: si usa getline para validar, antes (arriba de la validación se recomiendo poner cin.ignore))
*Validar que no se puedan escribir datos erróneos: si tu variable es de tipo caracteres o palabras
 no pueden usarse números, si tu variable es de tipo numérica no pueden usarse palabras o números negativos 
 a menos que se requieran.
*Validar que el dui este correcto.
 (en la sesión de esta semana adjunte un ejemplo de como validarlo, pueden hacerlo así o como prefieran).*/


 #include <iostream>
 #include <string.h>
 #include <cctype>
 #include <stdio.h>
 #include <stdlib.h>
using namespace std;

struct Empleado
{
    string nombreEmpleado;
    float sueldo;
    string dui;
}empleado[50];

bool esEntero(string num,int n) {//Verifica que sea un numero
	bool esEntero = true;
	int longitud = num.size();
	
	if (longitud == 0) {
		esEntero = false;
	} else if (longitud == 1 && !isdigit(num[0])) {
		esEntero = false;
	} else {
		int indice = 0;
		if (num[0] == '+' || num[0] == '-') {
			indice = 1;
		} else {
			indice = 0;
		}
		
		while (indice < longitud) {
			if (!isdigit(num[indice])) {
				esEntero = false;
				break;
			}
			indice++;
		}
	}
	
	if((num[0]=='-')and(n==2)){
		esEntero=false;
	}

	return esEntero;	
}

bool validarDui(string dui) {
	const string Digitos = "0123456789";

	if ((dui.size() > 10 or dui.size() < 9) or
	    (dui.size() == 10 and dui[8] != '-')) {
		return false;
	}

	for (size_t i = 0; i < dui.size(); i++) {
		if (dui.size() == 10 and i == 8) continue;

		if (Digitos.find(dui[i]) == string::npos) {
			return false;
		}
	}
	return true;
}

void informacion(int nEmpleados)
{
    cout<<"\nInformacion de empleados"<<endl;
    for (int i = 0; i < nEmpleados; i++)
    {   
    	bool repitename = true;
		string auxname;
		do {//Verifica que el nombre no sean numeros
			cin.ignore();
        	cout<<"Ingrese el nombre del empleado "<< i+1 << ": ";
			getline(cin,auxname);//El usuario ya puede ingresar espacios
			if (esEntero(auxname,1)) {
				cout << "Valor invalido. Intentalo nuevamente" << endl;
			} else {
				repitename = false;
			}
		} while (repitename);
		
        empleado[i].nombreEmpleado=auxname;
        
        bool repite = true;
		string num;
		do {
			cout<<"Ingrese el sueldo de su empleado en dolares: $";
			getline(cin, num);
		
			if (esEntero(num,2)) {
				repite = false;
			} else {
				cout << "Valor invalido. Intentalo nuevamente" << endl;
			}
		} while (repite);
		empleado[i].sueldo = atoi(num.c_str());
        
        bool repitedui = true;
        
        do {
        	string auxdui;
			cout<<"Ingrese el dui del empleado: ";
			getline(cin,auxdui);
			
			if (validarDui(auxdui)){
				empleado[i].dui=auxdui;
				repitedui = false;
			} else {
				cout << "DUI invalido. Intentalo nuevamente" << endl;
			}
		} while (repitedui);
        
    }
    return;
    
}



void informe(int nEmpleados)
{
    cout<<"\tVer empleados"<<endl;
    for (int i = 0; i < nEmpleados; i++)
    {
        cout<<"Nombre del empleado: "<< empleado[i].nombreEmpleado<<endl;
        cout<<"Sueldo base: "<< empleado[i].sueldo<<endl;
        cout<<"DUI del empleado: "<< empleado[i].dui<<endl;
    }
    return;
    
}
//Sueldos con descuentos de renta y seguro
void planilla(int nEmpleados)
{
    cout<<"\tTu planilla de empleados"<<endl;
    float t;
    for (int i = 0; i < nEmpleados; i++)
    {
        cout<<"Nombre del empleado: "<<empleado[i].nombreEmpleado<<endl;
        t = empleado[i].sueldo * 0.135;//t = al descuento del seguro y la renta de una vez
        cout<<"Sueldo Bruto: "<<empleado[i].sueldo<<endl;
        cout<<"Descuento de ISS (3.5%) y Renta (10%): "<<t<<endl;
        cout<<"Sueldo Neto: "<<(empleado[i].sueldo)-t<<endl;
        cout<<"Dui del empleado: "<< empleado[i].dui<<endl;
    }
    
}
void menu()
{
    int nEmpleados=0;
    int opcMenu;
    do
    {   
        cout<<"\nBienvenido: \n";
        cout<<"\nSeleccione una opcion: \n";
        cout<<"\n1.Ingresar datos de empleado. \n";
        cout<<"\n2.Ver informe de empleado. \n";
        cout<<"\n3.Ver planilla de empleados. \n";
        cout<<"\n4.Salir. \n";
        cout<<"\nOpcion: ";
        cin>>opcMenu;
        switch (opcMenu)
        {
        case 1:
            cout<<"Cantidad de empleados"<<endl;
            cin>>nEmpleados;
            informacion(nEmpleados);
            break;
        case 2:
            informe(nEmpleados);
            break;
        case 3:
            planilla(nEmpleados);
            break;
        case 4:
        cout<<"Tenga un feliz dia"<<endl;
            break;

        default:
        cout<<"Opcion invalida, intentelo de nuevo"<<endl;
            break;
        }
    }while (opcMenu != 4);
    
    
}

int main()
{
    menu();
    return 0;
}
