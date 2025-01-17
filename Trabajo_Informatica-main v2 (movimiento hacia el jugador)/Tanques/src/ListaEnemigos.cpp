#include "ListaEnemigos.h"

ListaEnemigos::ListaEnemigos() {
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		list[i] = 0;
}
ListaEnemigos::~ListaEnemigos() {}

bool ListaEnemigos::add(Enemigo* e) {
	int control = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		if (list[i] == e) {
			control++;
			return false;
		}

	if ((numero < MAX_ENEMIGOS) && (control == 0))
		list[numero++] = e; // �ltimo puesto sin rellenar
	else
		return false; // capacidad m�xima alcanzada
	return true;
}
void ListaEnemigos::destruirContenido() {
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
		delete list[i];
	numero = 0; // inicializa lista 
}
void ListaEnemigos::draw() {
	for (int i = 0; i < numero; i++)
		list[i]->drawtank();
}
void ListaEnemigos::refresh(float t, vector3D ori) {
	for (int i = 0; i < numero; i++)
		list[i]->refresh(t, ori);
}

Enemigo* ListaEnemigos::operator [](int i) {
	if (i >= numero)
		if (i < 0)
			i = 0;
	return list[i];
}

void ListaEnemigos::colision(tank& Tank) 
{
	for (int i = 0; i < numero; i++)
	{
		Interaction::choque(Tank, *(list[i]));	
	}
}
void ListaEnemigos::colision() 
{
	for (int i = 0; i < numero; i++)
	{
		for (int j= i+1; j<numero;j++)
			Interaction::choque(*list[i], *list[j]);
	}
}
/*void ListaEnemigos::colision(Wall& Pared) {
	for (int i = 0; i < numero; i++)
	{
		Interaction::colision(*list[i], Pared);
			
	}
}*/

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete list[index];
	numero--;
	for (int i = index; i < numero; i++)
		list[i] = list[i + 1];
}
void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (list[i] == e)
		{
			eliminar(i);
			return;
		}
}
