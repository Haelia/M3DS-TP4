#include "Revolution.h"

#include "glsupport.h"


#include "GLRender.h"

#include "Vector3.h"

#include "GLTool.h"


using namespace std;
using namespace p3d;

Revolution::Revolution() {
    // default profile
    _profile.push_back(Vector3(-0.8,0.6,0.0));
    _profile.push_back(Vector3(-0.3,0.2,0.0));
    _profile.push_back(Vector3(-0.9,-0.8,0.0));

}


void Revolution::initSphere() {
    vector<float> p;
    vector<float> n;
    vector<float> t;

    vector<unsigned int> index;

    int nbSlice=20; // include last slice that closes sphere
    int nbStack=20;
    double theta = 0;
    double phi = 0;

    for (int i = 0; i < nbStack; i++) {
        for (int j = 0; j < nbSlice; j++) {

            // Coordonnees des points
            p.push_back(cos(theta) * sin(phi));
            p.push_back(cos(phi));
            p.push_back(sin(theta) * sin(phi));

            // Normales
            n.push_back(cos(theta) * sin(phi));
            n.push_back(cos(phi));
            n.push_back(sin(theta) * sin(phi));

            // Coordonnees de texture
            t.push_back(-theta / (2 * M_PI));
            t.push_back(-phi / M_PI);
            theta += (2.*M_PI)/(20. - 1.);
        }
        theta=0;
        phi += M_PI/(20. - 1.);
    }

    for (int i = 0; i < nbStack - 1; i++) {
        for (int j = 0; j < nbSlice - 1; j++) {
            index.push_back((i*nbSlice) + j + nbSlice);
            index.push_back((i*nbSlice) + j);
            index.push_back((i*nbSlice) + j + 1);

            index.push_back((i*nbSlice) + j + 1);
            index.push_back((i*nbSlice) + j + nbSlice + 1);
            index.push_back((i*nbSlice) + j + nbSlice);

        }
    }


    initVAO(index,p,n,t);

    _texture = &_earth;

}


