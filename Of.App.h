#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		//vetor da camera
		ofVec2f mundo;

		//personagem completo
		struct personagem
		{
			
			
			ofVec2f posicao;
			float tamanho;
			ofImage sprite;
			float vel, acele;
			bool Up = false; bool Down = false; bool Right = false; bool Left = false;
		};

		personagem player;
		personagem inimigo;

		struct obstaculos
		{
			//no caso posicao x e y do objeto
			ofVec2f posiscao;
			//no caso tamanho x e y do objeto
			ofVec2f tamanhoObj;
			float tamanho;
			ofImage sprite;
		};
		obstaculos chao, chao2;

		void drawNatela(personagem& objeto);
};
