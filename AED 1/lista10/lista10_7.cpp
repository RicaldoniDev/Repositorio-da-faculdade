#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

/*
    Escreva uma classe em C++ que gerencie o acesso de um usuário ao sistema. O usuário deverá
    logar no sistema com o usuário "aluno" e a senha "1234". Caso o aluno tente entrar com um login
    diferente do informado, o sistema deverá lançar uma exceção, posteriormente tratada, indicando
    que o acesso não foi autorizado. Caso o usuário não informe o nome de usuário ou senha, o
    sistema também deve também lançar uma exceção, tratada pelo procedimento principal (main).
    A sua classe deve ter os atributos usuário e senha podendo ser carregados no construtor ou no
    método logar, que retornar um booleano indicando sucesso no login. Utilize o conceito de
    polimorfismo paramétrico (sobrecarga de método).
*/

class Login
{
private:
    char usuario[20];
    int senha = 0;

public:
    void logar()
    {
        cout << "Digite seu nome de usuario: ";
        cin >> usuario;

        cout << "Digite sua senha: ";
        cin >> senha;

        if (strcmp(usuario, "aluno") != 0)
        {
            throw 202;
            return;
        }

        if (strcmp(usuario, "") != 0)
        {
            throw 303;
            return;
        }

        if (senha == 0)
        {
            throw 404;
            return;
        }

        if (senha != 1234)
        {
            throw 505;
            return;
        }
    }
};

int main()
{
    Login login;

    try
    {
        login.logar();
    }
    catch (int err)
    {
        if (err == 202)
        {
            cout << "Usuário incorreto" << endl;
        }

        else if (err == 303)
        {
            cout << "Preencha o usuario" << endl;
        }

        else if (err == 404)
        {
            cout << "Preencha a senha" << endl;
        }

        else if (err == 505)
        {
            cout << "Senha incorreta" << endl;
        }
    }
}