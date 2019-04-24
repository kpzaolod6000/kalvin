class PointArray{
    int size;
    Point *points;
    public:
        PointArray();
        PointArray(const Point pts[],const int size);
        PointArray (const PointArray &pv);
        ~PointArray();
        
};