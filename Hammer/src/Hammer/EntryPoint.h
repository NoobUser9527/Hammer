#pragma once

#include<iostream>

#ifdef HM_PLATFORM_WINDOWS

extern Hammer::Application* Hammer::CreateApplication();

int main(int argc, char** argv)
{
	Hammer::Log::Init();
	HM_CORE_WARN("wadwadwdwa");
	int a = 5;
	HM_INFO("wadwadwdwa {0}", a);

	printf("aaaaaaaa");


	

	auto app = Hammer::CreateApplication();
	app->Run();
	delete app;
}


#endif