#include <iostream>
#include <math.h>
#include <graphics.h>
#include "primitivas.h"

  

 int main(){
	/// abrir janela//////
	XMAX = 600; YMAX = 400;
	int opcao;


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
		CirculoParametrica();			
		getch( ); // aguarda alguma tecla ser digitada na tela do DOS
		closegraph( ); // fecha modo gráfico
	break;	
        	
	case 2: //
		initwindow(XMAX, YMAX);
		CirculoPontoMedio();			
		getch( ); // aguarda alguma tecla ser digitada na tela do DOS
		closegraph( ); // fecha modo gráfico
	break;
	
	case 3: //
		initwindow(XMAX, YMAX);
		PreenchimentoDoCirculo();			
		getch( ); // aguarda alguma tecla ser digitada na tela do DOS
		closegraph( ); // fecha modo gráfico
	break;
	
	case 4: //
		initwindow(XMAX, YMAX);
  		ConstrucaoPreenchimentoElipses(250, 250, 100, 50);
		getch( ); // aguarda alguma tecla ser digitada na tela do DOS
		closegraph( ); // fecha modo gráfico
	break;
	
	case 5: //
		initwindow(XMAX, YMAX);
		PreenchimentoDePoligonosQuaisquer();
		getch( ); // aguarda alguma tecla ser digitada na tela do DOS
		closegraph( ); // fecha modo gráfico
	break;
	
	case 6: //
	break;

	  }
	  
	}while(opcao != 6);
	
return  0;
}
