#!/bin/bash
#variaveis! devem ser alteradas de acordo com o nome do projeto
#ATENCAO PARA O IP, VERIFICAR SE É MESMO O DO BRICK
#ATENCAO DEIXEI APENAS UMA DAS TRES LINHAS SEM COMENTARIO
#ip_ev3=10.42.0.3 #bluetooth
ip_ev3=192.168.0.1 #USB
#ip_ev3=192.168.2.121 #wifi
killall scp
#CRIO MINHAS VARIAVEIS NECESSARIAS
aux=$(pwd | grep -o '/' | wc -l)
nome_projeto=$(pwd | cut -d '/' -f $(($aux+1)))
cd ..
echo "Enviando o arquivo \"$nome_projeto\" para o EV3..." 
echo "Se demorar muito, seu EV3 pode não estar conectado."
scp -C "/home/$USER/$nome_projeto/Release/$nome_projeto" robot@$ip_ev3:~
if [ $? -eq 0 ]; then
	echo "Envio concluido"
else
	echo "Erro no envio"
fi