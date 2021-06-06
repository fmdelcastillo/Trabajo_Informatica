#include "Enemigo.h"
#include <stdio.h>
#include <Cstring>
#include <cmath>
#include "draw.h"
#include "freeglut.h"
#include "Disparo.h"
#include "tank.h"

#define pi 3.14159265358979323846264

Enemigo::Enemigo( ) {
	position.x = 4.0f;
	position.z = 4.0f;
	body_orientation = 90.0f;
	turret_orientation = 0.0f;
	speed = 2.0;
}

void Enemigo::setposition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;
}


void Enemigo::setbodyorientationrel(float dir) {
	body_orientation += dir;
}

void Enemigo::setturretorientation(float dir) {
	turret_orientation = dir;
}

void Enemigo::refresh(float t,vector3D ori) {
	/*mouse(mousepos, mousekey);
	keyactions(key, t);*/
	//
	float ganancia = 2;
	float dx = position.x - ori.x;
	float dz = position.z - ori.z;
	float orientacion = atan2(dx, dz);
	printf("%f", orientacion);
	position.x += -speed * cos(orientacion *ganancia) * t;
	position.z += speed * sin(orientacion *ganancia) * t;
	//	printf("posicion tanque=%f %f %f, posicion torreta= %f %f %f, posicionca�on=%f %f %f, posiciondisparo= %f %f %f\n",position.x,position.y,position.z,turret_relativeposition.x, turret_relativeposition.y, turret_relativeposition.z,canonrotao.x,canonrotao.y,canonrotao.z,disparorotao.x,disparorotao.y,disparorotao.z);

	

	
}
void Enemigo::drawtank() {
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	for (int i = 0; i < 20; i++) {
		glVertex3f(hitboxradius * cos(i * 2 * pi / 20), 0, hitboxradius * sin(i * 2 * pi / 20));
	}
	glEnd();

	glPopMatrix();
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glRotatef(body_orientation, 0, 1, 0);
	glTranslatef(hitboxradius * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(hitboxradius * 0.05, hitboxradius * 0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glColor3ub(0, 0, 255);
	glRotatef(turret_orientation, 0, 1, 0);
	glTranslatef(hitboxradius * 1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidCone(hitboxradius * 0.05, hitboxradius * 0.2, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
	glPopMatrix();
}
vector3D& Enemigo::getposition() {
	return position;
}

void Enemigo::setspeed(float v) {
	speed = v;
}