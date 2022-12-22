#define Pi 3.14159
#define SIGN(x) ((x) < 0 ? (-1) : (1))
#define ABS(x) ((x) < 0 ? (-x) : (x))

using namespace std;
int p1[2], p2[2],p3[2],XMAX,YMAX;

//------------------MENU------------------
void menu(){
    cout << "----------------- MENU -----------------" << endl;
    cout << "[0] Limpar Tela" << endl;//OK
    cout << "[1] Algoritmo Reta: Equacao Geral" << endl;//OK
    cout << "[2] Algoritmo Reta: Equacao Diferencial" << endl;//OK
    cout << "[3] Algoritmo Reta: Bresenham" << endl; //OK
    cout << "[4] Construir grade na janela" << endl;
    cout << "[5] Sair" << endl; //OK
    cout << "----------------------------------------" << endl;
}

//-----EQUAÇÃO GERAL----
void EquacaoGeral(int p1[2],int p2[2]){ 
		int y, x, valorx1, valorx2, valory1, valory2, m, b;

	int total = 0;
	valorx1= p1[0];
	valorx2= p2[0];
	valory1=p1[1];
	valory2= p2[1];
		
    if(valorx1 == valorx2){
		for(y = valory1; y < valory2 ;y++)
			putpixel(valorx1,YMAX-y,1);
	}else{
		m = (valory2-valory1)/(valorx2-valorx1);
		b = valory2 - m*valorx2;
		for(x = valorx1; x < valorx2; x++){
			y = m*x + b;
			putpixel(x,YMAX-y,1);
		}
    }
}
////////////////////////////////////////////////////////////////////////////////////
//------------------EQUAÇÃO DIFERENCIAL------------------
////////////////////////////////////////////////////////////////////////////////////
void DDA(int p1[2], int p2[2]){
	int x, x1, x2, y1, y2;
	float y, m;
	int valor;
	x1=p1[0];
	x2=p2[0];
	y1=p1[1];
	y2=p2[1];
	m = (y2-y1)/(x2-x1); /* 0 < |m| < 1 */
	for (x = x1; x <= x2; x++) {
		y= y1+ m*(x-x1);
	putpixel(x, round(y), valor);
	}
}
//////////////////////////////////////////////////////////////////////////////
//------------------BRESENHAM------------------
///////////////////////////////////////////////////////////////////////////
void Bresenham(int x1, int y1, int x2, int y2){
	int i,Sinalx,Sinaly,x,y,Troca;
	float Dx,Dy,tmp,P;
	Dx= ABS((x2-x1));
	Dy= ABS((y2-y1));
	Sinalx=SIGN((x2-x1));
	Sinaly=SIGN((y2-y1));
	x = x1;
	y = y1;
	if (Sinalx < 0)
	  x -=1;
	if (Sinaly < 0 )
	  y -= 1;
// trocar Dx por Dy dependendo da inclinacao da reta
	Troca= FALSE;
 	if (Dy > Dx){
  		tmp= Dx;
    	Dx= Dy;
    	Dy= tmp;
    	Troca= TRUE;
   }
	P= 2*Dy-Dx;
  	for(i=0;i<Dx;i++){
		putpixel(x,YMAX-y,5);
		while(P>=0) { 
	  		if(Troca)
				x = x+Sinalx;
      		else
       			y=y+Sinaly;
     		P = P -2*Dx;
    }
    if(Troca)
    	y = y+Sinaly;
    else
    	x = x+Sinalx;
    P= P +2*Dy;
   } 
		 
}   
/////////////////////////////////////////////////////
/////------------------TRACEJADO------------------
///////////////////////////////////////////////
void tracejado(){
  
  ///////////////// horizontal ////////////////////////////////
  	int y, x, valorx1, valorx2, valory1, valory2, m, b;
	int numeroDeLinhas = 0;
	int total = 0;
	valorx1= 1;
	valorx2= 600;
	valory1=1;
	valory2= 0;
	for(numeroDeLinhas = 0; numeroDeLinhas <= 10; numeroDeLinhas++){
		
       	if(valorx1 == valorx2){
		for(y = valory1; y < valory2 ;y++)
			putpixel(valorx1,YMAX-y,1);
	}else{
		m = (valory2-valory1)/(valorx2-valorx1);
		b = valory2 - m*valorx2;
		for(x = valorx1; x < valorx2; x++){
			y = m*x + b;
			putpixel(x,YMAX-y,1);
		}
	} 
	total = total + 50;
	valory2 = total;
	valorx1= 1;
	valorx2= 600;
	valory1=1;

    }
    
    /////////////// vertical ////////////////
    
	numeroDeLinhas = 0;
    total = 0;
    valorx1= 50;
    valorx2=50;
	valory1=0;
	valory2= 800;
	for(numeroDeLinhas = 0; numeroDeLinhas <= 12; numeroDeLinhas++){
		
       	if(valorx1 == valorx2){
		for(y = valory1; y < valory2 ;y++)
			putpixel(valorx1,YMAX-y,1);
	}else{
		m = (valory2-valory1)/(valorx2-valorx1);
		b = valory2 - m*valorx2;
		for(x = valorx1; x < valorx2; x++){
			y = m*x + b;
			putpixel(x,YMAX-y,1);
		}
	} 
	total = total + 50;
	valorx2 = total;
	valorx1= valorx2;
	valory2= 800;
	valory1=0;

    }  
}

