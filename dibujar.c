#include "paridad.h"
	
	void dibujar(){
		
		initwindow(600, 500);
		settextstyle(3, HORIZ_DIR, 2);
		
		//TEXTOS
		setcolor(15);
		setbkcolor(COLOR(0,122,255));
		outtextxy(150, 100, "q0");
		outtextxy(410, 102, "q1");
		outtextxy(150, 320, "q2");
		setbkcolor(COLOR(255, 204,0));
		setcolor(0);
		outtextxy(410, 320, "q3");
		
		//ARCOS CONECTORES
		setcolor(15);
		
		arc(290, 225, 0, 360, 160);//q0-q1
		
		//Superior
		arc(290, 450, 45, 135, 160);//q2-q3 
		//Inferior
		arc(290, 0, 225, 315, 160); //q0-q1
		//Izquierdo
		arc(40,220, 0, 45, 160);
		arc(40,220, 315, 360, 160);
		//derecho
		arc(540, 220, 135, 225, 160);
		arc(540,220, 180, 225, 160);
		
		
		//CIRCULOS
		setfillstyle(1, COLOR(0, 122, 255)); //AZUL
		setcolor(COLOR(0,122,255));			//AZUL DEL CONTORNO
		fillellipse(420, 330, 40, 40); //q3
		fillellipse(420, 110, 40, 40); //q1
		fillellipse(160, 330, 40, 40); //q2
		setfillstyle(1, COLOR(255, 204, 0)); //Amarillo
		setcolor(COLOR(255,204,0)); 		 //Amarillo del contorno
		fillellipse(160, 110, 40, 40); //q0
		circle(160,110, 45);
		
		//TEXTOS
		setcolor(15);
		setbkcolor(COLOR(0,122,255));
		outtextxy(410, 320, "q3");
		outtextxy(409, 92, "q1");
		outtextxy(148, 320, "q2");
		setbkcolor(COLOR(255,204,0));
		setcolor(0);
		outtextxy(150, 98, "q0");	

		//TEXTOS DE ARCOS CONECTORES
		setcolor(COLOR(0,122,255));
		setbkcolor(0);
		outtextxy(285, 40, "0"); //0 de q0 a q1
		outtextxy(285, 168, "0"); //0 de q1 a q0
		outtextxy(360, 215, "1"); //De q1 a q3
		outtextxy(460, 215, "1"); //De q3 a q1	
		outtextxy(100, 215, "1"); //De q0 a q1
		outtextxy(215, 215, "1"); //De q1 a q0
		outtextxy(285, 255, "0"); //De q2  a q3
		outtextxy(285, 390, "0"); //0 de q2 a q3
		
		//Flechas Conectoras
		setcolor(COLOR(255,204,0));
		outtextxy(373 , 80, "v");//q0 a q1
		outtextxy(199 , 305, "v");//q2 a q3
		outtextxy(392 , 273, "v");//q1 a q3	
		outtextxy(428 , 148, "^");//q3 a q1
		outtextxy(141 , 150, "^");//q2 a q0
		outtextxy(197 , 124, "^");//q1 a q0
		outtextxy(378 , 348, "^");//q2 a q3	
		outtextxy(180 , 274, "v");//q0 a q2	
	
		//Texto
		outtextxy(82, 430, "Diagrama de transiciones de paridad de ceros y unos");	
		
		getch();

		closegraph();
	}
