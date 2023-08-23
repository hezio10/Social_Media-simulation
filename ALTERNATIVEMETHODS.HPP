#ifndef ALTERNATIVEMETHODS_HPP_INCLUDE
#define ALTERNATIVEMETHODS_HPP_INCLUDE

using namespace std;


int menuEntrada() {
     int opc;
     cout << "================Menu de entrada===============\n";
     cout << "[1].Sign In"
         << "\n[2].Log In"
         << "\n::: ";
     cin >> opc;

    return opc;
}

int menuPrincipal() {
     int opc;
     cout << "================Minha Conta=============\n";
     cout << "[1].Meu Perfil" 
          << "\n[2].Ver Feed" 
          << "\n[3].Ver Notificacoes" 
          << "\n[4].Fazer Post"
          << "\n[0].Sair" 
          << "\n ::: ";
     cin  >> opc;

    return opc;
}

int menuPerfil() {
     int opc;
    cout << "\n[1].Ver lista de amigos"
         << "\n[2].Ver sugestoes de amizades"
         << "\n[0].Sair"
         << "\n::: ";
    cin >> opc;

    return opc;
}

int menuPedido() {
     int opc;
    cout << "\n[1].Fazer Pedido"
         << "\n[0].Sair"
         << "\n::: ";
    cin >> opc;

    return opc;
}
int menuAceitarRecusar() {
     int opc;
    cout << "[1].Aceitar Pedido"
         << "[2].Recusar Pedido"
         << "\n[0].Sair"
         << "\n::: ";
    cin >> opc;

    return opc;
}

#endif