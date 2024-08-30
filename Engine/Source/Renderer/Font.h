#pragma once

#include "../Resources/Resources.h"
#include <string>
#include <SDL_ttf.h>

class Font : public Resource
{
public:
	Font() = default;
	~Font();

	// Inherited via Resource
	bool Create(std::string name, ...) override;
	bool Load(const std::string& name, int fontSize);

	//Allow class access to pr
	friend class Text;

	_TTF_Font* GetTTFFont() { return ttfFont; }

private:
	_TTF_Font* ttfFont{ nullptr };

};
