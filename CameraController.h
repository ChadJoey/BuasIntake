#pragma once
#include "Camera.h"
#include "Timer.h"

class CameraController
{
public:
	CameraController(Camera* cam):
	cam(cam){}

	//return position of the camera
	Tmpl8::vec2 GetPos() 
	{
		return cam->camPos;
	}

	//sets position for the camera
	void SetPos(Tmpl8::vec2 newPos) 
	{
		cam->camPos = newPos;
	}
	//adds to the position of camera
	void AddPos(Tmpl8::vec2 addPos) 
	{
		cam->camPos.y += addPos.y;
	}

	//resets the camera's position
	void reset()
	{
		cam->camPos = { 0,0 };
	}

	//return top bound for the camera
	float GetTop()
	{
		return cam->camBounds.top;
	}

	//move the camera up
	void MoveCam(float speed)
	{
		if (!canCamMove)
		{
			return;
		}
		AddPos({ 0, -speed * static_cast<float>(Timer::Get().GetElapsedSeconds()) });
	}

private:
	Camera* cam;
	bool canCamMove = true;
};

