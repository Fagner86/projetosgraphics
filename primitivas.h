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
    cout << "[4] Horizontal" << endl;
    cout << "[5] vertical" << endl;
    cout << "[6] Construir grade na janela" << endl;
    cout << "[7] Sair" << endl; //OK
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
		
		// se x1 for igual a x2
    if(valorx1 == valorx2){
		for(y = valory1; y < valory2 ;y++){
		//A rasterizacao dos pontos sera feita atraves da função PutPixel que rasteriza um ponto na memoria de video, recebendo como parametros as coordenadas (x,y) do pixel na tela e uma cor em RGBA
			putpixel(valorx1,YMAX-y,RED);
			// delay(100);
			//y = y+10;
			 }
	}else{
		//m é o coeficiente angular da reta
		m = (valory2-valory1)/(valorx2-valorx1);
		// b coeficiente linear 
		b = valory2 - m*valorx2;
		for(x = valorx1; x < valorx2; x++){
			//forma reduzida
			y = m*x + b;
			putpixel(x,YMAX-y,RED);
			// 	 delay(100);
				// x = x+10;
		}
    }
}
////////////////////////////////////////////////////////////////////////////////////
//------------------EQUAÇÃO DIFERENCIAL------------------
////////////////////////////////////////////////////////////////////////////////////
void DDA(int ponto1[2], int ponto2[2]){
 int pontoX0, pontoY0, pontoX1, ponyoY1, dx,dy, valor;
 float Xincremento, Yincremento, X, Y;
 
 pontoX0 = ponto1[0];
 pontoX1 = ponto1[1];
 pontoY0 = ponto2[0];
 ponyoY1 = ponto2[1];
    // calcula dx e dy
    dx = pontoX1- pontoX0;
    dy = ponyoY1- pontoY0;
 // saber se continua com o valor de dy ou dx
    if (abs(dx) > abs(dy))
        valor = abs(dx);
    else
        valor = abs(dy);
 
    // calcular o incremento em x e y para cada passo
    Xincremento = dx / (float)valor;
    Yincremento = dy / (float)valor;
 
    // coloca pixel para cada etapa
    X = pontoX0;
    Y = pontoY0;
    for (int i = 0; i <= valor; i++) {
        putpixel(round(X), round(Y),RED); // colaca pixel em (X,Y) com cor vermelha
        X += 50; // incremento em x a cada passo
        Y += 50; // incremento em y a cada passo
         // tempo
    }
}
//////////////////////////////////////////////////////////////////////////////
//------------------BRESENHAM------------------
///////////////////////////////////////////////////////////////////////////
void Bresenham(int x0, int y0, int x1, int y1){
    int dx, dy, p, x, y;
    
	dx=x1-x0;
	dy=y1-y0;

	x=x0;
	y=y0;
 
p=2*dy-dx;
 /// ENQUANTO X MENOR QUE X1
while(x<x1){
  if(p>=0){
    putpixel(x,y,RED);
	y=y+1;
	p=p+2*dy-2*dx;
	
}else{
	putpixel(x,y,RED);
	p=p+2*dy;
	}
   x=x+1;
}
}



  /////////////// vertical ////////////////
void vertical(){
int y, x, valorx1, valorx2, valory1, valory2, m, b;
	int numeroDeLinhas = 0;
	int total = 0;
    valorx1= 0;
    valorx2=0;
	valory1=0;
	valory2= 800;
	// for com o numero de linhas
	for(numeroDeLinhas = 0; numeroDeLinhas <= 12; numeroDeLinhas++){
		for(y = valory1; y < valory2 ;y++)
			putpixel(valorx1,YMAX-y,RED);
			
	total = total + 50;
	valorx2 = total;
	valorx1= valorx2;
	valory2= 800;
	valory1=0;
    }
}
 ///////////////// horizontal ////////////////////////////////
 void horizontal(){
  
  	int y, x, valorx1, valorx2, valory1, valory2, m, b;
	int numeroDeLinhas = 0;
	int total = 0;
	valorx1= 0;
	valorx2= 600;
	valory1=0;
	valory2= 0;
		// for com o numero de linhas
	for(numeroDeLinhas = 0; numeroDeLinhas <= 10; numeroDeLinhas++){
		
		m = (valory2-valory1)/(valorx2-valorx1);
		b = valory2 - m*valorx2;
		for(x = valorx1; x < valorx2; x++){
			y = m*x + b;
			putpixel(x,YMAX-y,1);
		}
	total = total + 50;
	valory2 = total;
	valorx1= 0;
	valorx2= 600;
	valory1=0;

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
	valorx1= 0;
	valorx2= 600;
	valory1=0;
	valory2= 0;
		// for com o numero de linhas
	for(numeroDeLinhas = 0; numeroDeLinhas <= 10; numeroDeLinhas++){
		
		m = (valory2-valory1)/(valorx2-valorx1);
		b = valory2 - m*valorx2;
		for(x = valorx1; x < valorx2; x++){
			y = m*x + b;
			putpixel(x,YMAX-y,1);
		}
	total = total + 50;
	valory2 = total;
	valorx1= 0;
	valorx2= 600;
	valory1=0;

    }
    
    /////////////// vertical ////////////////
    
	numeroDeLinhas = 0;
    total = 0;
    valorx1= 0;
    valorx2=0;
	valory1=0;
	valory2= 800;
	// for com o numero de linhas
	for(numeroDeLinhas = 0; numeroDeLinhas <= 12; numeroDeLinhas++){
		for(y = valory1; y < valory2 ;y++)
			putpixel(valorx1,YMAX-y,1);
			
	total = total + 50;
	valorx2 = total;
	valorx1= valorx2;
	valory2= 800;
	valory1=0;
    }  
}


