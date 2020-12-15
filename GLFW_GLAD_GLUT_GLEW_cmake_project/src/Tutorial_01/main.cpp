#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include "filesystem.h"
#include "shader_s.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Rubik.h"
#include "solver/solver.h"

CuboRubik Ideal(0);
CuboRubik Copia(5);


CuboRubik Rubik(0);
CuboRubik IdealCopia(5);

float* verticex1;
float* verticex2;

float* verticex3;
float* verticex4;

vector<string> movimientos_vector;
string movimientos;
bool solver_activo = false;
int contador = 0;
string mov_ingreso = "";
bool veri = false;


void solver_start() {
    
    string solucion[] = {
        "UF", "UR", "UB", "UL",
        "DF", "DR", "DB", "DL",
        "FR", "FL",
        "BR", "BL",
        "UFR", "URB", "UBL", "ULF",
        "DRF", "DFL", "DLB", "DBR"
    };

    string no_solution[20];
    no_solution[0] = Rubik.cubo18->tipo_cubo;  // UF
    no_solution[1] = Rubik.cubo26->tipo_cubo;  // UR
    no_solution[2] = Rubik.cubo16->tipo_cubo;  // UB
    no_solution[3] = Rubik.cubo8->tipo_cubo;   // UL

    no_solution[4] = Rubik.cubo12->tipo_cubo;  // DF
    no_solution[5] = Rubik.cubo20->tipo_cubo;  // DR
    no_solution[6] = Rubik.cubo10->tipo_cubo;  // DB
    no_solution[7] = Rubik.cubo2->tipo_cubo;   // DL

    no_solution[8] = Rubik.cubo24->tipo_cubo;  // FR
    no_solution[9] = Rubik.cubo6->tipo_cubo;   // FL
    no_solution[10] = Rubik.cubo22->tipo_cubo; // BR
    no_solution[11] = Rubik.cubo4->tipo_cubo;  // BL

    no_solution[12] = Rubik.cubo27->tipo_cubo;  // UFR
    no_solution[13] = Rubik.cubo25->tipo_cubo;  // URB
    no_solution[14] = Rubik.cubo7->tipo_cubo;   // UBL
    no_solution[15] = Rubik.cubo9->tipo_cubo;   // ULF

    no_solution[16] = Rubik.cubo21->tipo_cubo;  // DRF
    no_solution[17] = Rubik.cubo3->tipo_cubo;   // DFL
    no_solution[18] = Rubik.cubo1->tipo_cubo;   // DLB
    no_solution[19] = Rubik.cubo19->tipo_cubo;  // DBR

    for (int i = 0; i < 20; i += 4) {
        cout << "\"" << no_solution[i] << "\", \"" << no_solution[i + 1] << "\", "
            << "\"" << no_solution[i + 2] << "\", \"" << no_solution[i + 3] << endl;
    }
    vector<string> moves(solve(no_solution, solucion));
    /*cout << "MOVIMIENTOS: ";
    for (auto i : moves) {
        cout << i << " ";
    }*/

    movimientos = "";
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i][1] == '1') {
            movimientos += moves[i][0];
        }
        else if (moves[i][1] == '2') {
            movimientos += moves[i][0];
            movimientos += moves[i][0];

        }
        else if (moves[i][1] == '3') {
            movimientos += moves[i][0];
            movimientos += moves[i][0];
            movimientos += moves[i][0];
        }
        /*else if (moves[i][1] == '4') {
            movimientos += moves[i][0];
            movimientos += moves[i][0];
            movimientos += moves[i][0];
            movimientos += moves[i][0];
        }*/
    }


    cout << endl;
}


