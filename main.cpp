#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>
#include <functional>
#include "USUARIO.HPP"
#include "POST.HPP"
#include "AMIZADE.HPP"
#include "NOTIFICACAO.HPP"
#include "REDESOCIAL.HPP"
#include "ALTERNATIVEMETHODS.HPP"

using namespace std;

int main() {
    RedeSocial user[3],teste;
    int opc, quantUsers{0}, idUser;

    do {
        RedeSocial::clear();
        switch (menuEntrada()) {
            case 1:
                RedeSocial::clear();
                user[quantUsers].signIn(quantUsers);
                quantUsers++; 
                getch();
            break;   
            case 2:
                RedeSocial::clear();
                bool loginResult = RedeSocial::logIn(user,quantUsers,&idUser);
                if(loginResult == false){
                    cout << "Senha incorrecta. Tente Novamente!";
                } else {
                    RedeSocial::clear();
                    switch (menuPrincipal()) {
                        case 1:
                            RedeSocial::clear();
                            switch(user[idUser].verPerfil()) {
                                case 0:
                                break;
                                case 1:
                                    RedeSocial::clear();
                                    user[idUser].listaDeAmigos();
                                    getch();
                                break;
                                case 2:
                                    RedeSocial::clear();
                                    user[idUser].sugestoesAmizade(user, quantUsers);
                                    switch(menuPedido()) {
                                        case 0:

                                        break;
                                        case 1:
                                            int idPedido;
                                            cout << "ID do user a fazer o pedido: ";
                                            cin >> idPedido;
                                            user[idPedido-1].fazerPedido(&user[idUser],user[idUser].getNome());
                                            user[idPedido].aceitarPedido(&user[idUser]);
                                            getch();
                                        break;
                                    }
                                    getch();
                                break;
                            }
                            getch();
                        break;
                        case 2:
                            RedeSocial::clear();
                            user->verPosts(user,quantUsers,user[idUser].getNome());
                            getch();
                        break;
                        case 3:
                            RedeSocial::clear();
                            user[idUser].notificar();
                            getch();
                        break;
                        case 4:
                            RedeSocial::clear();
                            user[idUser].fazerPost(user[idUser].getNome(),user);
                            getch();
                        break;
                    }
                }
                
            break;
        }

       

    }while(opc!=0);
        

    return 0;
}