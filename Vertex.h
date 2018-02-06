// STL

using namespace std;
class Vertex{

private:
	GLfloat x;
	GLfloat y;
	GLfloat z;

public:
	Vertex(GLfloat xcoor, GLfloat ycoor, GLfloat zcoor){x=xcoor; y=ycoor; z=zcoor;};
	GLfloat getX(){return x;};
	GLfloat getY(){return y;};
	GLfloat getZ(){return z;};
	void setX(GLfloat xcoor){x = xcoor;};
	void setY(GLfloat ycoor){y = ycoor;};
	void setZ(GLfloat zcoor){z = zcoor;};
};