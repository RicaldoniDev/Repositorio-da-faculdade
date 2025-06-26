using System;

class Program
{
    static void Main()
    {
        // Lê os dois números inteiros
        string[] entrada = Console.ReadLine().Split();
        int inicio = int.Parse(entrada[0]);
        int fim = int.Parse(entrada[1]);

        string crescente = "";
        string resultado = "";

        // Monta a sequência crescente
        for (int i = inicio; i <= fim; i++)
        {
            crescente += i.ToString();
        }

        // Adiciona a parte crescente ao resultado
        resultado += crescente;

        // Adiciona a parte invertida (espelho)
        for (int i = crescente.Length - 1; i >= 0; i--)
        {
            resultado += crescente[i];
        }

        // Imprime o resultado final
        Console.WriteLine(resultado);
    }
}