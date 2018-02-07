#ifndef __PARSER_H__
#define __PARSER_H__
#include "Face.h"
#include "Vertex.h"
#include "Normal.h"
#include "Texture.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



class Parser{
public:
  std::vector<Face> f;

	Parser(){};
	std::vector<Face>& readFile(std::string filename);
std::vector<Face> getVector(){return f;};

};
#endif