

using namespace std;

int XMAX,YMAX;

void menu(){
    cout << "----------------- MENU -----------------" << endl;
    cout << "[0] Limpar Tela" << endl;//OK
    cout << "[1] Desenha triangulo" << endl;//OK
    cout << "[2] Escala" << endl;//OK
    cout << "[3] Rotacao " << endl; //OK
    cout << "[4] Translatacao " << endl; //OK
    cout << "[5] Espelhamento" << endl;
    cout << "[6] Escala_fixa" << endl;
    cout << "[7] Rotacao_fixa" << endl;
    cout << "[8] Sair" << endl;
    cout << "----------------------------------------" << endl;
}


void Escala(int x0,int xf, int y0,int yf,int ce){
		
		int auxx0,auxxf,auxy0,auxyf,alt,larg,auxce;
		
		auxx0=x0*ce;
		auxxf=xf*ce;
		auxy0=y0*ce;
		auxyf=yf*ce;
		alt=alt;
		larg=larg;
		
		line(round(auxx0+alt/2), round(larg/2-auxy0), round(auxxf+alt/2), -round(larg/2-auxyf));	
}

void Rotacao(int x0,int xf, int y0,int yf,double angulo) {
	
	int auxx0,auxxf,auxy0,auxyf,alt,larg;
	
    auxx0= (x0*cos(angulo)-y0*sin(angulo));
	auxy0=(x0*sin(angulo)+y0*cos(angulo));
	auxxf= (xf*cos(angulo)-yf*sin(angulo));
	auxyf=(xf*sin(angulo)+yf*cos(angulo));
    alt=alt;
    larg=larg;
	

	line( round(auxx0+alt/2), round(larg/2-auxy0), round(auxxf+alt/2), round(larg/2-auxyf));
}
 void Translatacao(int x0,int xf, int y0,int yf,int tx,int ty) {
	int auxx0,auxxf,auxy0,auxyf,alt,larg,auxce;
	
	auxx0=x0+tx;
	auxxf=xf+tx;
	auxy0=y0+ty;
	auxyf=yf+ty;
	alt=alt;
	larg=larg;

	
	line( round(auxx0+alt/2), round(larg/2-auxy0), round(auxxf+alt/2), round(larg/2-auxyf));
}

void espelhamento(int x0,int xf, int y0,int yf){
	
	int auxx0,auxxf,auxy0,auxyf,alt,larg;
	

	auxx0=x0;
	auxxf=xf;
	auxy0=-y0;
	auxyf=-yf;
	alt=alt;
	larg=larg;
	
	line(round(auxx0+alt/2), round(larg/2-auxy0), round(auxxf+alt/2), round(larg/2-auxyf));
}

void Escala_fixa(int x0,int xf, int y0,int yf,int ce){
	
	int auxx0,auxxf,auxy0,auxyf,alt,larg,auxce;
	
	auxx0=x0*ce+55*(1-ce);
	auxxf=xf*ce+55*(1-ce);
	auxy0=y0*ce+65*(1-ce);
	auxyf=yf*ce+65*(1-ce);
	alt=alt;
	larg=larg;

	
    line( round(auxx0+alt/2+55), round(larg/2-auxy0+65), round(auxxf+alt/2+55), round(larg/2-auxyf+65));
			  }

void Rotacao_fixa(int x0,int xf, int y0,int yf,double angulo) {

	int auxx0,auxxf,auxy0,auxyf,alt,larg;
	
	auxx0=(x0*cos(angulo)-y0*sin(angulo));
	auxy0=(x0*sin(angulo)+y0*cos(angulo));
	auxxf=(xf*cos(angulo)-yf*sin(angulo));
	auxyf=(xf*sin(angulo)+yf*cos(angulo));
	auxx0=auxx0+55;
	auxxf=auxxf+55;
	auxy0=auxy0+65;
	auxyf=auxyf+65;
	alt=alt;
	larg=larg;

	
	line( round(auxx0+alt/2), round(larg/2-auxy0), round(auxxf+alt/2), round(larg/2-auxyf));
}






void Triangulo(float xpt1, float ypt1, float xpt2, float ypt2, float xpt3, float ypt3)
 {
 int dx,dy, valor;
 float pontoX1, pontoX2,pontoX3,pontoY1,pontoY2,pontoY3, Xincremento, Yincremento, X, Y;
 
 pontoX1 = xpt1;
 pontoX2 = xpt2;
 pontoY1 = ypt1;
 pontoY2 = ypt2;
 pontoX3 = xpt3;
 pontoY3 = ypt3;
 
  ////////// linha um //////////
    // calcula dx e dy
    dx = pontoX2- pontoX1;
    dy = pontoY2- pontoY1;
 // saber se continua com o valor de dy ou dx
    if (abs(dx) > abs(dy))
        valor = abs(dx);
    else
        valor = abs(dy);
 
    // calcular o incremento em x e y para cada passo
    Xincremento = dx / (float)valor;
    Yincremento = dy / (float)valor;
 
    // coloca pixel para cada etapa
    X = pontoX1;
    Y = pontoY1;
    for (int i = 0; i <= valor; i++) {
        putpixel(round(X), round(Y),RED); // colaca pixel em (X,Y) com cor vermelha
        X +=  Xincremento; // incremento em x a cada passo
        Y += Yincremento; // incremento em y a cada passo
         // tempo
    }
    
    /////////////////// Linha dois ///////////
      // calcula dx e dy
    dx = pontoX3- pontoX2;
    dy = pontoY3- pontoY2;
 // saber se continua com o valor de dy ou dx
    if (abs(dx) > abs(dy))
        valor = abs(dx);
    else
        valor = abs(dy);
 
    // calcular o incremento em x e y para cada passo
    Xincremento = dx / (float)valor;
    Yincremento = dy / (float)valor;
 
    // coloca pixel para cada etapa
    X = pontoX2;
    Y = pontoY2;
    for (int i = 0; i <= valor; i++) {
        putpixel(round(X), round(Y),RED); // colaca pixel em (X,Y) com cor vermelha
        X +=  Xincremento; // incremento em x a cada passo
        Y += Yincremento; // incremento em y a cada passo
         // tempo
    }
    
 //////////////////////   Linha tres ///////////
      // calcula dx e dy
    dx = pontoX3- pontoX1;
    dy = pontoY3- pontoY1;
 // saber se continua com o valor de dy ou dx
    if (abs(dx) > abs(dy))
        valor = abs(dx);
    else
        valor = abs(dy);
 
    // calcular o incremento em x e y para cada passo
    Xincremento = dx / (float)valor;
    Yincremento = dy / (float)valor;
 
    // coloca pixel para cada etapa
    X = pontoX1;
    Y = pontoY1;
    for (int i = 0; i <= valor; i++) {
        putpixel(round(X), round(Y),RED); // colaca pixel em (X,Y) com cor vermelha
        X +=  Xincremento; // incremento em x a cada passo
        Y += Yincremento; // incremento em y a cada passo
         // tempo
    }
}
