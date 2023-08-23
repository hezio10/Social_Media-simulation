#ifndef AMIZADE_HPP_INCLUDED
#define AMIZADE_HPP_INCLUDED
#include "USUARIO.HPP"

using namespace std;

class Amizade : virtual public User{
    public:
        vector<User*> amigos;
        vector<User*> pedidosPendentes;

    public:
        
};

// Implementacao dos metodos
     

     

    
#endif