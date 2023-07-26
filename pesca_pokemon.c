#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento_pesca.h"

#define ERROR -1
#define EXITO 0

#define CANTIDAD_GYARADOS 1
#define CANTIDAD_LEGENDARIOS 1
#define CANTIDAD_AZULES 2
#define CANTIDAD_VERDES 2
#define CANTIDAD_MAYOR_PESO 5

/* Compara la especie del Pokémon con la especie Gyarados. 
Si son iguales, devuelve true. Si no lo son, devuelve false. */
bool seleccionar_gyarados(pokemon_t* pokemon) {
	if (strcmp(pokemon->especie, "Gyarados") == 0) {
		return true;
	} else {
		return false;
	}
}

/* Compara la especie del Pokémon con el nombre de los legendarios del trío dragón. 
Si son iguales, devuelve true. Si no lo son, devuelve false. */
bool seleccionar_legendarios_trio_dragon(pokemon_t* pokemon) {
	if ((strcmp(pokemon->especie, "Dialga") == 0) || (strcmp(pokemon->especie, "Palkia") == 0) || (strcmp(pokemon->especie, "Giratina") == 0)) {
		return true;
	} else {
		return false;;
	}
}

/* Compara el color del Pokémon con el azul. 
Si son iguales, devuelve true. Si no lo son, devuelve false. */
bool seleccionar_azules(pokemon_t* pokemon) {
	if (strcmp(pokemon->color, "azul") == 0) {
		return true;
	} else {
		return false;
	}
}

/* Compara el color del Pokémon con el verde. 
Si son iguales, devuelve true. Si no lo son, devuelve false. */
bool seleccionar_verdes(pokemon_t* pokemon) {
	if (strcmp(pokemon->color, "verde") == 0) {
		return true;
	} else {
		return false;
	}
}

/* Devuelve true si el Pokémon pesa más o igual a 100, de lo contrario devuelve false. */
bool seleccionar_mayor_peso(pokemon_t* pokemon) {
	if (pokemon->peso >= 100) {
		return true;
	} else {
		return false;
	}
}

/* Muestra los datos del Pokémon en una línea de texto. */
void mostrar_pokemon_en_linea(pokemon_t* pokemon) {
	printf("Especie: %s\nVelocidad: %i  /  Peso: %i  /  Color: %s\n\n", pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color);
}

/* Muestra los datos del Pokémon en forma de carta. */
void mostrar_pokemon_en_carta(pokemon_t* pokemon) {
	printf("|--------------------|\n|     | ʕ·͡ᴥ·ʔ  |     |\n|--------------------|\n|     %s     |\n|  Velocidad: %i     |\n|  Peso: %i          |\n|  Color: %s      |\n|--------------------|\n\n", pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color);
}

/* Muestra los datos del Pokémon como se mostraba en los primeros juegos. */
void mostrar_pokemon_forma_clasica(pokemon_t* pokemon) {
	printf("------------------------\n\t%s\nʕ·͡ᴥ·ʔ     HP: ██████████\n\t\t20/20\nSpeed: %i\nWeight: %i\nColor: %s\n\n", pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color);
}

/* Muestra los datos del Pokémon como se muestra en los juegos actuales. */
void mostrar_pokemon_forma_actualizada(pokemon_t* pokemon) {
	printf("----------------------------\n\n  ʕ·͡ᴥ·ʔ    Name: %s\n ٩(̾●̮̮̃̾•̃̾)۶   Type: Water\n   Ƹ̵̡Ӝ̵̨̄Ʒ     OT: None\n  ˁ˚ᴥ˚ˀ    Speed: %i\n  ༼  ༽     Weight: %i\n  █  █     Color: %s\n\n", pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color);
}

/* Muestra los datos del Pokémon con Pikachu mirando. */
void mostrar_pokemon_pikachu_mirando(pokemon_t* pokemon) {
	printf("⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿ Especie: %s\n⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿ Velocidad: %i\n⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿ Peso: %i\n⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿ Color: %s\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿\n\n", pokemon->especie, pokemon->velocidad, pokemon->peso, pokemon->color);
}

int main() {
	arrecife_t* arrecife;
	acuario_t* acuario;

	int estado_trasladar = -1;

	arrecife = crear_arrecife("arrecife.txt");
	if (arrecife != NULL) {
		acuario = crear_acuario();
		if (acuario == NULL) {
			liberar_arrecife(arrecife);
		}
	}
	
	if ((arrecife != NULL) && (acuario != NULL)) {
		estado_trasladar = trasladar_pokemon(arrecife, acuario, &seleccionar_gyarados, CANTIDAD_GYARADOS);
		if (estado_trasladar == EXITO) {
			censar_arrecife(arrecife, &mostrar_pokemon_en_linea);
		}

		estado_trasladar = trasladar_pokemon(arrecife, acuario, &seleccionar_legendarios_trio_dragon, CANTIDAD_LEGENDARIOS);
		if (estado_trasladar == EXITO) {
			censar_arrecife(arrecife, &mostrar_pokemon_en_carta);
		}

		estado_trasladar = trasladar_pokemon(arrecife, acuario, &seleccionar_azules, CANTIDAD_AZULES);
		if (estado_trasladar == EXITO) {
			censar_arrecife(arrecife, &mostrar_pokemon_forma_clasica);
		}

		estado_trasladar = trasladar_pokemon(arrecife, acuario, &seleccionar_verdes, CANTIDAD_VERDES);	
		if (estado_trasladar == EXITO) {
			censar_arrecife(arrecife, &mostrar_pokemon_forma_actualizada);
		}

		estado_trasladar = trasladar_pokemon(arrecife, acuario, &seleccionar_mayor_peso, CANTIDAD_MAYOR_PESO);
		if (estado_trasladar == EXITO) {
			censar_arrecife(arrecife, &mostrar_pokemon_pikachu_mirando);
		}

		guardar_datos_acuario(acuario, "acuario.txt");
		liberar_acuario(acuario);
		liberar_arrecife(arrecife);
	}

	return 0;
}