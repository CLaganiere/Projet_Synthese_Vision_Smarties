#include "RGBFormat.h"

std::vector<img_t *> RGBFormat::perform(std::vector<img_t *> const & vectImage)
{

	for (auto & image : vectImage) {
		if ((*image).format() != QImage::Format::Format_RGB32) {
			*image = (*image).convertToFormat(QImage::Format_RGB32);
		}
	}

	return vectImage;
}
