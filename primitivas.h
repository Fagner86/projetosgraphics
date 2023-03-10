

using namespace std;
int p1[2], p2[2],p3[2],XMAX,YMAX;

//------------------MENU------------------
void menu(){
    cout << "----------------- MENU -----------------" << endl;
    cout << "[0] LIMPAR TELA" << endl;//OK
    cout << "[1] CONSTRUCAO DE CIRCULOS: Algoritmo da Equacao Parametrica" << endl;//OK
    cout << "[2] CONSTRUCAO DE CIRCULOS: Algoritmo do ponto medio" << endl;//OK
  	cout << "[3] CONSTRUCAO DE CIRCULOS: o preenchimento do circulo" << endl;//OK 
   	cout << "[4] CONSTRUCAO E PREENCHIMENTO DE ELIPSES." << endl;//OK 
   	cout << "[5] PREENCHIMENTO DE POLIGONOS" << endl;//OK 
    cout << "[6] SAIR" << endl; //OK
    cout << "----------------------------------------" << endl;
}

void CirculoParametrica()
{
// Definir as variáveis
 int y, x, x_centro, y_centro, raio;
 float angulo, pi= 3.14159265359;
 
 
//Definir as coordenadas do centro do círculo e raio
     x_centro = 200;
     y_centro = 200;
     raio = 50;
     

x = raio;
y = 0;

//laço para desenhar os pontos
for (angulo = 1;angulo < 360; angulo = angulo + 0.1)
{
putpixel(x + x_centro , y + y_centro, RED);
x = raio * cos(pi * angulo / 180);
y = raio * sin(pi * angulo / 180);
}
}

