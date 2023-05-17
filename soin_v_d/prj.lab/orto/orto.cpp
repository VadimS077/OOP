#include<iostream>

namespace orto {
    class Quad {
    public:
        Quad() = default;
        Quad(double x1_, double x2_, double x3_, double x4_, double y1_, double y2_, double y3_, double y4_) {
            x1 = x1_;
            x2 = x2_;
            x3 = x3_;
            x4 = x4_;
            y1 = y1_;
            y2 = y2_;
            y3 = y3_;
            y4 = y4_;

        }
        Quad Intersect(Quad first,Quad second){}
        Quad Scale(Quad first,int k){
            x1 = cx + k * (x1 - cx);
            y1 = cy + k * (y1 - cy);
            x2 = cx + k * (x2 - cx);
            y2 = cy + k * (y2 - cy);
            x3 = cx + k * (x3 - cx);
            y3 = cy + k * (y3 - cy);
            x4 = cx + k * (x4 - cx);
            y4 = cy + k * (y4 - cy);
            return *this;
        }
        Quad Union(Quad first,Quad second){}
    protected:
        double x1 = 0;
        double y1=0;
        double x2=0;
        double y2 = 0;
        double x3 = 0;
        double y3=0;
        double x4 = 0;
        double y4 = 0;
        double cx = (x1 + x2) / 2;
        double cy = (y1 + y2) / 2;


    };
    class Rect :Quad {
        Rect() = default;
        Rect(double x1_, double x2_, double x3_, double x4_, double y1_, double y2_, double y3_, double y4_) {
            x1 = x1_;
            x2 = x2_;
            x3 = x3_;
            x4 = x4_;
            y1 = y1_;
            y2 = y2_;
            y3 = y3_;
            y4 = y4_;
        }
        Rect Intersect(Rect first,Rect second){}
        Rect Union(Rect first,Rect second){}
        Rect Scale(Rect first,int k) {
            x1 = cx + k * (x1 - cx);
            y1 = cy + k * (y1 - cy);
            x2 = cx + k * (x2 - cx);
            y2 = cy + k * (y2 - cy);
            x3 = cx + k * (x3 - cx);
            y3 = cy + k * (y3 - cy);
            x4 = cx + k * (x4 - cx);
            y4 = cy + k * (y4 - cy);
            return *this;
        }
    };
    class Square : Quad {
        Square() = default;
        Square(double x1_, double x2_, double x3_, double x4_, double y1_, double y2_, double y3_, double y4_) {
            x1 = x1_;
            x2 = x2_;
            x3 = x3_;
            x4 = x4_;
            y1 = y1_;
            y2 = y2_;
            y3 = y3_;
            y4 = y4_;
        }
        Square Intersect(Square first,Square second){}
        Square Union(Square first,Square second){}
        Square Scale(Square first,int k){
            x1 = cx + k * (x1 - cx);
            y1 = cy + k * (y1 - cy);
            x2 = cx + k * (x2 - cx);
            y2 = cy + k * (y2 - cy);
            x3 = cx + k * (x3 - cx);
            y3 = cy + k * (y3 - cy);
            x4 = cx + k * (x4 - cx);
            y4 = cy + k * (y4 - cy);
            return *this;

        }
    };
}