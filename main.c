#include <stdio.h>
#include <ctype.h>

int main () {

    char ID[5][10], nombre[5][20];
    int stock[5], numVentas, numReabastecer;
    float precio[5], ganancias = 0, total = 0, descuento = 0;
    int selP;
    int cantP = 0;

    int opc;
    char opc2;

    do {
        do {
            printf("\nSeleccione una opcion:\n");
            printf("1.Registrar producto\n");
            printf("2.Vender producto\n");
            printf("3.Reabastecer producto\n");
            printf("4.Informacion producto\n");
            printf("5.Mostrar ganancias\n");
            printf("6.Salir\n");
            printf(">> ");
            scanf("%d", &opc);

            if (opc < 1 || opc > 6) {
                printf("Opcion invalida. Intente de nuevo.\n");
            }
        } while (opc < 1 || opc > 6);

        switch (opc)
        {
        case 1:
            if (cantP >= 5) {
                printf("Error: Se ha alcanzado el limite maximo de productos (5).\n");
                break;
            }
            printf("Ingrese los datos del producto\n");
            printf("ID: ");
            scanf("%s", ID[cantP]);
            printf("Nombre: ");
            scanf("%s", nombre[cantP]);
            
            do {
                printf("Stock: ");
                scanf("%d", &stock[cantP]);
                if (stock[cantP] < 0) {
                    printf("Error: El stock debe ser mayor o igual a 0. Intente de nuevo.\n");
                }
            } while (stock[cantP] < 0);

            do {
                printf("Precio: ");
                scanf("%f", &precio[cantP]);
                if (precio[cantP] < 0) {
                    printf("Error: El precio debe ser mayor o igual a 0. Intente de nuevo.\n");
                }
            } while (precio[cantP] < 0);

            cantP++;
            break;

        case 2:
            if (cantP == 0) {
                printf("No hay productos registrados.\n");
                break;
            }
            printf("Seleccione el numero de producto que desea vender:\n");
            printf("#\t\tId\t\tNombre\t\tStock\t\tPrecio\n");

            for (int i = 0; i < cantP; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", i, ID[i], nombre[i], stock[i], precio[i]);
            }
            
            do {
                printf(">> ");
                scanf("%d", &selP);
                if (selP < 0 || selP >= cantP) {
                    printf("Seleccion invalida. Seleccione un indice valido:\n");
                }
            } while (selP < 0 || selP >= cantP);

            do {
                printf("Ingrese las unidades que desea vender: ");
                scanf("%d", &numVentas);
                if (numVentas < 0) {
                    printf("Error: La cantidad de ventas debe ser mayor o igual a 0. Intente de nuevo.\n");
                }
            } while (numVentas < 0);

            if (numVentas > stock[selP]) {
                printf("Error: No se puede realizar la venta, no existe suficiente stock\n");
                break;
            }

            do {
                printf("Ingrese el porcentaje de descuento: ");
                scanf("%f", &descuento);
                if (descuento < 0 || descuento > 100) {
                    printf("Error: El descuento debe estar entre 0 y 100. Intente de nuevo.\n");
                }
            } while (descuento < 0 || descuento > 100);

            stock[selP] -= numVentas;
            total = (numVentas * precio[selP]) * (1 - (descuento / 100.0));
            ganancias += total;

            printf("El valor de la venta es: %.2f\n", total);
            printf("El nuevo stock es: %d\n", stock[selP]);
            break;

        case 3:
            if (cantP == 0) {
                printf("No hay productos registrados.\n");
                break;
            }
            printf("Seleccione el producto que desea reabastecer:\n");
            printf("#\t\tId\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cantP; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", i, ID[i], nombre[i], stock[i], precio[i]);
            }
            
            do {
                printf(">> ");
                scanf("%d", &selP);
                if (selP < 0 || selP >= cantP) {
                    printf("Seleccion invalida. Seleccione un indice valido:\n");
                }
            } while (selP < 0 || selP >= cantP);

            do {
                printf("Ingrese las unidades que desea reabastecer: ");
                scanf("%d", &numReabastecer);
                if (numReabastecer < 0) {
                    printf("Error: La cantidad a reabastecer debe ser mayor o igual a 0. Intente de nuevo.\n");
                }
            } while (numReabastecer < 0);

            stock[selP] += numReabastecer;
            printf("El nuevo stock es: %d\n", stock[selP]);
            break;

        case 4:
            if (cantP == 0) {
                printf("No hay productos registrados.\n");
                break;
            }
            printf("Id\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cantP; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%.2f\n", ID[i], nombre[i], stock[i], precio[i]);
            }
            break;

        case 5:
            printf("Las ganancias totales acumuladas son: %.2f\n", ganancias);
            break;

        case 6:
            return 0;

        default:
            break;
        }

        do {
            printf("\n¿Desea realizar otra operacion?\n");
            printf("[S] Continuar en el sistema\n");
            printf("[N] Salir del programa\n");
            printf(">> ");
            scanf(" %c", &opc2);

            opc2 = toupper(opc2);

            if (opc2 != 'S' && opc2 != 'N') {
                printf("Opcion no valida. Por favor ingrese 'S' o 'N'.\n");
            }
        } while (opc2 != 'S' && opc2 != 'N');

    } while (opc2 == 'S');

    return 0;
}