#include "Parser.h"
using namespace std;
std::vector<Face>& Parser::readFile(std::string filename){
	//Parser Method that takes the filename in and parses as needed
  ifstream inFile;
    std::vector <Vertex> v;
    std::vector<Face> f;
  int currentIndexVertex=0;
  std::vector <Normal> normals;
  int currentIndexNormals=0;
  std::vector<Face> faces;
  int currentIndexFaces=0;
  std::vector<Texture >textures;
  int currentIndexTextures=0;
  int numVertex=0;
  int numIndicies=0;
  bool wireFrame=false; 
  bool pointModel=false;
  bool solidModel=true;
  bool textureHere=true;

  if(filename.find("obj") == std::string::npos){
    cout << "File is not supported please provide an obj file" << endl;

  }

  else{
          inFile.open(filename.c_str());
          string line;
          float point;

      while (getline(inFile,line))
      {    
      cout << "Line: " << line << endl;    
            if(line.substr(0,1).compare("f")==0){

                          int vertex1;
                          int texture1;
                          int normal1;
                          line = line.substr(2);
                          int count=0;                       
                          Face newFace;
                          //Counts how many pairs are there
                          for(int i=0; i<line.size(); i++){
                            if(line[i]=='/')
                              count++;
                          }                 
                        
                          for(int x=0; x<2; x++){
                               vertex1 = std::stoi(line.substr(0,line.find("/")));
                               line = line.substr(line.find("/")+1);

                               if(textureHere){
                                 texture1 = std::stoi(line.substr(0,line.find("/")));
                                }

                               line = line.substr(line.find("/")+1);
                               normal1 =std::stoi(line.substr(0,line.find(" ")));
                               line = line.substr(line.find(" ")+1);
                            
                                if(x==0){
                                  newFace.setV1(v[vertex1-1]);
                                  if(textureHere){
                                     newFace.setT1(textures[texture1-1]);
                                  }
                                   newFace.setNormal(normals[normal1-1]);
                               }

                               if(x==1){
                                  newFace.setV2(v[vertex1-1]);
                                if(textureHere){
                                  newFace.setT2(textures[texture1-1]);
                                }
                              }

                           }

                          vertex1 = std::stoi(line.substr(0,line.find("/")));
                          line = line.substr(line.find("/")+1);
                          if(textureHere){
                              texture1 = std::stoi(line.substr(0,line.find("/")));
                             newFace.setT3(textures[texture1-1]);
                          }
                           normal1 =std::stoi(line.substr(line.find("/")+1));
                          newFace.setV3(v[vertex1-1]);
                          newFace.setIsTriangle(true);
                        
                        if(count>6){    
                          newFace.setIsTriangle(false);
                          line = line.substr(line.find(" ")+1);
                          vertex1 = std::stoi(line.substr(0,line.find("/")));
                        line = line.substr(line.find("/")+1);
                        if(textureHere){
                          texture1 = std::stoi(line.substr(0,line.find("/")));
                          newFace.setT4(textures[texture1-1]);
                        }
                        normal1 =std::stoi(line.substr(line.find("/")+1));
                         newFace.setV4(v[vertex1-1]);
                        }

                        faces.push_back(newFace);
                        currentIndexFaces++;
                        numIndicies++;

          
                 }

            //Case for texture
        else if (line.substr(0,2).compare("vt")==0){
                  textureHere=true;
                  Texture newText;
                  line = line.substr(3);
                  std::istringstream in(line);
                  float point;

                  in>>point;
                  newText.setX(point);   
                  in>>point;
                  newText.setY(point);
                  textures.push_back(newText);
                  currentIndexTextures++;

          }

             //Case for normals
          else if (line.substr(0,2).compare("vn")==0){
                  Normal newNormal;
                  line = line.substr(3);
                  std::istringstream in(line);
                  float point;
                  for(int x=0; x<2; x++){

                    if(x==0){
                      in >>point;
                      newNormal.setX(point);
                    }
                    if(x==1){
                      in >>point;
                      newNormal.setY(point);
                    }
                  }
                  in>>point;
                  newNormal.setZ(point);
                  normals.push_back(newNormal);
                  currentIndexNormals++;
          }

              //Case for the vertex
          else if(line.substr(0,1).compare("v")==0){

                    Vertex newVertex;
                    line = line.substr(2);

                    std::istringstream in(line);
                    float point;
                    for(int x=0; x< 2; x++){
                      if(x==0){
                        in>>point;

                        newVertex.setX(point);
                      }
                      if(x==1){
                       in>>point;
                       newVertex.setY(point);

                     }
                   }
                   in>>point;

                   newVertex.setZ(point);
                   cout << "Adding Vertex " << endl;  
                   v.push_back(newVertex);
                   cout << "Added Vertex " << endl;                   
                   currentIndexVertex++;
                   numVertex++;
                    
         	}
        }
  inFile.close();
    }
    cout << "Returing f " << endl;
    return f;
}
