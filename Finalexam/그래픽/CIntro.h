#pragma once
#include"define.h"
class CIntro{
	bool m_bIntro;


public:
	CIntro();
	~CIntro();
	void Update();
	void Render();
	void Reshape(int, int);
};