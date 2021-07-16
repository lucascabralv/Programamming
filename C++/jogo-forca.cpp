#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;
string palavra_secreta;
string palavra_tema;
const int max_erros = 8;

//vector<char> chutes_errados;
//Para adicionar no final desse vetor utilizar:
//chute_errados.push_back(chutes);

bool letra_existe(char chute){
    /* 
    // C++11 -> compila com: 
    // g++ jogo-forca.cpp -o jogo-forca -std=c++11
    // ou make jogo-forca.cpp ( por causa do Makefile)
    for(char letra : palavra_secreta){
        if(letra == chute){
            return true;
        }
    }
    */
    for(int i = 0; i < palavra_secreta.size(); i++){
        if(chute == palavra_secreta[i]){
            return true;
        }
    }
    return false;
}

void desenha(int erros){
    if(erros == 0){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜         " << endl;
        cout << "⎜         " << endl;
        cout << "⎜         " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 1){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜         " << endl;
        cout << "⎜         " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 2){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜    █    " << endl;
        cout << "⎜         " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 3){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜   ⎡█­­    " << endl;
        cout << "⎜         " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 4){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜   ⎡█⎤­­   " << endl;
        cout << "⎜         " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 5){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜   ⎡█⎤­­   " << endl;
        cout << "⎜   ⎟     " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 6){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜   ⎡█⎤­­   " << endl;
        cout << "⎜   ⎟ ⎜   " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 7){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜   ⎡█⎤­­   " << endl;
        cout << "⎜   ⎦ ⎜   " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    } else if(erros == 8){
        cout << "_____     " << endl;
        cout << "⎜   ⎩     " << endl;
        cout << "⎜    ◯    " << endl;
        cout << "⎜   ⎡█⎤­­   " << endl;
        cout << "⎜   ⎦ ⎣   " << endl;
        cout << "≜≜≜≜≜≜≜≜≜≜" << endl;
    }
}

bool nao_acertou(map<char, bool> chutou){
    for(int i = 0; i < palavra_secreta.size(); i++){
        if(!chutou[palavra_secreta[i]]){
            return true;
        }
    }
    return false;
}

void letras_chutadas(map<char, bool> chutou){
    string alfabeto = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    cout << "Letras que já chutou: ";
    for(int i = 0; i < alfabeto.size(); i++){
        if(chutou[alfabeto[i]]){
            cout << alfabeto[i];
        }
        cout << " ";
    }
    cout << "\n" << endl;
}

void imprime_palavraSecreta(map<char, bool> chutou){
    for(int i = 0; i < palavra_secreta.size(); i++){
        if(chutou[palavra_secreta[i]]){
            cout << palavra_secreta[i];
        } else {
            cout << "_";
        }
        cout << " ";
    }
    cout << "\n" << endl;
}

char trata_letra(char letra){
    if(letra >= 97 && letra <= 122){
        return letra = letra - 32;
    }
    return letra;
}

bool nao_enforcou(int erros){
    if(erros >= max_erros){
        return false;
    }
    return true;
}

void veredito_final(bool ganhou){
    if (!ganhou){
        cout << "\n\n";
        cout << "**********************************************" << endl;
        cout << " -> Você perdeu!!! "<< endl;
        cout << " A palavra era: " << palavra_secreta << endl;
        cout << "**********************************************" << endl;
        cout << "\n\n";
        cout << "Enter para continuar..." << endl;
        cin.ignore();
        getchar();
    } else {
        cout << "\n\n";
        cout << "***************************************" << endl;
        cout << " -> Parabéns você acertou a palavra!!!" << endl;
        cout << "***************************************" << endl;
        cout << "\n\n";
        cout << "Enter para continuar..." << endl;
        cin.ignore();
        getchar();
    }
}

vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("jogo-forca-palavras.txt");
    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        vector<string> palavras_arquivo;

        for(int i = 0; i < quantidade_palavras*2; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_arquivo;
    } else {
        cout << "O arquivo não pode ser encontrado" << endl;
        exit(0);
    }
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("jogo-forca-palavras.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista.size()/2 + 1 << endl;
        for(int i = 0; i < nova_lista.size(); i ++){
            arquivo << nova_lista[i];
            if(i % 2 != 0){
                arquivo << endl;
            } else {
                arquivo << " ";
            }
        } 
    } else {
        cout << "O arquivo não pode ser encontrado" << endl;
        exit(0);
    }
    arquivo.close();
}

void adiciona_palavra(){
    string palavra_sugerida;
        cout << "Adicione uma palavra ao banco de dados" << endl;
        cout << "Deseja continuar? [S/N]" << endl;
        cin.ignore();
        fflush(stdin);
        cin >> palavra_sugerida;
        if(palavra_sugerida == "S" || palavra_sugerida == "s"){
            system("clear || cls");
            cout << "• Regras: LETRAS MAIÚSCULAS e apenas uma palavra\n• Formato: TEMA PALAVRA" << endl;
            cout << "- Exemplo: FRUTA MORANGO" << endl;
            cout << "Digite: ";
            fflush(stdin);
            getline(cin, palavra_sugerida);

            vector<string> lista_palavras = le_arquivo();
            lista_palavras.push_back(palavra_sugerida);

            salva_arquivo(lista_palavras);
        }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();
    srand(time(NULL));
    int indice_aleatorio = rand() % palavras.size();
    if(indice_aleatorio % 2 != 0){
        indice_aleatorio += 1;
    }
    palavra_secreta = palavras[indice_aleatorio+1];
    palavra_tema = palavras[indice_aleatorio];
}

void jogo(){
    int erros = 0;
    int nletrasChutadas = 0;
    map<char, bool> chutou;

    sorteia_palavra();

    while(nao_acertou(chutou) && nao_enforcou(erros)){
        desenha(erros);
        cout << "Tema: " << palavra_tema << endl;
        letras_chutadas(chutou);
        imprime_palavraSecreta(chutou);

        char chute;
        cin >> chute;
        chute = trata_letra(chute);

        if(!letra_existe(chute) && chutou[chute] != true){
            erros++;
        }
        chutou[chute] = true;

        system("clear || cls");
    }
    veredito_final(nao_enforcou(erros));
}

int menu(){
    int escolha = 0;
    while(escolha != 1 && escolha != 2 && escolha != 3){
        system("clear || cls");
        cout << "***********************" << endl;
        cout << "***  JOGO DA FORCA  ***" << endl;
        cout << "***********************" << endl;
        cout << "\n";
        cout << "1 - Jogar" << endl;
        cout << "2 - Adicionar palavra" << endl;
        cout << "3 - Sair" << endl;
        cout << "\n-> Escolha um número: ";
        cin >> escolha;
    }
    system("clear || cls");
    return escolha;
}

int main(){
    int escolha = menu();
    while(escolha != 3){
        if(escolha == 1){
            jogo();
        }else if(escolha == 2){
            adiciona_palavra();
        }
        escolha = menu();
    }
    return 0;
}