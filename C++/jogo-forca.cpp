#include <iostream>
#include <string>
#include <map>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;

bool letra_existe(char chute){
    /* 
    // C++11 -> compila com: 
    // g++ jogo-forca.cpp -o jogo-forca -std=c++11
    // ou make jogo-forca.cpp ( por causa do Makefile)
    for(char letra : PALAVRA_SECRETA){
        if(letra == chute){
            return true;
        }
    }
    */
    for(int i = 0; i < PALAVRA_SECRETA.size(); i++){
        if(chute == PALAVRA_SECRETA[i]){
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


int main(){
    system("clear || cls");
    int erros = 0;
    int max_erros = 8;
    int nletrasChutadas = 0;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    string alfabeto = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

    while(nao_acertou && nao_enforcou && erros < max_erros){
        desenha(erros);

        cout << "Letras que já chutou: ";

        for(int i = 0; i < alfabeto.size(); i++){
            if(chutou[alfabeto[i]]){
                cout << alfabeto[i];
            } else {
                cout << " ";
            }
            cout << " ";
        }

        cout << "\n" << endl;

        for(int i = 0; i < PALAVRA_SECRETA.size(); i++){
            if(chutou[PALAVRA_SECRETA[i]]){
                cout << PALAVRA_SECRETA[i];
            } else {
                cout << "_";
            }
            cout << " ";
        }

        cout << "\n" << endl;

        char chute;
        cin >> chute;

        chutou[chute] = true;
        

        if(letra_existe(chute)){
            
        } else {
            erros++;
        }
        system("clear || cls");
    }
    if (erros < max_erros){
        cout << "Você perdeu!!!";
    }
    return 0;
}