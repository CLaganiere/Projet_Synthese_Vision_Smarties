#include "ARGBFormat.h"

std::vector<img_t *> ARGBFormat::perform(std::vector<img_t *> const & vectImage)
{
	
	for (auto & image : vectImage) {
		if ((*image).format() != QImage::Format::Format_ARGB32) {
			*image = (*image).convertToFormat(QImage::Format_ARGB32);
		}
	}

	return vectImage;
}
