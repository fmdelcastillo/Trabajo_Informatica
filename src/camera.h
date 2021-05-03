#pragma once
#include "structs.h"
class camera{
	float pi=3.14159295358979323846264;
	float orientation;
	vector3D *objective;
	float distance;
	float elevation;
public:
	camera();
	void refresh(bool key[]);
	void drawcamera();
	void getobjectivedirection(vector3D* obj );
	float* getorientationdirection();
};