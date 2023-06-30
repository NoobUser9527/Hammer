#include "hammer.h"

class Chess : public Hammer::Application
{
public:
	Chess()
	{

	}

	~Chess()
	{

	}
};

Hammer::Application* Hammer::CreateApplication()
{
	return new Chess();
}

