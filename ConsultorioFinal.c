#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define INITIAL_ALLOC 2
#else
#define INITIAL_ALLOC 512
#endif
int Search_in_File(char *fname, char *str)
{
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];

	if ((fp = fopen(fname, "r")) == NULL)
	{
		return (-1);
	}
	while (fgets(temp, 512, fp) != NULL)
	{
		if ((strstr(temp, str)) != NULL)
		{
			printf("Se encontró una  coincidencia en la linea : %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	if (find_result == 0)
	{
		printf("\nLo sentimos, no encontramos ninguna coincidencia.\n");
	}

	//Close the file if still open.
	if (fp)
	{
		fclose(fp);
	}
	return (0);
}
int main(int argc, char *argv[])
{
	//FILE*registroBinarioM;
	//FILE*registroBinarioP;
	FILE *registroA;
	FILE *registroB;
	char *line;
	//char nombre[30], apellido[30],cedula[20],especialidad[20], correo[20],direccion[20],genero[10];//datos que van a ser necesarios pedir
	int opcion, opcionMedico, opcionPaciente, result;
	long int rectamp;
	long int rectam;
	char nombre[30];
	char repite = 1;
	char respuesta[10];
	char s;
	registroB = fopen("RegistroB.txt", "a+");
	if (registroB == NULL)
	{
		registroB = fopen("RegistroB.txt", "w+");
		if (registroB == NULL)
		{
			puts("No se puede abrir el archivo.");
			exit(0);
		}
	}
	registroA = fopen("RegistroA.txt", "a+");
	if (registroA == NULL)
	{
		registroA = fopen("RegistroA.txt", "w+");
		if (registroA == NULL)
		{
			puts("No se puede abrir el archivo.");
			exit(0);
		}
	}
	struct registroMedico
	{

		char nombre[30];
		char apellido[30];
		char sexo[30];
		int cedula;
		char especialidad[30];
		char direccion[30];
		char correo[30];
		int numConsultorio;
		char telefono[20];
	};
	struct registroMedico medico;

	struct registroPaciente
	{
		char nombre[30];
		char apellido[30];
		char sexo[30];
		char telefono[20];
		char direccion[30];
		int edad;
		char padecimiento[1000];
	};
	struct registroPaciente paciente;

	rectam = sizeof(medico);
	rectamp = sizeof(paciente);
	//do
	//{
	printf("\tBienvenido a My Oreo Consultory:\n ");
	printf("Favor de seleccione una de las siguientes opciones:\n");
	printf("1-Medico.\n");
	printf("2-Paciente.\n");
	printf("3-Salir.\n");
	scanf("%d", &opcion);
	fflush(stdin);
	switch (opcion)
	{
		//Menu medico
	case 1:

		do
		{
			//opciones del medico
			printf("\t---Menu de medico--- \n");
			printf("Seleccione una opcion:\n");
			printf("1-Buscar medico.\n");
			printf("2-Modificar medico.\n");
			printf("3-Registrar medico.\n");
			printf("4-Ver empleado.\n");
			printf("5-Eliminar archivo.\n");
			printf("6-Salir.\n");
			scanf("%d", &opcionMedico);
			fflush(stdin);
			switch (opcionMedico)
			{
			case 1:
				printf("Usted selecciono buscar medico:\n");
				printf("Favor de ingresar el nombre del medico que busca:\n");
				scanf("%s", nombre);
				result = Search_in_File("RegistroA.txt", nombre);
				if (result == -1)
				{
					perror("Error");
					exit(1);
				}

				fclose(registroA);
				break;
			case 2:
					printf("Usted selecciono modificar medico:\n");
				    printf("Desea modificar el nombre?:S/N\n");
				    scanf("%s",&respuesta);
				    if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			           	  printf("Favor de reingresar el nombre:\n");
			           	  
		             	}
				    printf("Deseas modificar el apellido?: S/N\n");
				    scanf("%s",&respuesta);
				    if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			           		printf("Favor de reingresar el apellido:\n");
		             	}
		            printf("Desea modificar el sexo?: S/N\n");
		            scanf("%s",&respuesta);
		            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		            	printf("Favor de reingresar el sexo:\n");
		            }
		            printf("Deseas modificar la id?: S/N\n");
		            scanf("%s",&respuesta);
		            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		            	printf("favor de reingresar su id:\n");
		            }
		            printf("Deseas modificar la especialidad?:S/N\n");
		            scanf("%s",&respuesta);
		            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		            	printf("Favor de reingresarla especialidad:\n");
		            }
		            printf("Deseas modificar tu direccion?:S/N\n");
		            scanf("%s",&respuesta);
		            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		            	printf("Favor de reingresar la direccion?:\n");
					}
					printf("Deseas modificar tu num.telefonico?: S/N\n");
					scanf("%s",&respuesta);
					if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar tu num.telefonico:\n");
					}
		            printf("Deseas modificar tu correo?: S/N\n");
		            scanf("%s",&respuesta);
		            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		            	printf("Favor de reingresar su correo:\n");
		            }
		            printf("Desea modificar su num.de consultorio?: S/N\n");
		            scanf("%s",&respuesta);
		            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
		            	printf("Favor de reingresar su num.de consultorio:\n");
					}
					
				break;
			case 3:

				do
				{

					//ingresamos datos del medico
					printf("Registro medico:\n");
					printf("Favor de ingresar su nombre:\n");
					scanf("%s", medico.nombre);
					printf("Favor de  ingresar su apellido:\n");
					scanf("%s", medico.apellido);
					printf("Favor de ingresar su sexo:\n");
					scanf("%s", medico.sexo);
					printf("Favor de ingresar su id:\n");
					scanf("%d", &medico.cedula);
					printf("Favor de ingresar su especialidad:\n");
					scanf("%s", medico.especialidad);
					printf("Favor de ingresar su direccion:\n");
					scanf("%s", medico.direccion);
					printf("Favor de ingresar su telefono:\n");
					scanf("%s", medico.telefono);
					printf("Favor de ingresar su correo:\n");
					scanf("%s", medico.correo);
					printf("Favor de ingresar su numero de consultorio:\n");
					scanf("%d", &medico.numConsultorio);
					fprintf(registroA, "-Nombre: %s \n-Apellido: %s \n-Sexo: %s \n-id: %d  \n-Especialidad: %s\n-Direccion: %s \n-Telefono: %s \n-Correo: %s \n-Consultorio:%d \n-------------\n", medico.nombre, medico.apellido, medico.sexo, medico.cedula, medico.especialidad, medico.direccion, medico.telefono, medico.correo, medico.numConsultorio);
					printf("Deseas agregar otro medico S/N?.\n");
					scanf("%s", respuesta);
					if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0))
					{
						repite = 0;
					}
				} while (repite);
				system("PAUSE");
				break;
			case 4:
				//Para listar los medicos.
				printf("ver medicos:\n");
				fclose(registroA);
				registroA = fopen("RegistroA.txt", "r");
				while((s=fgetc(registroA))!=EOF) {       
				printf("%c",s);    }
				
				fclose(registroA);

				break;
			case 5:

				//Cerramos el registroA para poder eliminarlo.
				fclose(registroA);

				printf("Seleccionaste eliminar archivo\n");

				if (remove("RegistroA.txt") == -1)
				{
					printf("Error en eliminar a archivo.\n");
				}
				else
				{

					printf("se elimino el archivo.\n");
				};

				break;
			case 6:
				printf("Seleccionaste salir.\n");
				exit(0);
				break;

			default:
				printf("Favor de ingresar una opcion valida.\n");
				break;
			}
		} while (opcion != 6);
		return 0;
		break;

	case 2:
		printf("\t---Menu de paciente--- \n");
		printf("Seleccione una opcion:\n");
		printf("1-Buscar paciente.\n");
		printf("2-Modificar paciente.\n");
		printf("3-Registrar paciente.\n");
		printf("4-Ver paciente.\n");
		printf("5-Eliminar archivo.\n");
		printf("6-Salir.\n");
		scanf("%d", &opcionPaciente);
		fflush(stdin);
		switch (opcionPaciente)
		{
		case 1:
			printf("Selecciono buscar paciente:\n");
			printf("Favor de ingresar el nombre del medico que busca:\n");
			scanf("%s", nombre);
			result = Search_in_File("RegistroB.txt", nombre);
				if (result == -1)
				{
					perror("Error");
					exit(1);
				}

			fclose(registroB);
			
			break;
		case 2:
			printf("Selecciono Modificar pacientes.\n");
			printf("Deseas modificar el nombre?:S/N\n");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar el nombre:\n");
			}
			printf("Deseas modificar el apellido?: S/N\n");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar el apellido:\n");
			}
			printf("Deseas modificar el sexo?:S/N\n");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar el sexo:\n");
			}
			printf("Deseas modificar la edad?:S/N\n");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar la edad:\n");
			}
			printf("Deseas modificar el num.telefonico?:S/N\n ");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar el num.telefonico:\n");
			}
			printf("Deseas modificar la direccion?:S/N\n");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar la direccion:\n");
			}
			printf("Deseas modificar los sintomas?:S/N\n");
			scanf("%s",&respuesta);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
						printf("Favor de reingresar los sintomas:\n");
			}
			break;
		case 3:
			printf("Selecciono registrar paciente:\n");
			printf("Favor de ingresar el nombre del paciente:\n");
			scanf("%s", paciente.nombre);
			printf("Favor de  ingresar el apellido del paciente:\n");
			scanf("%s", paciente.apellido);
			printf("Favor de ingresar el sexo de su paciente:\n");
			scanf("%s", paciente.sexo);
			printf("Favor de ingresar la  edad de su paciente:\n");
			scanf("%d", &paciente.edad);
			printf("Favor de ingresar el telefono del paciente:\n");
			scanf("%s", paciente.telefono);
			printf("Favor de ingresar la direccion del paciente:\n");
			scanf("%s", paciente.direccion);
			printf("Favor de ingresar los sintomas del paciente:\n");
			scanf("%s", paciente.padecimiento);
			fprintf(registroB, "\n-Nombre: %s \n-Apellido: %s \n-Sexo: %s \n-Edad: %d \n-Telefono: %s \n-Direccion: %s \n-Sintomas: %s \n-------------\n", paciente.nombre, paciente.apellido, paciente.sexo, paciente.edad, paciente.telefono, paciente.direccion, paciente.padecimiento);
			system("PAUSE");
			break;
		case 4:
			//listar pacientes.
			printf("Selecciono ver pacientes:\n");
			fclose(registroB);
				registroA = fopen("RegistroB.txt", "r");
				while((s=fgetc(registroB))!=EOF) {       
				printf("%c",s);    }
				
				fclose(registroB);
			break;
		case 5:
			//Cerramos el registroB para asi poderlo eliminar
			fclose(registroB);
			printf("Seleccionaste eliminar archivo\n");

			if (remove("RegistroB.txt") == -1)
			{
				printf("Error en eliminar a archivo.\n");
			}
			else
			{

				printf("se elimino archivo.\n");
			};
			break;
		case 6:
			printf("Seleccionaste salir.\n");
			exit(0);

			break;
		}
		break;
	case 3:
		printf("Seleccionaste salir.\n");
		exit(0);
		break;

	default:
		printf("Prueba");
		break;
	}

	//	}while(opcion!=3);
	//return 0;
}
