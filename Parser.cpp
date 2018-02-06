//Read File
// STL
#include "Parser.h"

using namespace std;

    vector<Face> f Parser::readFile(std::string filename){
      ifstream inFile;
      vector<Face> face;
       vector <Vertex> vertex;
      int currentIndexVertex=0;
     vector <Normal> normals;
    int currentIndexNormals=0;
 
      int currentIndexFaces=0;
      vector<Texture >textures;
    int currentIndexTextures=0;
    int numVertex=0;
    int numIndicies=0;

     
      if(filename.find("obj") == std::string::npos){
        cout << "File is not supported please provide an obj file" << endl;

      }
      else{

        inFile.open(filename.c_str());
        string line;
        GLfloat point;

        while (getline(inFile,line))
        {

    //If it is a comment
          cout << line << endl;

          if(line.substr(0,1).compare("#")==0){

          }




          if(line.substr(0,1).compare("f")==0){
           
           
          //   int vertex1;
          //   int texture1;
          //   int normal1;
          //   line = line.substr(2);
          //   faces_t newFace;
           
          //   for(int x=0; x<2; x++){
          //    vertex1 = std::stoi(line.substr(0,line.find("/")));
          //     line = line.substr(line.find("/")+1);
            
          //   if(textureHere){
          //    texture1 = std::stoi(line.substr(0,line.find("/")));
            
          //    }
          //     line = line.substr(line.find("/")+1);

          //    normal1 =std::stoi(line.substr(0,line.find(" ")));

          //    line = line.substr(line.find(" ")+1);
           

          //    if(x==0){
          //      newFace.one = vertex[vertex1-1];
          //      if(textureHere){
          //      newFace.texture1=textures[texture1-1];
          //      }
          //      newFace.normal=normals[normal1-1];
          //    }
          //    if(x==1){
          //     newFace.two=vertex[vertex1-1];
          //     if(textureHere){
          //     newFace.texture2=textures[texture1-1];
          //     }
          //   }



          // }
          // vertex1 = std::stoi(line.substr(0,line.find("/")));
          // line = line.substr(line.find("/")+1);
          // if(textureHere){
          // texture1 = std::stoi(line.substr(0,line.find("/")));
          //   newFace.texture3=textures[texture1-1];
          // }
          // normal1 =std::stoi(line.substr(line.find("/")+1));
         

         
          // newFace.three = vertex[vertex1-1];
           std::istringstream in(line,'/'); 
            Face *f;
            if(line.substr(line.find("/")+1).compare("/")==0){
              f->setIsTexture(false);
            }
            int count=0;
            for(int i=0; i<line.size(); i++){
              if(line[i]=='/')
                count++;
            }
                     

            int vertex1;
            int vertex2;
            int vertex3;
            int texture1;
            int texture2;
            int texture3;
            int texture4;
            int normal1;
            in>>vertex1;

            if(f->isTexture()){
              in>>texture1;
              f->setT1(textures[texture1]);
            }
            in>> normal1;
             f->setV1(Vertex[vertex1]);
            f->setNormal(Normal[normal1]);


             in>>vertex2;
            if(f->isTexture()){
              in>>texture2;
              f->setT2(textures[texture2]);
            }
            in>> normal1;
            f->setV2(Vertex[vertex2]);

             in>>vertex3;
            if(f->isTexture()){
              in>>texture3;
              f->setT3(textures[texture3]);
            }
            in>> normal1;
            f->setV2(Vertex[vertex3]);

            if(count>6){
              in>>vertex4;
            if(f->isTexture()){
              in>>texture4;
              f->setT4(textures[texture4]);
            }
            f->setV2(Vertex[vertex4]);
            in>> normal1;

            }
          faces.push_back(f);
          currentIndexFaces++;
          numIndicies++;
          
          delete f;
          
        }

      //Case for texture
        else if (line.substr(0,2).compare("vt")==0){
          Texture *t;
          textureHere=true;
          textures_t newText;
          line = line.substr(3);
          std::istringstream in(line);       
          in>>t->setX();   
          in>>t.setY();
          textures.push_back(t);
          currentIndexTextures++;
          delete t;

        }

       //Case for normals
        else if (line.substr(0,2).compare("vn")==0){
          Normal *n;
          line = line.substr(3);
          std::istringstream in(line);
          
              in >>n->setX();
              in >>n->setY();
          in>>n->setZ();
          normals.push_back(n);
          currentIndexNormals++;
          delete n;

        }

        //Case for the vertex
        else if(line.substr(0,1).compare("v")==0){
          Vertex *v;
          line = line.substr(2);
          std::istringstream in(line);
            in>>v->setX();
            in>>v->setY();
          in>>v->setZ();
          vertex.push_back(newVertex);
          currentIndexVertex++;
          numVertex++;
          delete v;
        }

        else{
          cout << "not a case" << endl;
        }


      }

      inFile.close();
    }
  }

  #if   defined(OSX)
#pragma clang diagnostic pop
#endif