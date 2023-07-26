#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento_pesca.h"

#define ERROR -1
#define EXITO 0

arrecife_t* crear_arrecife(const char* ruta_archivo) {
	int cantidad_leidos = 0;

	pokemon_t pokemon;

	arrecife_t* arrecife = malloc(1 * sizeof(arrecife_t));
	if (arrecife == NULL) {
		liberar_arrecife(arrecife);
		return NULL;
	}

	arrecife->pokemon = NULL;
	arrecife->cantidad_pokemon = 0;

	void* auxiliar_pokemones = NULL;

	FILE* archivo_arrecife = fopen(ruta_archivo, "r");
	if (!archivo_arrecife) {
		liberar_arrecife(arrecife);
		return NULL;
	}

	while ((cantidad_leidos = fscanf(archivo_arrecife, "%99[^;];%i;%i;%49[^\n]\n", pokemon.especie, &pokemon.velocidad, &pokemon.peso, pokemon.color)) == 4) {
		auxiliar_pokemones = realloc(arrecife->pokemon, (unsigned int)(arrecife->cantidad_pokemon + 1) * sizeof(pokemon_t));
		if (auxiliar_pokemones == NULL) {
			liberar_arrecife(arrecife);
			arrecife = NULL;
		}
		arrecife->pokemon = auxiliar_pokemones;
		arrecife->pokemon[arrecife->cantidad_pokemon] = pokemon;
		arrecife->cantidad_pokemon++;
	}

	fclose(archivo_arrecife);

	if (arrecife->cantidad_pokemon == 0) {
		liberar_arrecife(arrecife);
    	return NULL;
    }

	return arrecife;
}

acuario_t* crear_acuario() {
	acuario_t* acuario = malloc(1 * sizeof(acuario_t));
	if (acuario == NULL) {
		liberar_acuario(acuario);
		return NULL;
	}

	acuario->pokemon = NULL;
	acuario->cantidad_pokemon = 0;

	return acuario;
}

int trasladar_pokemon(arrecife_t* arrecife, acuario_t* acuario, bool (*seleccionar_pokemon) (pokemon_t*), int cant_seleccion) {
	if (arrecife == NULL) {
		return ERROR;
	}

	if (acuario == NULL) {
		return ERROR;
	}

	if (cant_seleccion == 0) {
		return EXITO;
	}

	int i = 0;
	int contador_pokemon_suficientes = 0;
	bool pokemon_satisface_condicion = false;
	pokemon_t pokemon_auxiliar;
	void* auxiliar_acuario = NULL;

	for (int i = 0; i < arrecife->cantidad_pokemon; i++) {
		pokemon_satisface_condicion = seleccionar_pokemon(&arrecife->pokemon[i]);
		if (pokemon_satisface_condicion == true) {
			contador_pokemon_suficientes++;
		}
	}

	pokemon_satisface_condicion = false;

	if (contador_pokemon_suficientes >= cant_seleccion) {
		while ((i < arrecife->cantidad_pokemon) && (cant_seleccion != 0)) {
			pokemon_satisface_condicion = seleccionar_pokemon(&arrecife->pokemon[i]);
			if (pokemon_satisface_condicion == true) {
				auxiliar_acuario = realloc(acuario->pokemon, (unsigned int)(acuario->cantidad_pokemon + 1) * sizeof(pokemon_t));
				if (auxiliar_acuario != NULL) {
					pokemon_auxiliar = arrecife->pokemon[i];
					for (int j = i; j < (arrecife->cantidad_pokemon - 1); j++) {
						arrecife->pokemon[j] = arrecife->pokemon[j + 1];
					}

					acuario->pokemon = auxiliar_acuario;
					acuario->pokemon[acuario->cantidad_pokemon] = pokemon_auxiliar;
					acuario->cantidad_pokemon++;
					arrecife->cantidad_pokemon--;
					i--;
					cant_seleccion--;
				} else {
					i = arrecife->cantidad_pokemon;
				}
			}
			i++;
		}	
	} else {
		return ERROR;
	}

	if (auxiliar_acuario == NULL) {
		return ERROR;
	}

	return EXITO;
}

void censar_arrecife(arrecife_t* arrecife, void (*mostrar_pokemon)(pokemon_t*)) {
	if (arrecife == NULL) {
		return;
	}

	if (mostrar_pokemon == NULL) {
		return;
	}

	for (int i = 0; i < arrecife->cantidad_pokemon; i++) {
		mostrar_pokemon(&arrecife->pokemon[i]);
	}
}

int guardar_datos_acuario(acuario_t* acuario, const char* nombre_archivo) {
	if (acuario == NULL) {
		return ERROR;
	}

	FILE* archivo_acuario = fopen(nombre_archivo, "w");
	if (!archivo_acuario) {
		fclose(archivo_acuario);
		return ERROR;
	}

	for (int i = 0; i < acuario->cantidad_pokemon; i++) {
		fprintf(archivo_acuario, "%s;%i;%i;%s\n", acuario->pokemon[i].especie, acuario->pokemon[i].velocidad, acuario->pokemon[i].peso, acuario->pokemon[i].color);
	}

	fclose(archivo_acuario);

	return EXITO;
}

void liberar_acuario(acuario_t* acuario) {
	if (acuario == NULL) {
		return;
	}

	free(acuario->pokemon);
	free(acuario);
}

void liberar_arrecife(arrecife_t* arrecife) {
	if (arrecife == NULL) {
		return;
	}

	free(arrecife->pokemon);
	free(arrecife);
}