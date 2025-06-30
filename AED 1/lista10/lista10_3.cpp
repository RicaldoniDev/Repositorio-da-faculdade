#include <stdlib.h>
#include <iostream>

using namespace std;

/*
    Crie uma classe para representar uma conta corrente, com métodos para depositar uma
    quantia, sacar uma quantia e obter o saldo. Para cada saque será debitada também uma taxa de
    operação equivalente à 0.5% do valor sacado. Crie, em seguida, uma subclasse (herdada) da classe
    anterior para representar uma conta corrente de um cliente especial. Clientes especiais pagam
    taxas de operação de apenas 0.1% do valor sacado.
*/

class ContaCorrente
{
private:
    float saldo;

public:
    float getSaldo()
    {
        return saldo;
    }

    void setSaldo(float saldo)
    {
        this->saldo = saldo;
    }

    void deposito(float valor)
    {
        saldo += valor;
    }

    void sacar(float valor)
    {
        if (valor > saldo)
        {
            cout << "Saldo insuficiente";
            return;
        }
        saldo -= valor * (0.5 / 100);
    }
};

class ContaEspecial : ContaCorrente
{

public:
    void sacar(float valor)
    {
        if (valor > getSaldo())
        {
            cout << "Saldo insuficiente";
            return;
        }
        setSaldo(getSaldo() - valor * (0.5 / 100));
    }

    void deposito(float valor)
    {
        setSaldo(getSaldo() + valor);
    }

    float getSaldo()
    {
        return getSaldo();
    }
};

int main()
{
    int tipo, opcao;
    float valor;

    ContaCorrente contaPadrao;
    ContaEspecial especial;

    cout << "\nSelecione o tipo de conta:" << endl;
    cout << "1 - Conta padrao" << endl;
    cout << "2 - Conta especial" << endl;
    cin >> tipo;

    do
    {
        cout << endl
             << "\nSelecione as opcoes:" << endl;
        cout << "1 - Sacar" << endl;
        cout << "2 - Depositar" << endl;
        cout << "3 - Conferir Saldo" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 0:
            cout << "Saindo..." << endl;
            break;

        case 1:
            float valor;
            cout << "Digite o valor do saque: ";
            cin >> valor;
            if (tipo == 1)
            {
                contaPadrao.sacar(valor);
            }
            else if (tipo == 2)
            {
                especial.sacar(valor);
            }
            break;

        case 2:
            float valor;
            cout << "Digite o valor do deposito: ";
            cin >> valor;
            if (tipo == 1)
            {
                contaPadrao.deposito(valor);
            }
            else if (tipo == 2)
            {
                especial.deposito(valor);
            }

        case 3:
            if (tipo == 1)
            {
                contaPadrao.getSaldo();
            }
            else if (tipo == 2)
            {
                especial.getSaldo();
            }
        default:
            cout << "Opcao invalida";
            break;
        }

    } while (opcao != 0);
}