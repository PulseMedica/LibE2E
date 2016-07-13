#pragma once

#include <map>

#include "bscan.h"
#include "substructure_template.h"

namespace E2E
{

	class Image;

	class CScan : public SubstructureTemplate<BScan>
	{
		Image* sloImage = nullptr;
		std::vector<Image*> pixmaps;
		// image
	public:
		CScan();
		virtual ~CScan();

		      BScan& getBScan(int bscanId)                      { return getAndInsert(bscanId)         ; }
		const BScan& getBScan(int bscanId) const                { return *(substructureMap.at(bscanId)); }

		std::size_t getBScanSize() const                        { return substructureMap.size(); }


		const Image* getSloImage() const                        { return sloImage; }
		void   takeSloImage(Image* img);

		const std::vector<Image*>& getPixmaps() const           { return pixmaps; }
		void takePixmap(Image* img)                             { pixmaps.push_back(img); }
	};


}