void Revolution::initCube() {
    vector<float> p;
    vector<float> n;
    vector<float> t;

    vector<unsigned int> index;

    // haut (3)
      p.push_back(-1);
      p.push_back(1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(1);
      n.push_back(0);

      t.push_back(0.66);
      t.push_back(0.5);

      p.push_back(-1);
      p.push_back(1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(1);
      n.push_back(0);

      t.push_back(1);
      t.push_back(0.5);

      p.push_back(1);
      p.push_back(1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(1);
      n.push_back(0);

      t.push_back(1);
      t.push_back(1);

      p.push_back(1);
      p.push_back(1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(1);
      n.push_back(0);

      t.push_back(0.66);
      t.push_back(1);

      //cote (2)
      p.push_back(-1);
      p.push_back(-1);
      p.push_back(-1);

      n.push_back(-1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.33);
      t.push_back(0.5);

      p.push_back(-1);
      p.push_back(-1);
      p.push_back(1);

      n.push_back(-1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.66);
      t.push_back(0.5);

      p.push_back(-1);
      p.push_back(1);
      p.push_back(1);

      n.push_back(-1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.66);
      t.push_back(1);

      p.push_back(-1);
      p.push_back(1);
      p.push_back(-1);

      n.push_back(-1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.33);
      t.push_back(1);


      //cote (1)
      p.push_back(-1);
      p.push_back(-1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(1);

      t.push_back(0);
      t.push_back(0.5);

      p.push_back(1);
      p.push_back(-1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(1);

      t.push_back(0.33);
      t.push_back(0.5);

      p.push_back(1);
      p.push_back(1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(1);

      t.push_back(0.33);
      t.push_back(1);

      p.push_back(-1);
      p.push_back(1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(1);

      t.push_back(0);
      t.push_back(1);

      //cote (5)
      p.push_back(1);
      p.push_back(-1);
      p.push_back(1);

      n.push_back(1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.33);
      t.push_back(0);

      p.push_back(1);
      p.push_back(-1);
      p.push_back(-1);

      n.push_back(1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.66);
      t.push_back(0);

      p.push_back(1);
      p.push_back(1);
      p.push_back(1);

      n.push_back(1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.33);
      t.push_back(0.5);

      p.push_back(1);
      p.push_back(1);
      p.push_back(-1);

      n.push_back(1);
      n.push_back(0);
      n.push_back(0);

      t.push_back(0.66);
      t.push_back(0.5);

      //cote (6)
      p.push_back(1);
      p.push_back(-1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(-1);

      t.push_back(0.66);
      t.push_back(0);

      p.push_back(-1);
      p.push_back(-1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(-1);

      t.push_back(1);
      t.push_back(0);

      p.push_back(1);
      p.push_back(1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(-1);

      t.push_back(0.66);
      t.push_back(0.5);

      p.push_back(-1);
      p.push_back(1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(0);
      n.push_back(-1);

      t.push_back(1);
      t.push_back(0.5);

      //bas (4)
      p.push_back(1);
      p.push_back(-1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(-1);
      n.push_back(0);

      t.push_back(0);
      t.push_back(0);

      p.push_back(1);
      p.push_back(-1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(-1);
      n.push_back(0);

      t.push_back(0.33);
      t.push_back(0);

      p.push_back(-1);
      p.push_back(-1);
      p.push_back(-1);

      n.push_back(0);
      n.push_back(-1);
      n.push_back(0);

      t.push_back(0.33);
      t.push_back(0.5);

      p.push_back(-1);
      p.push_back(-1);
      p.push_back(1);

      n.push_back(0);
      n.push_back(-1);
      n.push_back(0);

      t.push_back(0);
      t.push_back(0.5);

      // index
      int face = 4;
      for(int i = 0; i<3; i++){
          index.push_back(0 + i * face);
          index.push_back(1 + i * face);
          index.push_back(2 + i * face);
          index.push_back(0 + i * face);
          index.push_back(2 + i * face);
          index.push_back(3 + i * face);
      }

      for(int i = 3; i<5; i++){
          index.push_back(0 + i * face);
          index.push_back(1 + i * face);
          index.push_back(2 + i * face);
          index.push_back(1 + i * face);
          index.push_back(3 + i * face);
          index.push_back(2 + i * face);
      }

      index.push_back(0 + 5 * face);
      index.push_back(2 + 5 * face);
      index.push_back(1 + 5 * face);
      index.push_back(0 + 5 * face);
      index.push_back(3 + 5 * face);
      index.push_back(2 + 5 * face);



    initVAO(index,p,n,t);

    _texture=&_dice;
}


void Revolution::initRevolution() {
    if (_profile.size()<2) return; // more than 2 vertices in the profile

    vector<float> p;
    vector<float> n;
    vector<float> t;

    vector<unsigned int> index;

    int nbSlice=40; // include last slice that closes the object
    int nbStack=_profile.size();

    std::vector<Vector3> normalProfile; // to compute normal profile

    double theta = 0.;

    for(int i=0; i<nbStack; i++){

        for(int j=0; j<nbSlice; j++){

            Vector3 dir=_profile[i+1]-_profile[i];
            Vector3 norm= Vector3(-dir.y(),dir.x(),0.);
            Vector3 point = _profile[i].rotationY(theta);

            p.push_back(point.x());
            p.push_back(point.y());
            p.push_back(point.z());

            // Normales
            Vector3 normale = norm.rotationY(theta);
            n.push_back(normale.x());
            n.push_back(normale.y());
            n.push_back(normale.z());

            t.push_back(theta / (2*M_PI));
            t.push_back(i/_profile.size());


            theta += (2 * M_PI / (nbSlice - 1));
        }
        theta=0.;
    }

    for (int i = 0; i < nbStack - 1; i++) {
        for (int j = 0; j < nbSlice - 1; j++) {
            index.push_back((i*nbSlice) + j + nbSlice);
            index.push_back((i*nbSlice) + j);
            index.push_back((i*nbSlice) + j + 1);

            index.push_back((i*nbSlice) + j + 1);
            index.push_back((i*nbSlice) + j + nbSlice + 1);
            index.push_back((i*nbSlice) + j + nbSlice);

        }
    }






    initVAO(index,p,n,t);
    _texture=&_ul1;
}


void Revolution::init() {
    glGenBuffers(1,&_vbo);
    glGenBuffers(1,&_elementBuffer);
    glGenVertexArrays(1,&_vao);

    _earth.readMipmap("EarthDay512.jpg");
    _dice.readMipmap("dice.png");
    _ul1.readMipmap("UL1-IEEA.png");

}


void Revolution::draw(EShader mode) {
    //  return;
    glBindVertexArray(_vao);


    p3d::material(Vector4(0,0,0,1),Vector3(0,0.8,0.2),Vector3(0,0.2,0.8),100);
    p3d::diffuseBackColor=Vector3(0.8,0,0);
    if (mode==Shader_Ambient) {
        p3d::ambientColor=Vector4(0.0,0.8,0,1);
        p3d::ambientBackColor=Vector4(0.8,0.0,0,1);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }

    _texture->bind(0);

    switch(mode) {
    case Shader_Ambient:p3d::shaderVertexAmbient();break;
    case Shader_Light:p3d::shaderLightPhong();break;
    case Shader_Texture:p3d::shaderTextureLight();break;
    }


    glDrawElements(GL_TRIANGLES,_nbElement,GL_UNSIGNED_INT,0);



    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBindVertexArray(0);

}


// Caution : position should be a (x,y,z) array, normal (x,y,z) array, texCoord (x,y) array. lengths should be coherent
void Revolution::initVAO(const std::vector<unsigned int> &index,const std::vector<float> &position,const std::vector<float> &normal,const std::vector<float> &texCoord) {

    vector<float> attrib;
    attrib.resize(position.size()*8);
    for(unsigned int i=0;i<position.size()/3;++i) {
        attrib[i*8+0]=position[i*3+0];
        attrib[i*8+1]=position[i*3+1];
        attrib[i*8+2]=position[i*3+2];

        if (!normal.empty()) {
            attrib[i*8+3]=normal[i*3+0];
            attrib[i*8+4]=normal[i*3+1];
            attrib[i*8+5]=normal[i*3+2];
        }

        if (!texCoord.empty()) {
            attrib[i*8+6]=texCoord[i*2+0];
            attrib[i*8+7]=texCoord[i*2+1];
        }
    }



    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glBufferData(GL_ARRAY_BUFFER,attrib.size()*sizeof(float),attrib.data(),GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,index.size()*sizeof(unsigned int),index.data(),GL_STATIC_DRAW);
    _nbElement=index.size();

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),0);                                   // position
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(const GLvoid *)(3*sizeof(float)));   // normal
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(const GLvoid *)(6*sizeof(float)));   // texCoord

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementBuffer);

    glBindVertexArray(0);

}

void Revolution::drawProfile() {
    p3d::ambientColor=Vector4(1,0,0,1);
    p3d::shaderVertexAmbient();
    p3d::drawLineStrip(_profile);
    p3d::drawPoints(_profile);

    vector<Vector3> mirror;
    for(auto &p:_profile) {
        mirror.push_back(Vector3(-p.x(),p.y(),p.z()));
    }

    p3d::uniformAmbient(Vector4(0,0,0,1));
    p3d::drawLineStrip(mirror);
    p3d::drawPoints(mirror);

    p3d::uniformAmbient(Vector4(0,1,0,1));
    p3d::drawLines({Vector3(0,-1,0),Vector3(0,1,0)});



}



