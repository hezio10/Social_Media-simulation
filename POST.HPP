#ifndef POST_HPP_INCLUDED
#define POST_HPP_INCLUDED

using namespace std;

class Post :virtual public User {
    private:
        string autor;
        string content;
        string dataDeCriacao;

    public:
        time_t t;
        struct tm tempo;
    // setters
        void setAutor(string x);
        void setContent();
        void setTempo();
        void setDAtaDeCriacao();

    // getters
        string getAutor() { return autor; }
        string getContent() { return content; }
        struct tm getTempo() { return tempo; }
        string getDAtaDeCriacao() { return dataDeCriacao; }

    // metodos
       
       
        
};
// cout << "Data: " << historico->getEntryTime().tm_mday << "/ " << historico->getEntryTime().tm_mon << "/ " << historico->getEntryTime().tm_year + 1900;


// Implementacao dos metodos setters
    void Post::setAutor(string x) {
        autor = x;
    }

    void Post::setContent() {
        cout << "Conteudo do post: \n";
        fflush(stdin);
        getline(cin,content);
    }

    void Post::setTempo() {
        time(&t);
		struct tm *tempoInsert = localtime(&t);
		tempo = *tempoInsert;
    }

    
   

    

   
#endif