void valueee() {
    string solucion[] = {
        "UF", "UR", "UB", "UL",
        "DF", "DR", "DB", "DL",
        "FR", "FL",
        "BR", "BL",
        "UFR", "URB", "UBL", "ULF",
        "DRF", "DFL", "DLB", "DBR"
    };

    string no_solution[20];
    no_solution[0] = Rubik.cubo18->tipo_cubo;  // UF
    no_solution[1] = Rubik.cubo26->tipo_cubo;  // UR
    no_solution[2] = Rubik.cubo16->tipo_cubo;  // UB
    no_solution[3] = Rubik.cubo8->tipo_cubo;   // UL

    no_solution[4] = Rubik.cubo12->tipo_cubo;  // DF
    no_solution[5] = Rubik.cubo20->tipo_cubo;  // DR
    no_solution[6] = Rubik.cubo10->tipo_cubo;  // DB
    no_solution[7] = Rubik.cubo2->tipo_cubo;   // DL

    no_solution[8] = Rubik.cubo24->tipo_cubo;  // FR
    no_solution[9] = Rubik.cubo6->tipo_cubo;   // FL
    no_solution[10] = Rubik.cubo22->tipo_cubo; // BR
    no_solution[11] = Rubik.cubo4->tipo_cubo;  // BL

    no_solution[12] = Rubik.cubo27->tipo_cubo;  // UFR
    no_solution[13] = Rubik.cubo25->tipo_cubo;  // URB
    no_solution[14] = Rubik.cubo7->tipo_cubo;   // UBL
    no_solution[15] = Rubik.cubo9->tipo_cubo;   // ULF

    no_solution[16] = Rubik.cubo21->tipo_cubo;  // DRF
    no_solution[17] = Rubik.cubo3->tipo_cubo;   // DFL
    no_solution[18] = Rubik.cubo1->tipo_cubo;   // DLB
    no_solution[19] = Rubik.cubo19->tipo_cubo;  // DBR


    bool equal = true;

    for (int i = 0; i < 20; ++i) {
        if (solucion[i] != no_solution[i]) {
            equal = false;
            break;
        }
    }

    if (equal) {
        Rubik.arreglar(&Ideal, verticex1, verticex2);
        Rubik.start(verticex1, verticex2, 1);
        cout << "NO SE PUDO RESOLVER" << endl;
        veri = true;
    }
}





// CUBO
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180)  
unsigned int texture1, texture2, texture3;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);


using namespace std;
// camera
glm::vec3 cameraPos = glm::vec3(0.0f, 2.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 0.5f, 0.0f);

bool firstMouse = true;
float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float mixValue = 0.2f;


bool an1 = false;
bool an2 = false;
bool an3 = false;
bool an4 = false;

bool copia = false;


