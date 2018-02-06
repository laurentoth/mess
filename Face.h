// STL

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Parser.cpp"
#include "Vertex.h"
#include "Normal.h"
#include "Texture.h"
using namespace std;

class Face{

private:
  Vertex one;
  Vertex two;
  Vertex three;
  Vertex four;
  Normal normal;
  Texture texture1;
  Texture texture2;
  Texture texture3;
  Texture texture4;
  bool triangle;
  bool texture;


public:
	Face(){};
	Face(Vertex v1, Vertex v2, Vertex v3){one=v1; two=v2; three=v3;};
	Face(Vertex v1, Vertex v2, Vertex v3,Texture t1, Texture t2, Texture t3){one=v1; two=v2; three=v3; texture1=t1; texture2=t2; texture3=t3;};
	Face(Vertex v1, Vertex v2, Vertex v3,Texture t1, Texture t2, Texture t3, Normal n){one=v1; two=v2; three=v3; texture1=t1; texture2=t2; texture3=t3; normal=n;};
	Face(Vertex v1, Vertex v2, Vertex v3, Normal n){one=v1; two=v2; three=v3; normal=n;};
	Face(Vertex v1, Vertex v2, Vertex v3, Vertex v4){one=v1; two=v2; three=v3; four=v4;};
	Face(Vertex v1, Vertex v2, Vertex v3,Vertex v4,Texture t1, Texture t2, Texture t3, Texture t4){one=v1; two=v2; three=v3; four=v4; texture1=t1; texture2=t2; texture3=t3;};
	Face(Vertex v1, Vertex v2, Vertex v3,Vertex v4,Texture t1, Texture t2, Texture t3,Texture t4, Normal n){one=v1; two=v2; three=v3; four=v4; texture1=t1; texture2=t2; texture3=t3; texture4=t4; normal=n;};
	Face(Vertex v1, Vertex v2, Vertex v3, Vertex v4, Normal n){one=v1; two=v2; three=v3; four=v4; normal=n;};
Vertex	getV1(){return one;};
Vertex	getV2(){return two;};
Vertex	getV3(){return three;};
Vertex	getV4(){return four;};
Normal	getNormal(){return normal;};
Texture	getT1(){return texture1;};
Texture	getT2(){return texture2;};
Texture	getT3(){return texture3;};
Texture getT4(){return texture4;};
bool isTriangle(){if(triangle){return true;} return false;};
bool isTexture(){if(texture){return true;}return false;};

void	setV1(Vertex v1){ one =v1;};
void	setV2(Vertex v2){ two=v2;};
void	setV3(Vertex v3){ three=v3;};
void	setV4(Vertex v1){ four=v4;};
void	setNormal(Normal n){ normal=n;};
void	setT1(Texture t1){ texture1=t1;};
void	setT2(Texture t2{ texture2=t2;};
void	setT3(Texture t3){ texture3=t3;};
void setT4(Texture t4){ texture4=t4;};
void setIsTriangle(bool t){triangle=t;};
void setIsTexture(bool t){texture=t;};
};