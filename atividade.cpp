#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

#include "primitiva.h"


 int main(){
	/// abrir janela//////
	XMAX = 600; YMAX = 400;
	int opcao, tx,ty;
	double coef, angulo;
	
    do{
    	//// chama o menu////
		menu();	
		/// escolher uma opcao de entrada///
		cout << "\nEscolha uma opcao: ";
		cin >> opcao;
	
    switch (opcao){
    	
    case 0: //limpar tela 
        system("cls || clear");
    	break;
    
	case 1: //
	
		initwindow(XMAX, YMAX);
		
		Triangulo(150, 100, 100, 300, 300, 300);
					
		getch( );
		closegraph( );
		break;	
        
		//////////// escalar ////	
	case 2:
	
		cout<<"digite o valor do Coeficiente escalar";
		cin>> coef;
		initwindow(XMAX, YMAX);
				 Escala(100, 150, 300, 300, 2.2);
				 Escala(100, 120, 120, 250, 2.2);
				 Escala(150, 120, 120, 250, 2.2);		 
        getch();
		closegraph();
		break;
	
	case 3: 
		cout<<"digite o valor do angulo";
		cin>> angulo;
		initwindow(XMAX, YMAX);
		Rotacao(40, 70, 50, 50, angulo);
		Rotacao(40, 55, 50, 90, angulo);
		Rotacao(70, 55, 50, 90, angulo);
		getch();
		closegraph();
		break;
		
	case 4:
	
		cout<<"digite o valor do Coeficiente de translatação de x";
		cin>>tx;
		cout<<"digite o valor do Coeficiente de translatação de y";
		cin>>ty;
		initwindow(XMAX, YMAX);
	
				Translatacao(100, 120, 100, 100, tx,ty);
				Translatacao(100, 105, 100, 140,  tx,ty);
				Translatacao(120, 105, 100, 140,  tx,ty);
		getch( );
		closegraph( );
		break;
	case 5: 
		cout<<"desenhar triangulo invertido";
		initwindow(XMAX, YMAX);
		espelhamento(80, 110, 90, 90);
		espelhamento(80, 95, 90, 130);
		espelhamento(110, 95, 90, 130);
		getch( );
		closegraph( );
		break;
		
	case 6:
       	
		cout <<"digite o valor do Coeficiente escalar";
		cin >> coef;
		initwindow(XMAX, YMAX);
		Escala_fixa(100, 120, 100, 100, coef);
		Escala_fixa(100, 105, 100, 140, coef);
		Escala_fixa(120, 105, 100, 140, coef);
		getch( );
		closegraph( );
		break;
	
	case 7:
	
				cout <<"digite o valor do angulo";
				cin >> angulo;
				initwindow(XMAX, YMAX);
				Rotacao_fixa(100, 120, 100, 100, angulo);
				Rotacao_fixa(100, 105, 100, 140, angulo);
				Rotacao_fixa(120, 105, 100, 140, angulo);
				getch( );
				closegraph( );
		break;
	
	case 8: //sair
		break;	
	  
}
	}while(opcao != 8);
	
return  0;
}

