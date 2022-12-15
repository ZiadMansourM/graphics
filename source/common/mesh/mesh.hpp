#pragma once

#include <glad/gl.h>
#include "vertex.hpp"

namespace our {

    #define ATTRIB_LOC_POSITION 0
    #define ATTRIB_LOC_COLOR    1
    #define ATTRIB_LOC_TEXCOORD 2
    #define ATTRIB_LOC_NORMAL   3

    class Mesh {
        // Here, we store the object names of the 3 main components of a mesh:
        // A vertex array object, A vertex buffer and an element buffer
        unsigned int VBO, EBO;
        unsigned int VAO;
        // We need to remember the number of elements that will be drawn by glDrawElements 
        GLsizei elementCount;
    public:

        // The constructor takes two vectors:
        // - vertices which contain the vertex data.
        // - elements which contain the indices of the vertices out of which each triangle will be constructed.
        // The mesh class does not keep a these data on the RAM. Instead, it should create
        // a vertex buffer to store the vertex data on the VRAM,
        // an element buffer to store the element data on the VRAM,
        // a vertex array object to define how to read the vertex & element buffer during rendering 
        Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& elements)
        {
            //TODO: (Req 2) Write this function
            // remember to store the number of elements in "elementCount" since you will need it for drawing
            // For the attribute locations, use the constants defined above: ATTRIB_LOC_POSITION, ATTRIB_LOC_COLOR, etc
            glGenVertexArrays(1, &VAO); // Generating the vertex array
            glBindVertexArray(VAO); // Bind the vertex array so that any upcoming operation after this line will use this vertex array (like pinning it to the project)
            
            glGenBuffers(1, &VBO); // Generating vertex buffer 
            glBindBuffer(GL_ARRAY_BUFFER, VBO); // Stating that its type is Array Buffer (3shan fe types kteer zy frame buffer w keda), binding the buffer
            glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &vertices[0], GL_STATIC_DRAW); //now we place the data i want to put inside the buffer
            // GL_ARRAY_BUFFER = Type of buffer (Array Buffer)
            // vertices.size()*sizeof(Vertex) = Size of data in bytes (vertices.size()=rows* sizeof(Vertex)=number of bits in each row)
            // &vertices[0] = array to be saved in buffer (contains the vertex data)
            // GL_STATIC_DRAW = httresem one time

            glGenBuffers(1, &EBO); //Generating element buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //binding the element buffer
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size()*sizeof(unsigned int), &elements[0], GL_STATIC_DRAW);//now we place the data i want to put inside the buffer
            elementCount = elements.size();


            //now ba2olo e2ra el data beta3et el vertices mel buffer bel shakl dah
            //Setting attribute for the postion
            glVertexAttribPointer(ATTRIB_LOC_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
            glEnableVertexAttribArray(ATTRIB_LOC_POSITION);
            //The value in ATTRIB_LOC_POSITION heya el location fel vertex shader attributes
            //el 3 deh el data hatebaa talatat 3shan el vec3 fel shader ya3ni by2ra 3 floats (specifies the size of the vertex attribute. The vertex attribute is a vec3 so it is composed of 3 values)
            //type float (the type of the data which is GL_FLOAT (a vec* in GLSL consists of floating point values))
            //normalized law true w not normalized law false byfre2 fel colour aktar (specifies if we want the data to be normalized. If we're inputting integer data types (int, byte) and we've set this to GL_TRUE, the integer data is normalized to 0 (or -1 for signed data) and 1 when converted to float. This is not relevant for us so we'll leave this at GL_FALSE.)
            //stride:(tells us the space between consecutive vertex attributes. akeno row kamel by3araf kol haga 3an el vertex deh
            //This is the offset of where the position data begins in the buffer. Since the position data is at the start of the data array this value is just 0
            ///////////
            glVertexAttribPointer(ATTRIB_LOC_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
            glEnableVertexAttribArray(ATTRIB_LOC_COLOR);
            ////////////
            glVertexAttribPointer(ATTRIB_LOC_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tex_coord));
            glEnableVertexAttribArray(ATTRIB_LOC_TEXCOORD);
            ////////////
            glVertexAttribPointer(ATTRIB_LOC_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
            glEnableVertexAttribArray(ATTRIB_LOC_NORMAL);
        
        }

        // this function should render the mesh
        void draw() 
        {
            //TODO: (Req 2) Write this function
            glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, (void*)0);
            //GL_TRIANGLES: 3shan bnrsem triangles fa mode triangles
            //elementCount=6: number of elements to be rendered 
            //GL_UNSIGNED_INT: type of values of indices
            //(void*)0: specify law fe offset men el first index hena
        }

        // this function should delete the vertex & element buffers and the vertex array object
        ~Mesh(){
            //TODO: (Req 2) Write this function
            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
            glDeleteBuffers(1, &EBO);
        }

        Mesh(Mesh const &) = delete;
        Mesh &operator=(Mesh const &) = delete;
    };

}