#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup()
{
	//definicoes padrao do player
	player.posicao.x = 0;
	player.posicao.y = 20;
	player.tamanho = player.sprite.getHeight();
	player.sprite.loadImage("players/Jogador.png");
	player.sprite.setAnchorPoint(player.sprite.getWidth() / 2, player.sprite.getHeight() / 2);
	player.vel = 0.5f;

	//definicoes padrao do inimigo
	inimigo.posicao.x = 400;
	inimigo.posicao.y = 50;
	inimigo.sprite.loadImage("players/Player.png");
	inimigo.sprite.setAnchorPoint(inimigo.sprite.getWidth() / 2, inimigo.sprite.getHeight() / 2);
	inimigo.vel = 0.5f;

	//definicoes do chao
	chao.posiscao.x = 80;
	chao.posiscao.y = 500;
	chao.tamanho = chao.sprite.getHeight() /2;
	chao.tamanhoObj.x = 1000;
	chao.tamanhoObj.y = 300;
	chao.sprite.loadImage("players/chao.png");
	chao.sprite.setAnchorPoint(chao.sprite.getWidth() / 2, chao.sprite.getHeight() / 2);
	//definicios do chao2
	/*chao2.posiscao.x = 400;
	chao2.posiscao.y = 500;
	chao2.tamanho = chao.sprite.getHeight() / 2;
	chao2.tamanhoObj.x = 700;
	chao2.tamanhoObj.y = 400;
	chao2.sprite.loadImage("players/chao.png");
	chao2.sprite.setAnchorPoint(chao.sprite.getWidth() / 2, chao.sprite.getHeight() / 2);*/
	
	//definicoes de camera, deve ser definida no setup e no update
	mundo = player.posicao;
	mundo = inimigo.posicao;
	mundo = chao.posiscao;
	//mundo = chao2.posiscao;

	
}

//--------------------------------------------------------------
void ofApp::update()
{	
	

	//pegando tempo para usar na movimentação
	double time = ofGetLastFrameTime();

	//setando as posicoes x e y mais a velocidade multiplicada pelo tempo
	player.posicao += player.vel * time;
	

	//se a tecla for pressionada o player moviemnta
	if (player.Up == true)
	{
		player.posicao.y -= player.vel;
	}
	if (player.Down == true)
	{
		player.posicao.y += player.vel;
	}
	if (player.Left == true)
	{
		player.posicao.x -= player.vel;
	}
	if (player.Right == true)
	{
		player.posicao.x += player.vel;
	}

	//movimentacao com scroll de tela, que na verdade ja esta definida ali em cima
	/*if (player.Up == true)
	{
		mundo.y += player.vel * time;
	}
	if (player.Down == true)
	{
		mundo.y -=  player.vel* time;
	}
	if (player.Left == true)
	{
		mundo.x += player.vel* time;
	}
	if (player.Right == true)
	{
		mundo.x -= player.vel* time;
	}*/

	//parametros da camera(QUALQUER OBJETO COLOCADO NA CENA DEVE SER SETADO PELA CAMERA)
	mundo = player.posicao;
	mundo = chao.posiscao;
	mundo = inimigo.posicao;
	//mundo = chao2.posiscao;

	
	//COLISAO (acontece, mas ela está em circulo, e não sei como arrumar isso
	//a colisao não acompanha a imagem, ela esta setada no ponto fixo da posicao do chao
	// eu nao sei como arrumar)
	if (player.posicao.distance(chao.posiscao) < 430) 
	{
		player.posicao.y -= 0.5;
	}
	if (player.posicao.distance(inimigo.posicao) < 100)
	{
		player.posicao.y -= 0.5;
	}
	/*if (player.posicao.distance(chao2.posiscao) < 430)
	{
		player.posicao.y -= 0.5;
	}*/
	
	/*//copy the circle center to a new point (this changes so there needs to be a copy)

Point pt = circle.center;


    //point on rectangle closest to circle 
    //(snaps the point to the rectangle, pretty much, 
    //if the circle center is inside the rectangle there isn't snapping, 
    //but this is fine since it will detect a collision as a result)

if(player.posicao.x >  chao.tamanhoObj.x) player.posicao.x =  chao.tamanhoObj.x;
if(player.posicao.x <  chao.tamanhoObj.x) player.posicao.x =  chao.tamanhoObj.x;
if(player.posicao.y > chao.tamanhoObj.y) player.posicao.y = chao.tamanhoObj.y;
if(player.posicao.y <  chao.tamanhoObj.y) player.posicao.y =  chao.tamanhoObj.y;


    //distance check, just use distance^2 for actual implementation

if(distance(player.posicao, circle.center) < circle.radius) return true;
return false;*/ 
//tentativa de colisao que nao deu
}

//FUNCAO DESENHO QUE RECEBE A STRUCT E TEM SEUS PARAMETROS DENTRO
void ofApp::drawNatela(personagem& objeto)
{
	//FUNÇAO DE TAMANHO DOS SPRITES PARA DESENHAR
	ofVec2f hwindow(ofGetWindowWidth(), ofGetWindowHeight());
	hwindow /= 2;
	ofVec2f finalPos = objeto.posicao - mundo + hwindow;

	objeto.sprite.draw
	(finalPos.x, finalPos.y, player.tamanho);

	
}

//--------------------------------------------------------------

void ofApp::draw()
{
	drawNatela(player);
	drawNatela(inimigo);
	chao.sprite.draw(chao.posiscao.x , chao.posiscao.y, chao.tamanhoObj.x + chao.tamanho, chao.tamanhoObj.y + chao.tamanho);
	
	ofDrawBitmapString("Posicao do player: " + ofToString(player.posicao), 10, 10);
	ofDrawBitmapString("Posicao do chao: " + ofToString(chao.posiscao), 10, 30);
	ofDrawBitmapString("Tamanho do chao: " + ofToString(chao.tamanhoObj), 10,50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	//se a tecla estiver sendo pressionada, movimenta
	if (key == OF_KEY_UP || key == 'w')
	{
		player.Up = true;
	}
	if (key == OF_KEY_DOWN || key == 's')
	{
		player.Down = true;
	}
	if (key == OF_KEY_RIGHT || key == 'd')
	{
		player.Right = true;
	}
	if (key == OF_KEY_LEFT || key == 'a')
	{
		player.Left = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	//se a telca não estiver sendo pressionada, para movimento
	if (key == OF_KEY_UP || key == 'w')
	{
		player.Up = false;  
	}
	if (key == OF_KEY_DOWN || key == 's')
	{
		player.Down = false;
	}
	if (key == OF_KEY_RIGHT || key == 'd')
	{
		player.Right = false;
	}
	if (key == OF_KEY_LEFT || key == 'a')
	{
		player.Left = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
