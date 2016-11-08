#ifndef BASIC_TRANSFORMATIONS_H
#define BASIC_TRANSFORMATIONS_H

#include "Herramientas/auxiliares.h"
#include "descriptor.h"

namespace MLT {
    class Basic_Transformations: public  Descriptor{
    public:
        Basic_Transformations(int input_type, int output_type);
        ~Basic_Transformations();
        int Extract(vector<Mat> Imagenes, vector<Mat> &Descriptores);

    private:
        int input,output;
    };
}

#endif // BASIC_TRANSFORMATIONS_H
