#ifndef GRAPHICOBJECT
#define GRAPHICOBJECT

class QPainter;

class GraphicObject {
public:
	virtual ~GraphicObject() {}
	virtual void draw(QPainter& painter) const = 0;

    virtual void set_initial_position(int x, int y) {
        x_ = x;
        y_ = y;
    }

    virtual void set_extents(int a, int b) = 0;

protected:
    int x() const {return x_;}
    int y() const {return y_;}

private:
    int x_=0, y_=0;
};

#endif // GRAPHICOBJECT

