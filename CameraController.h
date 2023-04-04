#pragma once
#include "Camera.h"
#include "Timer.h"

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

	float GetNewTop()
	{
		return cam->camBounds.top - GetPos().y;
	}

	void MoveCam(float speed)
	{
		AddPos({ 0, -speed * static_cast<float>(Timer::Get().GetElapsedSeconds()) });
	}

private:
	Camera* cam;
};

