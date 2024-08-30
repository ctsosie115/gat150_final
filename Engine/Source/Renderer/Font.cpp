#include "..//../Source/Renderer/Font.h"
#include <iostream>
#include <string>
#include <cstdarg>

Font::~Font()
{
	if (ttfFont != nullptr)
	{
		TTF_CloseFont(ttfFont);
	}
}

bool Font::Load(const std::string& name, int fontSize)
{
	ttfFont = TTF_OpenFont(name.c_str(), fontSize);

	if (ttfFont == nullptr)
	{
		std::cerr << "Could not load font: " << name << std::endl;
		return false;
	}
	 
	return true;
}

bool Font::Create(std::string name, ...)
{
	va_list args;
	va_start(args, name);
	int font_size = va_arg(args, int);
	
	va_end(args);

	return Load(name, font_size); 
}
