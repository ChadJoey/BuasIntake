#pragma once
#include "Camera.h"

 class CameraController
{
public:
	CameraController(Camera* cam):
	cam(cam){}
	

	Tmpl8::vec2 GetPos() 
	{
		return cam->camPos;
	}

	void SetPos(Tmpl8::vec2 newPos) 
	{
		cam->camPos = newPos;
	}

	void AddPos(Tmpl8::vec2 addPos) 
	{
		cam->camPos += addPos;
	}

	void reset()
	{
		cam->camPos = { 0,0 };
	}

private:
	Camera* cam;
};