void CirculoPontoMedio(){
//Definir as coordenadas do centro da circunferência e seu raio
    int x_centro = 200;
    int y_centro = 200;
    int raio = 50;
///Definir variáveis para os pontos inicial e final da circunferência e calcular o valor inicial do ponto médio:
    int x = 0;
    int y = raio;
    int p = 1 - raio;

//Definir um laço para desenhar pontos ao longo da circunferência usando o algoritmo do ponto médio:
    while (x <= y) {
        putpixel(x_centro + x, y_centro + y, WHITE);
        putpixel(x_centro - x, y_centro + y, WHITE);
        putpixel(x_centro + x, y_centro - y, WHITE);
        putpixel(x_centro - x, y_centro - y, WHITE);
        putpixel(x_centro + y, y_centro + x, WHITE);
        putpixel(x_centro - y, y_centro + x, WHITE);
        putpixel(x_centro + y, y_centro - x, WHITE);
        putpixel(x_centro - y, y_centro - x, WHITE);

        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

}
void PreenchimentoDoCirculo(){
    int x_centro = 200;
    int y_centro = 200;
    int raio = 50;

    // desenha o círculo
    int x = 0, y = raio;
    int d = 1 - raio;
    while (x <= y) {
        putpixel(x_centro + x, y_centro + y, WHITE);
        putpixel(x_centro - x, y_centro + y, WHITE);
        putpixel(x_centro + x, y_centro - y, WHITE);
        putpixel(x_centro - x, y_centro - y, WHITE);
        putpixel(x_centro + y, y_centro + x, WHITE);
        putpixel(x_centro - y, y_centro + x, WHITE);
        putpixel(x_centro + y, y_centro - x, WHITE);
        putpixel(x_centro - y, y_centro - x, WHITE);

        if (d < 0) {
            d = d + 2 * x + 3;
        } else {
            d = d + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

       // Varre cada linha horizontal do círculo
    int x_center = 200;
    int y_center= 200;
	int radius = 50;
	 int color =  WHITE;
    for (y = y_center - radius; y <= y_center + radius; y++)
    {
        // Determina as coordenadas x dos pontos de interseção da linha de varredura com o círculo
        int x_left = x_center - sqrt(radius * radius - (y - y_center) * (y - y_center));
        int x_right = x_center + sqrt(radius * radius - (y - y_center) * (y - y_center));

        // Pinta as áreas da linha de varredura que estão dentro do círculo
        for ( x = x_left; x <= x_right; x++)
        {
            putpixel(x, y, color);
        }
    }
}

void ConstrucaoPreenchimentoElipses(int xc, int yc, int rx, int ry) {
  int x = 0, y = ry;
  int rx2 = rx * rx, ry2 = ry * ry;
  int p = ry2 - rx2 * ry + rx2 / 4;
  
  // Desenha e preenche a parte superior da elipse
  while (2 * ry2 * x <= 2 * rx2 * y) {
    // Desenha as linhas superior e inferior da elipse
    putpixel(xc + x, yc + y, GREEN);
    putpixel(xc - x, yc + y, GREEN);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, GREEN);
  
    // Preenche a linha horizontal correspondente à elipse
    for (int i = xc - x; i <= xc + x; i++) {
      putpixel(i, yc + y, GREEN);
      putpixel(i, yc - y, GREEN);
    
    }

    if (p < 0) {
      x++;
      p += 2 * ry2 * x + ry2;
    } else {
      x++;
      y--;
      p += 2 * ry2 * x - 2 * rx2 * y + ry2;
    }
  }

  p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
  
  // Desenha e preenche a parte inferior da elipse
  while (y >= 0) {
    // Desenha as linhas superior e inferior da elipse
    putpixel(xc + x, yc + y, GREEN);
    putpixel(xc - x, yc + y, GREEN);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, GREEN);

    // Preenche a linha horizontal correspondente à elipse
    for (int i = xc - x; i <= xc + x; i++) {
      putpixel(i, yc + y, GREEN);
      putpixel(i, yc - y, GREEN);
      
    }

    if (p > 0) {
      y--;
      p -= 2 * rx2 * y + rx2;
    } else {
      y--;
      x++;
      p += 2 * ry2 * x - 2 * rx2 * y + rx2;
    }
  }
}

// Função para verificar se um ponto está dentro do polígono
bool pontoDentroDoPoligono(int x, int y, int pontos[], int numPontos) {
    int intersecoes = 0;
    for (int i = 0; i < numPontos; i++) {
        int x1 = pontos[i*2];
        int y1 = pontos[i*2+1];
        int x2 = pontos[(i*2+2) % (numPontos*2)];
        int y2 = pontos[(i*2+3) % (numPontos*2)];
        // Verifique se o segmento de reta cruza a linha horizontal que passa pelo ponto (x, y)
        if (((y1 <= y) && (y2 > y)) || ((y2 <= y) && (y1 > y))) {
            // Calcule a coordenada x da interseção entre o segmento de reta e a linha horizontal
            double intersecao = (double)(y - y1) * (double)(x2 - x1) / (double)(y2 - y1) + x1;
            // Se a coordenada x da interseção é maior que a coordenada x do ponto, o segmento de reta cruza a linha vertical que passa pelo ponto (x, y)
            if (x < intersecao) {
                intersecoes++;
            }
        }
    }
    // Se o número de interseções é ímpar, o ponto está dentro do polígono
    return (intersecoes % 2 != 0);
}

// Função para preencher o polígono com a cor especificada
void PreenchimentoDePoligonosQuaisquer() {
	// Defina os pontos do polígono côncavo
	//caso previse mudar o poligono so trocar por alguma opcao abaixo comentada
    // 100, 100,200, 50, 300, 100, 300, 300, 200, 250, 100, 300 
    //100,100, 200,100, 200,200, 150,150, 100,200
    //100, 100, 300, 100, 300, 300, 200, 250, 100, 300 
    //100, 100, 300, 100, 200, 300,200, 200,100, 300 
    //50, 250, 100, 150, 250, 150, 300, 250, 200, 300, 150, 250
    //100, 50, 150, 100, 175, 75, 200, 100, 250, 50, 200, 150, 200, 200, 175, 175, 150, 200, 100, 150
    int pontos[] = {100, 50, 150, 100, 200, 50, 200, 150, 100, 150 };
	int numPontos = 5;

	// Desenhe o polígono na tela
	setcolor(WHITE);
	drawpoly(numPontos, pontos);

    int minX = pontos[0];
    int maxX = pontos[0];
    int minY = pontos[1];
    int maxY = pontos[1];
    // Encontre as coordenadas mínimas e máximas do polígono para limitar a área de preenchimento
    for (int i = 0; i < numPontos; i++) {
        if (pontos[i*2] < minX) minX = pontos[i*2];
        if (pontos[i*2] > maxX) maxX = pontos[i*2];
        if (pontos[i*2+1] < minY) minY = pontos[i*2+1];
        if (pontos[i*2+1] > maxY) maxY = pontos[i*2+1];
    }
    // Preencha a área dentro do polígono com a cor especificada
    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (pontoDentroDoPoligono(x, y, pontos, numPontos)) {
                putpixel(x, y, GREEN);
            }
        }
    }
}
