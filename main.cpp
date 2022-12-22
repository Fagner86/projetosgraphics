#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "primitivas.h"

int main(){
	/// abrir janela//////
	XMAX = 600; YMAX = 400;
    int x1,x2,y1,y2, opcao, total;
	
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
        
  	case 1: //Algoritmo Reta: Equacao Geral     
		cout<<"Digite o ponto inicial da reta (X1,Y1): ";
		cin>>p1[0]>>p1[1];
		cout<<"Digite o ponto final da reta (X2,Y2): ";
		cin>>p2[0]>>p2[1];
		initwindow(XMAX, YMAX);
		EquacaoGeral(p1,p2);
        getch( );
		closegraph( );
		break;
			
  	case 2: //Algoritmo Reta: Equacao Diferencial
	    cout<<"Digite o ponto inicial da reta (X1,Y1): ";
		cin>>p1[0]>>p1[1];
		cout<<"Digite o ponto final da reta (X2,Y2): ";
		cin>>p2[0]>>p2[1];
		initwindow(XMAX, YMAX);
		DDA(p1, p2);
		getch( );
		closegraph( );
		break;
		
	case 3: //bresenham   
    	cout<<"Digite o ponto inicial (X1,Y1): ";
		cin>>x1>>y1;
		cout<<"Digite o ponto final (X2,Y2): ";
		cin>>x2>>y2;
		initwindow(XMAX, YMAX);
		Bresenham(x1, y1, x2, y2);			
		getch( );
		closegraph( );
		break;
	
	case 4: //construir grade na janela
		initwindow(XMAX, YMAX);//janela 720x440
	    tracejado();
		getch( );
		closegraph( );
		break;	
	
	case 5: //sair
		break;	
	  }
	  
	}while(opcao != 5);
	
return  0;
}
