#ifndef BLOB_INFO_H
#define BLOB_INFO_H

#include <list>
class BlobsInfo {

public:
	BlobsInfo() = default;
	BlobsInfo(BlobsInfo const & blob) = default;
	BlobsInfo(int xVal, int yVal, int areaVal);
	~BlobsInfo() = default;

	BlobsInfo& operator=(BlobsInfo const & blob) = default;
	bool operator==(BlobsInfo const & b) const;

	int x;
	int y;
	int area;

};

using Blobs = std::list<BlobsInfo>;

#endif // BLOB_INFO_H