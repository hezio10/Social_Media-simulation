#ifndef REDESOCIAL_HPP_INCLUDED
#define REDESOCIAL_HPP_INCLUDED
#include "ALTERNATIVEMETHODS.HPP"

using namespace std;

class RedeSocial : public Notificacao {
    public:
        Post posts[10];
        Notificacao notification[20], notific[20];
        static int quantPosts;
        int quantNotPed, quantNot;
        RedeSocial() { 
            quantPosts = 0;
            quantNotPed = 0;
            quantNot = 0;
        }
        int verPerfil();
        void signIn(int pos);
        static void clear() { system("cls"); }
        static bool logIn(RedeSocial users[], int quant, int *pos);
        void sugestoesAmizade(RedeSocial users[], int quant);
        static void verPosts(RedeSocial user[], int quant, string nome);

        void fazerPost(string nome, RedeSocial* user);
        void eliminarPost();
        void fazerPedido(RedeSocial* outroUser, string nome);
        void aceitarPedido(RedeSocial* solicitante);
        void recusarPedido(RedeSocial* solicitante);
        void notificar();
        void listaDeAmigos();

};

 int RedeSocial::quantPosts=0;

// Implementacao dos metodos
    void RedeSocial::signIn(int pos) {
        ofstream arquivo;
        setID(pos+1);
        setNome();
        setEmail();
        setPassword();
        setBio();
        arquivo.open("dataBase",ios::app);
        arquivo <<"\n"<< getID()
                <<"\n"<< getNome()
                <<"\n"<< getEmail()
                <<"\n"<< getPassword()
                <<"\n"<< getBio();
        arquivo.close();
    }

    bool RedeSocial::logIn(RedeSocial users[], int quant, int *pos) {
        string emailQ, senhaQ;
        bool result;
        int cont=0;

        cout << "Digite o email: ";
        cin >> emailQ;
        cout << "Digite a senha: ";
        cin >> senhaQ;

        for(int i=0; i<quant; i++) {
            if(users[i].getPassword() == senhaQ && users[i].getEmail() == emailQ) {
                cont = 1;
                *pos = i;
            }
        }
        if (cont=1) {
            result = true;
        } else {
            result = false;
        }

        return result;
    }

    int RedeSocial::verPerfil() {
        cout << "===============Perfil do usuario==============\n";
        cout << " Nome: " << getNome() << "\n";
        cout << " Amigos: " << amigos.size() << "\n";
        cout << " Biografia:\n" << getBio() << "\n";
        cout << "==============================================\n\n";

        return menuPerfil();
    }

     void RedeSocial::fazerPost(string nome, RedeSocial* user){
        ofstream arquivo;
        posts[quantPosts].setAutor(nome);
        posts[quantPosts].setContent();
        posts[quantPosts].setDAtaDeCriacao();

        arquivo.open("InfoPost", ios::app);
        arquivo  << "Autor:" << posts[quantPosts].getAutor()
                << "\n"<< "Content:" <<  posts[quantPosts].getContent()
                << "\n" << "Data de Criacao: " << getTempo().tm_mday << "/" << getTempo().tm_mon << "/n" << getTempo().tm_year;
        arquivo.close(); 
        quantPosts++;
        for(int i=0; i<amigos.size(); i++) {
            for(int k=0; k<amigos.size(); k++) {
                if((user+i)->getID()==amigos[k]->getID()) {
                    (user+i)->notific[quantNot].setRemetente(nome);
                    (user+i)->notific[quantNot].setInfo("Novo post de ");
                     quantNot++;
                }

            }

        }

        arquivo.open("NotPost", ios::app);
        arquivo << "\n" << getRemetente()
                << "\n" << getInfo();
        arquivo.close();
    }

     void RedeSocial::verPosts(RedeSocial user[], int quant, string nome) {
        int nr, nrUser, cont{0};
        string linha;
        ifstream arq;

        srand(time(0));
        cout << "Feed de noticias de " << nome << " :" << endl;
        if(RedeSocial::quantPosts == 0) {
            cout << "\nSem posts por enquanto.\n";
        } else {
            // for (int j=0; j<quant; j++) {
            //     nrUser = rand()%user->quantPosts;
            //     for(int i=0; i<user->quantPosts; i++){
            //         nr = rand()%user->quantPosts;
            //         cout << "Autor: " << user[j].posts[i].getAutor() << endl;
            //         cout << "Conteudo: " << user[j].posts[i].getContent() << endl;
            //         cout << "Data de criacao: " << user[j].posts[i].getDAtaDeCriacao() << endl;
            //     }
            // }
            arq.open("InfoPost", ios::app);
            if(arq.is_open()) {
                while(getline(arq,linha)) {
                    cout << linha << endl;
                    cont ++;
                    if (cont == 2) {
                        cout << "_________________________________________\n";
                    }
                }
            } else {
                cout <<"\nFalha ao abrir o arquivo!\n";
            }
        }
    }

    void RedeSocial::sugestoesAmizade(RedeSocial users[], int quant) {
        for(int i=0; i<quant; i++) {
            if(users[i].getID() != getID()) {
                for(int j=0; j<=amigos.size(); j++) { 
                    if (amigos.size() == 0) {
                        cout << "Nome: " << users[i].getNome() << "\n";
                        cout << "ID: " << users[i].getID() << "\n\n";

                    } else if (amigos[j]->getID() != users[i].getID()) {
                        cout << "Nome: " << users[i].getNome() << "\n";
                        cout << "ID: "  << users[i].getID() << "\n\n";   
                    
                    }
                }
            }
        }
        cout << "-_________________________________________________\n";
    }

    void RedeSocial::fazerPedido(RedeSocial* outroUser, string nome) {
        outroUser->pedidosPendentes.push_back(this);
        cout << " O seu pedido foi enviado.";

        outroUser->notification[quantNotPed].setRemetente(nome);
        outroUser->notification[quantNotPed].setInfo("Voce recebeu um pedido de amizade de ");
        cout << notification[quantNotPed].getInfo() << notification[quantNotPed].getRemetente() << "\n";
        quantNotPed++;
        
     }

     void RedeSocial::aceitarPedido(RedeSocial* solicitante) {
        solicitante->amigos.push_back(this);
        pedidosPendentes.erase(pedidosPendentes.begin());
        solicitante->notific[quantNot].setRemetente(solicitante->getNome());
        solicitante->notific[quantNot].setInfo("Cumprimente seu novo amigo, ");
        quantNot++;

     }

      void RedeSocial::recusarPedido(RedeSocial* solicitante) {
        pedidosPendentes.erase(pedidosPendentes.begin());
     }
// 
     void RedeSocial::listaDeAmigos() {
        if(amigos.size() == 0) {
            cout << "Sem amigos no momento!\nEspero que faca amigos logo.";
        } else {
            cout << "============Lista de Amigos=========\n\n";
            for(int i=0; i<amigos.size(); i++) {
                cout << amigos[i]->getNome() << "\n";
            }
        }
     }

   

    void RedeSocial::notificar( ) {
        if(quantNotPed==0) {
            cout << "Sem notificacoes novas no momento!";
        } else {
            cout << "========Pedidos de Amizade====================\n";
            for(int i=0; i<quantNotPed; i++) {
                cout << notification[i].getInfo() << notification[i].getRemetente() << "\n";
            }
            quantNotPed = 0;
            cout << "========Outras Notificacoes====================\n";
            for(int i=0; i<quantNotPed; i++) {
                cout << notific[i].getInfo() << notific[i].getRemetente() << "\n";
            }
            quantNot = 0;
        }
    }

#endif