///////////////////////////////////////////////////////////////
//------------------CONSTRUIR GRADE NA JANELA SEM ALGORITIMO DA RETA------------------
///////////////////////////////////////////////////////////
/*void gradeJanela(){
    //// VERTICAL ////////
    line(0, 1200, 10,0);
    line(50, 1200, 50,0);
    line(100, 1200, 100,0);
    line(150, 1200, 150,0);
    line(200, 1200, 200,0);
    line(250, 1200, 250,0);
    line(300, 1200, 300,0);
    line(350, 1200, 350,0);
    line(400, 1200, 400,0);
    line(450, 1200, 450,0);
    line(500, 1200, 500,0);
    line(550, 1200, 550,0);
    line(600, 1200, 600,0);
    line(650, 1200, 650,0);
    line(700, 1200, 700,0);
    line(750, 1200, 750,0);
    line(800, 1200, 800,0);
    line(850, 1200, 850,0);
    line(900, 1200, 900,0);
    line(950, 1200, 950,0);
    line(1000, 1200, 1000,0);
    line(1050, 1200, 1050,0);
    line(1100, 1200, 1100,0);
    line(1150, 1200, 1150,0);
    line(1200, 1200, 1200,0);
    line(1250, 1200, 1250,0);
    line(1300, 1200, 1300,0);
    line(1350, 1200, 1350,0);
    line(1400, 1200, 1400,0);
    line(1450, 1200, 1450,0);
    line(1500, 1200, 1500,0);
    line(1550, 1200, 1550,0);
    line(1600, 1200, 1600,0);
    line(1650, 1200, 1650,0);
    line(1700, 1200, 1700,0);
    line(1750, 1200, 1750,0);
    line(1800, 1200, 1800,0);
    line(1850, 1200, 1850,0);
    line(1900, 1200, 1900,0);
    line(1950, 1200, 1950,0);
  
   
    //(pocicao linear ---, altura || , posicao vertical ||, inicio 0)

    //////////////////////////// HORIZONTAl /////////////////////
    line(0, 0,1500,0);
    line(0, 50,2000,50);
    line(0, 100,2000,100);
    line(0, 150,2000,150);
    line(0, 200,2000,200);
    line(0, 250,2000,250);
    line(0, 300,2000,300);
    line(0, 350,2000,350);
    line(0, 400,2000,400);
    line(0, 450,2000,450);
    line(0, 500,2000,500);
    line(0, 550,2000,550);
    line(0, 600,2000,600);
    line(0, 650,2000,650);
    line(0, 700,2000,700);
    line(0, 750,2000,750);
    line(0, 800,2000,800);
    line(0, 850,2000,850);
    line(0, 900,2000,900);
    line(0, 950,2000,950);
    line(0, 1000,2000,1000);
	

}*/
