#include "MonoChrome.h"

std::vector<img_t*> MonoChrome::perform(std::vector<img_t*> const & vectImage)
{
	for (auto & image : vectImage) {
		*image = image->convertToFormat(img_t::Format_Grayscale8).convertToFormat(img_t::Format_ARGB32);
	}

	return vectImage;
}
