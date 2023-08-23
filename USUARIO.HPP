#ifndef USUARIO_HPP_INCLUDED
#define USUARIO_HPP_INCLUDED

using namespace std;

class User {
    private:
        int id;
        string nome;
        string email;
        string password;
        string biografia;
    public:
    // setters
        void setID(int x);
        void setNome();
        void setEmail();
        void setPassword();
        void setBio();

    // getters
        int getID() { return id; }
        string getNome() { return nome; }
        string getEmail() { return email; } 
        string getPassword() { return password; }
        string getBio() { return biografia; }
        
};

// Implementacao dos metodos setters
    void User::setID(int x) {
        id = x;
    }

    void User::setNome() {
        cout << "Nome: ";
        cin >> nome;
    }

    void User::setEmail() {
        cout << "Email: ";
        cin >> email;
    }

    void User::setPassword() {
        cout << "Password: ";
        cin >> password;
    }

    void User::setBio() {
        cout << "Biografia: ";
        fflush(stdin);
        getline(cin,biografia);
    }

#endif