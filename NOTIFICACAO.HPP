#ifndef NOTIFICACAO_HPP_INCLUDED
#define NOTIFICACAO_HPP_INCLUDED
#include "POST.HPP"
#include "AMIZADE.HPP"

using namespace std;

class Notificacao : public Post, public Amizade {
    private:
        string info;
        string remetente;
    public:

        void setInfo(string x);
        void setRemetente(string x);

        string getInfo() { return info; }
        string getRemetente() { return  remetente; }
        
       
};

void Notificacao::setInfo (string x) {
    info = x;
}

void Notificacao::setRemetente(string x) {
    remetente = x;
}





#endif