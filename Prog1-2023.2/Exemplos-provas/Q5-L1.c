    #include <stdio.h>
    #include <math.h>
    #include <locale.h>

    void calculaTaxas(float);
    
    int main (){
        
        float fuel;

        setlocale(LC_ALL, "");
    
        printf("Insira o preço da gasolina na bomba: ");
        scanf("%f", &fuel);
        printf("Fuel: %f\n\n", fuel);

        calculaTaxas(fuel);

    return 0;
    }

    void calculaTaxas(float fuel){
        float distri, etanol, icms, cidepiscofins, refinaria;

        distri = fuel*0.17;
        etanol = fuel*0.12;
        icms = fuel*0.28;
        cidepiscofins = fuel*0.07;

        refinaria = fuel - distri - etanol - icms - cidepiscofins;

        printf("Valor na bomba: %.2fR$"
          "\nDistribuição e revenda: %.2fR$"
          "\nCusto Etanol Anidro: %.2fR$"
          "\nICMS: %.2fR$"
          "\nCIDE, PIS/PASEP e COFINS: %.2fR$"
          "\nVALOR DA REFINARIA: %.2fR$.", fuel, distri, etanol, icms, cidepiscofins, refinaria);
    }