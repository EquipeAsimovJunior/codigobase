/*
 * leituraserial.h
 *
 *  Created on: 02/07/2019
 *      Author: ev3
 */

#ifndef SRC_LEITURASERIAL_H_
#define SRC_LEITURASERIAL_H_

#include "serial.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
Serial serial("/dev/ttyUSB0" , 115200);
int posicaoServo;
int frente, direita, esquerda, tras, cdireita, cesquerda, posicao, distradar;
string heinViado;
string distt;

void tudoSerialResgate(int sfrente, int ssep, int sservo, int scac){

	std::string pos1;
	std::string pos2;
	std::string pos3;
	std::string pos4;
	std::stringstream s1;
	std::stringstream s2;
	std::stringstream s3;
	std::stringstream s4;
	s1 << sfrente;
	s2 << ssep;
	s3 << sservo;
	s4 << scac;

	pos1 = s1.str();
	pos2 = s2.str();
	pos3 = s3.str();
	pos4 = s4.str();

	heinViado = "r;"+pos1+";"+pos2+";"+pos3+";"+pos4+"#";
	serial.envia(heinViado);
	distt = serial.recebeAteCaractere('\n');
	serial.limpaBuffer();
	sscanf(distt.c_str(),"%d;%d;%d;%d;%d",&frente,&direita,&esquerda,&posicao,&distradar);
}

void tudoSerialResgate2(int sfrente, int ssep, int sservo, int scac){

	std::string pos1;
	std::string pos2;
	std::string pos3;
	std::string pos4;
	std::stringstream s1;
	std::stringstream s2;
	std::stringstream s3;
	std::stringstream s4;
	s1 << sfrente;
	s2 << ssep;
	s3 << sservo;
	s4 << scac;

	pos1 = s1.str();
	pos2 = s2.str();
	pos3 = s3.str();
	pos4 = s4.str();

	heinViado = "t;"+pos1+";"+pos2+";"+pos3+";"+pos4+"#";
	serial.envia(heinViado);
	distt = serial.recebeAteCaractere('\n');
	serial.limpaBuffer();
	sscanf(distt.c_str(),"%d;%d;%d;%d;%d",&frente,&direita,&esquerda,&posicao,&distradar);
}

void tudoSerialLinha(int sfrente){
	std::string pos1;
	std::stringstream s1;
	s1 << sfrente;
	pos1 = s1.str();

	heinViado = "l;"+pos1+"#";
	serial.envia(heinViado);
	distt = serial.recebeAteCaractere('\n');
	sscanf(distt.c_str(),"%d;%d;%d",&frente,&cdireita,&cesquerda);
}



#endif /* SRC_LEITURASERIAL_H_ */
