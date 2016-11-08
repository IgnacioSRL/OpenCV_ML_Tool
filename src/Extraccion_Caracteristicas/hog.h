#ifndef HOG_H
#define HOG_H

#include "Herramientas/auxiliares.h"
#include "descriptor.h"

using namespace std;
using namespace cv;

namespace MLT {
    class HOG: public Descriptor{
    public:
        HOG(Size win_size=Size(64, 128),Size block_stride=Size(8, 8),
            double win_sigma=-1,double threshold_L2hys=0.2, bool gamma_correction=true,
            int nlevels=HOGDescriptor::DEFAULT_NLEVELS);
        ~HOG();
        int Extract(vector<Mat> Imagenes, vector<Mat> &Descriptores);
        int Mostrar(vector<Mat> Images, int scaleimage, int scalelines);
    private:
        cv::HOGDescriptor Hog;
        vector<Mat> Valores;
    };
}

#endif // HOG_H
