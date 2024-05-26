#include <stdio.h>

int main() {
    int numeroFactura, cedula, localidad, cantidadEntradas;
    char nombre[100];
    char continuar;
    float precioEntrada, subtotal, cargosServicio, totalPagar;
    const float cargoServicioPorEntrada = 1000.0;
    
    // Variables para las estadísticas
    int cantidadSol = 0, cantidadSombra = 0, cantidadPreferencial = 0;
    float acumuladoSol = 0, acumuladoSombra = 0, acumuladoPreferencial = 0;
    
    do {
        // Lectura de datos de la venta
        printf("Ingrese el numero de factura: ");
        scanf("%d", &numeroFactura);
        
        printf("Ingrese la cedula del comprador: ");
        scanf("%d", &cedula);
        
        printf("Ingrese el nombre del comprador: ");
        scanf("%s", nombre);
        
        // Validar la localidad ingresada
        do {
            printf("Ingrese la localidad deseada (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ");
            scanf("%d", &localidad);
        } while (localidad < 1 || localidad > 3);
        
        // Validar la cantidad de entradas
        do {
            printf("Ingrese la cantidad de entradas (maximo 4): ");
            scanf("%d", &cantidadEntradas);
        } while (cantidadEntradas < 1 || cantidadEntradas > 4);
        
        // Determinar el precio por entrada y el nombre de la localidad
        char nombreLocalidad[20];
        if (localidad == 1) {
            precioEntrada = 10500.0;
            snprintf(nombreLocalidad, sizeof(nombreLocalidad), "Sol Norte/Sur");
        } else if (localidad == 2) {
            precioEntrada = 20500.0;
            snprintf(nombreLocalidad, sizeof(nombreLocalidad), "Sombra Este/Oeste");
        } else if (localidad == 3) {
            precioEntrada = 25500.0;
            snprintf(nombreLocalidad, sizeof(nombreLocalidad), "Preferencial");
        }
        
        // Cálculo del subtotal
        subtotal = cantidadEntradas * precioEntrada;
        
        // Cálculo de los cargos por servicios
        cargosServicio = cantidadEntradas * cargoServicioPorEntrada;
        
        // Cálculo del total a pagar
        totalPagar = subtotal + cargosServicio;
        
        // Mostrar los datos de la venta
        printf("\nNumero de Factura: %d\n", numeroFactura);
        printf("Cedula: %d\n", cedula);
        printf("Nombre comprador: %s\n", nombre);
        printf("Localidad: %s\n", nombreLocalidad);
        printf("Cantidad de Entradas: %d\n", cantidadEntradas);
        printf("Subtotal: %.2f colones\n", subtotal);
        printf("Cargos por Servicios: %.2f colones\n", cargosServicio);
        printf("Total a pagar: %.2f colones\n\n", totalPagar);
        
        // Actualización de las estadísticas
        if (localidad == 1) {
            cantidadSol += cantidadEntradas;
            acumuladoSol += subtotal;
        } else if (localidad == 2) {
            cantidadSombra += cantidadEntradas;
            acumuladoSombra += subtotal;
        } else if (localidad == 3) {
            cantidadPreferencial += cantidadEntradas;
            acumuladoPreferencial += subtotal;
        }
        
        // Preguntar si se desea registrar otra venta
        printf("Desea ingresar otra venta? (s/n): ");
        scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');
    
    // Mostrar estadísticas finales
    printf("\nEstadísticas:\n");
    printf("Cantidad Entradas Localidad Sol Norte/Sur: %d\n", cantidadSol);
    printf("Acumulado Dinero Localidad Sol Norte/Sur: %.2f colones\n", acumuladoSol);
    printf("Cantidad Entradas Localidad Sombra Este/Oeste: %d\n", cantidadSombra);
    printf("Acumulado Dinero Localidad Sombra Este/Oeste: %.2f colones\n", acumuladoSombra);
    printf("Cantidad Entradas Localidad Preferencial: %d\n", cantidadPreferencial);
    printf("Acumulado Dinero Localidad Preferencial: %.2f colones\n", acumuladoPreferencial);
    
    return 0;
}

