#include <stdio.h>

int main() {
    int cedula, tipoEmpleado, cantidadHoras;
    float precioHora, salarioOrdinario, aumento, salarioBruto, deduccionCCSS, salarioNeto;
    char nombre[100];
    char continuar;
    
    // Variables para las estadísticas
    int cantidadOperarios = 0, cantidadTecnicos = 0, cantidadProfesionales = 0;
    float acumuladoOperarios = 0, acumuladoTecnicos = 0, acumuladoProfesionales = 0;

    do {
        // Lectura de datos del empleado
        printf("Ingrese la cedula del empleado: ");
        scanf("%d", &cedula);
        
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", nombre);
        
        printf("Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ");
        scanf("%d", &tipoEmpleado);
        
        printf("Ingrese la cantidad de horas laboradas: ");
        scanf("%d", &cantidadHoras);
        
        printf("Ingrese el precio por hora: ");
        scanf("%f", &precioHora);
        
        // Cálculo del salario ordinario
        salarioOrdinario = cantidadHoras * precioHora;

        // Cálculo del aumento según el tipo de empleado
        if (tipoEmpleado == 1) {
            aumento = salarioOrdinario * 0.15;
        } else if (tipoEmpleado == 2) {
            aumento = salarioOrdinario * 0.10;
        } else if (tipoEmpleado == 3) {
            aumento = salarioOrdinario * 0.05;
        } else {
            aumento = 0;
            printf("Tipo de empleado invalido.\n");
        }

        // Cálculo del salario bruto
        salarioBruto = salarioOrdinario + aumento;
        
        // Cálculo de las deducciones de ley (9.17%)
        deduccionCCSS = salarioBruto * 0.0917;
        
        // Cálculo del salario neto
        salarioNeto = salarioBruto - deduccionCCSS;
        
        // Mostrar los datos del empleado
        printf("\nCedula: %d\n", cedula);
        printf("Nombre Empleado: %s\n", nombre);
        printf("Tipo Empleado: %d\n", tipoEmpleado);
        printf("Salario por Hora: %.2f\n", precioHora);
        printf("Cantidad de Horas: %d\n", cantidadHoras);
        printf("Salario Ordinario: %.2f\n", salarioOrdinario);
        printf("Aumento: %.2f\n", aumento);
        printf("Salario Bruto: %.2f\n", salarioBruto);
        printf("Deduccion CCSS: %.2f\n", deduccionCCSS);
        printf("Salario Neto: %.2f\n\n", salarioNeto);
        
        // Actualización de las estadísticas
        if (tipoEmpleado == 1) {
            cantidadOperarios++;
            acumuladoOperarios += salarioNeto;
        } else if (tipoEmpleado == 2) {
            cantidadTecnicos++;
            acumuladoTecnicos += salarioNeto;
        } else if (tipoEmpleado == 3) {
            cantidadProfesionales++;
            acumuladoProfesionales += salarioNeto;
        }
        
        // Preguntar si se desea ingresar otro empleado
        printf("Desea ingresar otro empleado? (s/n): ");
        scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');
    
    // Calcular los promedios
    float promedioOperarios = (cantidadOperarios > 0) ? (acumuladoOperarios / cantidadOperarios) : 0;
    float promedioTecnicos = (cantidadTecnicos > 0) ? (acumuladoTecnicos / cantidadTecnicos) : 0;
    float promedioProfesionales = (cantidadProfesionales > 0) ? (acumuladoProfesionales / cantidadProfesionales) : 0;
    
    // Mostrar estadísticas
    printf("\nEstadísticas:\n");
    printf("Cantidad Empleados Tipo Operarios: %d\n", cantidadOperarios);
    printf("Acumulado Salario Neto para Operarios: %.2f\n", acumuladoOperarios);
    printf("Promedio Salario Neto para Operarios: %.2f\n", promedioOperarios);
    
    printf("Cantidad Empleados Tipo Tecnico: %d\n", cantidadTecnicos);
    printf("Acumulado Salario Neto para Tecnicos: %.2f\n", acumuladoTecnicos);
    printf("Promedio Salario Neto para Tecnicos: %.2f\n", promedioTecnicos);
    
    printf("Cantidad Empleados Tipo Profesional: %d\n", cantidadProfesionales);
    printf("Acumulado Salario Neto para Profesionales: %.2f\n", acumuladoProfesionales);
    printf("Promedio Salario Neto para Profesionales: %.2f\n", promedioProfesionales);
    
    return 0;
}

