#include "FarnebackPlus.h"

//void FarnebackPlus::addForceToFluid( ofxFluid *fluid ) {
//    for ( int x = 0; x < flow.cols; x+=10 ) {
//        for ( int y = 0; y < flow.rows; y+=10 ) {
//            
//            float normX = x / (float)flow.cols;
//            float normY = y / (float)flow.rows;
//            // find the position in fluid space
//            ofPoint pos = ofPoint( normX * 1280.0, normY * 720.0 );
//            // get the velocity
//            const Vec2f& vec = flow.at<Vec2f>(y,x);
//            ofPoint v = ofPoint( vec[0], vec[1] );
//            
//            fluid->addTemporalForce( pos, v, ofFloatColor(1.0,1.0,1.0), 1.0 );
//            
//        }
//    }
//}

void FarnebackPlus::updateVectorFieldTexture() {
    int w = this->flow.cols, h = this->flow.rows;

    if ( vf.getWidth() != w || vf.getHeight() != h ) {
        cout << "allocating vector field texture and pixels" << endl;
        
        vf.allocate( w, h, OF_IMAGE_COLOR );

        /*
        float* pix = new float[w * h * 3];
        memset((char*)pix, 0x00, w * h * 3 * sizeof(float));
        vf.setFromPixels(pix, w, h, OF_IMAGE_COLOR);
        */
    }
    
    
    ofVec2f v;
    
    float max = -1;
    
    for(int x = 0; x < flow.cols; x++) {
        for(int y = 0; y < flow.rows; y++ ) {
          const Vec2f& vec = flow.at<Vec2f>(y,x);
          //const Vec2f& vec = flow.at<Vec2f>(x,y);
          v.set( vec[0], vec[1] );
          //         printf("%f, %f<--\n", v.x, v.y);
            int index = (y*w+x) * 3;
            if ( v.x > max ) {
                max = v.x;
            }
            if ( v.y > max ) {
                max = v.y;
            }
//            vf.getPixels()[index+0] = ofMap( v.x, -100.0f, 100.0f, 0, 1.0, true );
//            vf.getPixels()[index+1] = ofMap( v.y, -100.0f, 100.0f, 0, 1.0, true );

#if 0
            bool xnan = (v.x != v.x);
            bool ynan = (v.y != v.y);
            if(!xnan) {
              vf.getPixels()[index+0] = v.x;
            }
            if(!ynan) {
              vf.getPixels()[index+1] = v.y;
            }
#else 
            vf.getPixels()[index+0] = v.x;
            vf.getPixels()[index+1] = v.y;

#endif
            vf.getPixels()[index+2] = 0;
        }
    }
    
    vf.update();
}