int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);


    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("D://UCSP//Graphics//GLFW_GLAD_GLUT_GLEW_cmake_project//src//Tutorial_01//shader.vs", "D://UCSP//Graphics//GLFW_GLAD_GLUT_GLEW_cmake_project//src//Tutorial_01//shader.fs");



    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    verticex1 = new float[2592];
    verticex2 = new float[5184];

    verticex3 = new float[2592];
    verticex4 = new float[5184];

    //Rubik.start(verticex1, verticex2, 0);

    // Rubik Ideal
    cout << "---------------" << endl;
    /*cout << Rubik.compara_cubos(Ideal.cubo8, Rubik.cubo8) << endl;*/
    Rubik.move4_data(&Ideal, verticex1, verticex2);
    Copia.move4_data(&IdealCopia, verticex3, verticex4);

    cout << "---------------" << endl;



    unsigned int VBO[4], VAO[4];
    glGenVertexArrays(4, VAO);
    glGenBuffers(4, VBO);

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticex1[0]) * 2592, verticex1, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticex2[0]) * 5184, verticex2, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindVertexArray(VAO[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticex3[0]) * 2592, verticex3, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindVertexArray(VAO[3]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticex4[0]) * 5184, verticex4, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);




    // load and create a texture 
    // -------------------------

    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrappin  g to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load(FileSystem::getPath("letras/U.jpg").c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);



    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
    // or set it via the texture class
    ourShader.setInt("texture2", 1);
    ourShader.setInt("texture3", 2);

    int fcont = 0;
    cout << "W A S D - para trasladar la cámara" << endl;
    cout << "Q E - para la textura" << endl;
    cout << "Mouse para rotar cámara" << endl;

    cout << "\nCOMANDOS RUBIK" << endl;
    cout << "Z = DOWN" << endl;
    cout << "X = UP" << endl;
    cout << "C = BACK" << endl;
    cout << "V = FRONT" << endl;
    cout << "B = LEFT" << endl;
    cout << "N = RIGHT" << endl;

    cout << "F = DOWN Reverse" << endl;
    cout << "G = UP Reverse" << endl;
    cout << "H = BACK Reverse" << endl;
    cout << "J = FRONT Reverse" << endl;
    cout << "K = LEFT Reverse" << endl;
    cout << "L = RIGHT Reverse" << endl;

    cout << "1 = MID" << endl;
    cout << "2 = MID" << endl;
    cout << "3 = MID" << endl;
    cout << "4 = REVERSE MID" << endl;
    cout << "5 = REVERSE MID" << endl;
    cout << "6 = REVERSE MID" << endl;

    cout << "UP DOWN LEFT RIGHT :::: PARA ANIMAR EL CUBO" << endl;
    cout << "ENTER :::: PARA RESOLVER EL CUBO" << endl;

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        fcont++;
        if (fcont % 100 == 0) {
            glClearColor(
                (GLfloat)(rand() % 100) / 100.0f,
                (GLfloat)(rand() % 100) / 100.0f,
                (GLfloat)(rand() % 100) / 100.0f, 1.0f
            );
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // activate shader
        ourShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        ourShader.setMat4("view", view);

        Rubik.start(verticex1, verticex2, 1);
        Copia.start(verticex3, verticex4, 1);
        if (an1 == true) {
            Rubik.animar1(verticex1, verticex2);
            an1 = false;        
        }
        if (an2 == true) {
            Rubik.animar2(verticex1, verticex2);
            an2 = false;
        }
        if (an3 == true) {
            Rubik.animar3(verticex1, verticex2);
            an3 = false;
        }
        if (an4 == true) {
            Rubik.animar4(verticex1, verticex2);
            an4 = false;
        }

        if (1) {
            glBindVertexArray(VAO[0]);
            glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(verticex1[0]) * 2592, verticex1, GL_STATIC_DRAW);
            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            ourShader.setFloat("mixValue", mixValue);

            ourShader.use();
            glBindVertexArray(VAO[0]);
            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

            ourShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 324); // 36 por cubo
        }

       

        if (1) {
            glBindVertexArray(VAO[1]);
            glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(verticex2[0]) * 5184, verticex2, GL_STATIC_DRAW);

            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            ourShader.setFloat("mixValue", mixValue);

            ourShader.use();
            glBindVertexArray(VAO[1]);
            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
            float ejes[3]{ 0.1f,0.0f,0.0f };
            ourShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 648);
        }



        if (copia) {
            glBindVertexArray(VAO[3]);
            glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(verticex4[0]) * 5184, verticex4, GL_STATIC_DRAW);

            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            ourShader.setFloat("mixValue", mixValue);

            ourShader.use();
            glBindVertexArray(VAO[3]);
            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
            float ejes[3]{ 0.1f,0.0f,0.0f };
            ourShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 648);


            glBindVertexArray(VAO[2]);
            glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(verticex3[0]) * 2592, verticex3, GL_STATIC_DRAW);
            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            ourShader.setFloat("mixValue", mixValue);

            ourShader.use();
            glBindVertexArray(VAO[2]);
            model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

            ourShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 324); // 36 por cubo

        }




        if (solver_activo) {
            int limit = movimientos.length();

            if (contador < limit) {
                if (!Rubik.mov1 && !Rubik.mov3 && !Rubik.mov4 && !Rubik.mov6 && !Rubik.mov7 && !Rubik.mov9 &&
                    !Rubik.mov10 && !Rubik.mov12 && !Rubik.mov13 && !Rubik.mov15 && !Rubik.mov6 && !Rubik.mov8) {
                    if (movimientos[contador] == 'D') {
                        Rubik.mov1 = true;
                        Rubik.move1_data(&Ideal, verticex1, verticex2);
                    }
                    else if (movimientos[contador] == 'U') {
                        Rubik.mov3 = true;
                        Rubik.move3_data(&Ideal, verticex1, verticex2);
                    }
                    else if (movimientos[contador] == 'B') {
                        Rubik.mov4 = true;
                        Rubik.move4_data(&Ideal, verticex1, verticex2);
                    }
                    else if (movimientos[contador] == 'F') {
                        Rubik.mov6 = true;
                        Rubik.move6_data(&Ideal, verticex1, verticex2);
                    }
                    else if (movimientos[contador] == 'L') {
                        Rubik.mov7 = true;
                        Rubik.move7_data(&Ideal, verticex1, verticex2);
                    }
                    else if (movimientos[contador] == 'R') {
                        Rubik.mov9 = true;
                        Rubik.move9_data(&Ideal, verticex1, verticex2);
                    }
                    ++contador;
                }
            }
            else {
                solver_activo = false;
                movimientos = "";
                contador = 0;
                valueee();
                
            }
        }


        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, texture3);
        // render container

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(4, VAO);
    glDeleteBuffers(4, VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    //float cameraSpeed = 2.5 * deltaTime;
    float cameraSpeed = 5 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    float vec_dir[3] = { 0,0,0 };


    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        mixValue += 0.05f; // change this value accordingly (might be too slow or too fast based on system hardware)
        if (mixValue >= 1.0f)
            mixValue = 1.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        mixValue -= 0.05f; // change this value accordingly (might be too slow or too fast based on system hardware)
        if (mixValue <= 0.0f)
            mixValue = 0.0f;
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov1 = true;
            Rubik.move1_data(&Ideal, verticex1, verticex2);
            mov_ingreso += "D";

            Copia.mov1 = true;
            Copia.move1_data(&IdealCopia, verticex3, verticex4);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov2 = true;
            Rubik.move2_data(&Ideal, verticex1, verticex2);

            Copia.mov2 = true;
            Copia.move2_data(&IdealCopia, verticex3, verticex4);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov3 = true;
            Rubik.move3_data(&Ideal, verticex1, verticex2);
            mov_ingreso += "U";

            Copia.mov3 = true;
            Copia.move3_data(&IdealCopia, verticex3, verticex4);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov4 = true;
            Rubik.move4_data(&Ideal, verticex1, verticex2);
            mov_ingreso += "B";

            Copia.mov4 = true;
            Copia.move4_data(&IdealCopia, verticex3, verticex4);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov5 = true;
            Rubik.move5_data(&Ideal, verticex1, verticex2);
            Copia.mov5 = true;
            Copia.move5_data(&IdealCopia, verticex3, verticex4);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov6 = true;
            Rubik.move6_data(&Ideal, verticex1, verticex2);
            mov_ingreso += "F";

            Copia.mov6 = true;
            Copia.move6_data(&IdealCopia, verticex3, verticex4);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov7 = true;
            Rubik.move7_data(&Ideal, verticex1, verticex2);
            mov_ingreso += "L";
            Copia.mov7 = true;
            Copia.move7_data(&IdealCopia, verticex3, verticex4);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov8 = true;
            Rubik.move8_data(&Ideal, verticex1, verticex2);
            
            Copia.mov8 = true;
            Copia.move8_data(&IdealCopia, verticex3, verticex4);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov9 = true;
            Rubik.move9_data(&Ideal, verticex1, verticex2);
            mov_ingreso += "R";

            Copia.mov9 = true;
            Copia.move9_data(&IdealCopia, verticex3, verticex4);
        }
    }



    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov10 = true;
            Rubik.move1_data(&Ideal, verticex1, verticex2);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov11 = true;
            Rubik.move2_data(&Ideal, verticex1, verticex2);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov12 = true;
            Rubik.move3_data(&Ideal, verticex1, verticex2);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov13 = true;
            Rubik.move4_data(&Ideal, verticex1, verticex2);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov14 = true;
            Rubik.move5_data(&Ideal, verticex1, verticex2);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov15 = true;
            Rubik.move6_data(&Ideal, verticex1, verticex2);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov16 = true;
            Rubik.move7_data(&Ideal, verticex1, verticex2);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov17 = true;
            Rubik.move8_data(&Ideal, verticex1, verticex2);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
        if (Rubik.mov1 == false && Rubik.mov2 == false && Rubik.mov3 == false &&
            Rubik.mov4 == false && Rubik.mov5 == false && Rubik.mov6 == false &&
            Rubik.mov7 == false && Rubik.mov8 == false && Rubik.mov9 == false &&
            Rubik.mov10 == false && Rubik.mov11 == false && Rubik.mov12 == false &&
            Rubik.mov13 == false && Rubik.mov14 == false && Rubik.mov15 == false &&
            Rubik.mov16 == false && Rubik.mov17 == false && Rubik.mov18 == false) {

            Rubik.mov18 = true;
            Rubik.move9_data(&Ideal, verticex1, verticex2);
        }
    }

    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        if (!solver_activo) {
            cout << "MOVIMIENTOS ENTRADA:  " << mov_ingreso << endl;
            mov_ingreso = "";
            solver_start();
            cout << "\nResultados: " << movimientos << endl;
            solver_activo = true;
        }
        else {
            cout << "ESPERE QUE TERMINE SOLVER" << endl;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        if (an1 == false) {
            an1 = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        if (an2 == false) {
            an2 = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        if (an3 == false) {
            an3 = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        if (an4 == false) {
            an4 = true;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) {
        if (copia == false) {
            copia = true;
        }
        else {
            copia = false;
        }
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}


