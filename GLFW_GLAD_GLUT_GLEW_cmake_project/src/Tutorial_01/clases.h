#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

void rotate_x_y(float* arr, float incremento, float x) {
    // float incremento = 0.01;
    float center = 1.5;

    for (int i = 0; i < 2592; i += 8) {
        arr[i + 0] = center + (arr[i] - center) * cos(incremento) - (arr[i + 1] - center) * sin(incremento);
        arr[i + 1] = center + (arr[i] - center) * sin(incremento) + (arr[i + 1] - center) * cos(incremento);
    }
}

void rotate_x_z(float* arr, float incremento, float x) {
    // float incremento = 0.01;
    float center = 1.5;

    for (int i = 0; i < 2592; i += 8) {
        arr[i + 0] = center + (arr[i] - center) * cos(incremento) - (arr[i + 2] - center) * sin(incremento);
        arr[i + 2] = center + (arr[i] - center) * sin(incremento) + (arr[i + 2] - center) * cos(incremento);
    }
}

void rotate_y_z(float* arr, float incremento, float x) {
    // float incremento = 0.01;
    float center = 1.5;

    for (int i = 0; i < 2592; i += 8) {
        arr[i + 1] = center + (arr[i + 1] - center) * cos(incremento) - (arr[i + 2] - center) * sin(incremento);
        arr[i + 2] = center + (arr[i + 1] - center) * sin(incremento) + (arr[i + 2] - center) * cos(incremento);
    }
}

class Vertice {
public:
    float pos_x, pos_y, pos_z;
    float col_x, col_y, col_z;
    float tex_x, tex_y;

    Vertice(float px, float py, float pz) {
        pos_x = px; pos_y = py; pos_z = pz;
        col_x = 0;  col_y = 0;  col_z = 0;
        tex_x = 1;  tex_y = 1;
    }

    void setPosicion(float px, float py, float pz) {
        pos_x = px; pos_y = py; pos_z = pz;
    }
    void setColor(float cx, float cy, float cz) {
        col_x = cx; col_y = cy; col_z = cz;
    }
    void setTextura(float tx, float ty) {
        tex_x = tx; tex_y = ty;
    }
};

class Cara {
public:
    Vertice* v1; Vertice* v2; Vertice* v3; Vertice* v4;

    // triangule1: v1, v2, v3
    // triangule2: v2, v3, v4
    Cara(float v1_x, float v1_y, float v1_z,
        float v2_x, float v2_y, float v2_z,
        float v3_x, float v3_y, float v3_z,
        float v4_x, float v4_y, float v4_z) {

        v1 = new Vertice(v1_x, v1_y, v1_z);
        v2 = new Vertice(v2_x, v2_y, v2_z);
        v3 = new Vertice(v3_x, v3_y, v3_z);
        v4 = new Vertice(v4_x, v4_y, v4_z);

        v1->setTextura(1.0f, 0.0f);
        v2->setTextura(0.0f, 0.0f);
        v3->setTextura(1.0f, 1.0f);
        v4->setTextura(0.0f, 1.0f);
    }

    void blanco() {
        v1->setColor(1.0, 1.0, 1.0);
        v2->setColor(1.0, 1.0, 1.0);
        v3->setColor(1.0, 1.0, 1.0);
        v4->setColor(1.0, 1.0, 1.0);
    }
    void rojo() {
        v1->setColor(1.0, 0.0, 0.0);
        v2->setColor(1.0, 0.0, 0.0);
        v3->setColor(1.0, 0.0, 0.0);
        v4->setColor(1.0, 0.0, 0.0);
    }
    void azul() {
        v1->setColor(0.0, 0.0, 1.0);
        v2->setColor(0.0, 0.0, 1.0);
        v3->setColor(0.0, 0.0, 1.0);
        v4->setColor(0.0, 0.0, 1.0);
    }
    void naranja() {
        v1->setColor(1.0, 0.5, 0.0);
        v2->setColor(1.0, 0.5, 0.0);
        v3->setColor(1.0, 0.5, 0.0);
        v4->setColor(1.0, 0.5, 0.0);
    }
    void verde() {
        v1->setColor(0.0, 1.0, 0.0);
        v2->setColor(0.0, 1.0, 0.0);
        v3->setColor(0.0, 1.0, 0.0);
        v4->setColor(0.0, 1.0, 0.0);
    }
    void amarillo() {
        v1->setColor(1.0, 1.0, 0.0);
        v2->setColor(1.0, 1.0, 0.0);
        v3->setColor(1.0, 1.0, 0.0);
        v4->setColor(1.0, 1.0, 0.0);
    }

    void copy_color_cara(Cara* copy) {
        v1->setColor(copy->v1->col_x, copy->v1->col_y, copy->v1->col_z);
        v2->setColor(copy->v1->col_x, copy->v1->col_y, copy->v1->col_z);
        v3->setColor(copy->v1->col_x, copy->v1->col_y, copy->v1->col_z);
        v4->setColor(copy->v1->col_x, copy->v1->col_y, copy->v1->col_z);
    }

    char color() {
        if (v1->col_x == 1.0 && v1->col_y == 1.0 && v1->col_z == 1.0)
            return 'w';

        if (v1->col_x == 1.0 && v1->col_y == 0.0 && v1->col_z == 0.0)
            return 'r';

        if (v1->col_x == 0.0 && v1->col_y == 0.0 && v1->col_z == 1.0)
            return 'b';

        if (v1->col_x == 1.0 && v1->col_y == 0.5 && v1->col_z == 0.0)
            return 'o';

        if (v1->col_x == 0.0 && v1->col_y == 1.0 && v1->col_z == 0.0)
            return 'g';

        if (v1->col_x == 1.0 && v1->col_y == 1.0 && v1->col_z == 0.0)
            return 'y';
    }

    void modificar(float x, float y, float z) {
        v1->pos_x += x; v2->pos_x += x; v3->pos_x += x; v4->pos_x += x;
        v1->pos_y += y; v2->pos_y += y; v3->pos_y += y; v4->pos_y += y;
        v1->pos_z += z; v2->pos_z += z; v3->pos_z += z; v4->pos_z += z;
    }
};

class Cubo {
public:
    Cara* cara1; Cara* cara2; Cara* cara3;
    Cara* cara4; Cara* cara5; Cara* cara6;

    Vertice* v1; Vertice* v2; Vertice* v3; Vertice* v4;
    Vertice* v5; Vertice* v6; Vertice* v7; Vertice* v8;

    string tipo_cubo;

    // las caras formas "   Z   "
    Cubo(float v1_x, float v1_y, float v1_z,
        float v2_x, float v2_y, float v2_z,
        float v3_x, float v3_y, float v3_z,
        float v4_x, float v4_y, float v4_z,
        float v5_x, float v5_y, float v5_z,
        float v6_x, float v6_y, float v6_z,
        float v7_x, float v7_y, float v7_z,
        float v8_x, float v8_y, float v8_z,
        string _tipo_cubo, float x) {

        tipo_cubo = _tipo_cubo;

        float value = 0.02;

        v1_x += value; v2_x += value; v3_x += value; v4_x += value; v5_x -= value; v6_x -= value; v7_x -= value; v8_x -= value;
        v1_y += value; v2_y -= value; v3_y += value; v4_y -= value; v5_y += value; v6_y -= value; v7_y += value; v8_y -= value;
        v1_z -= value; v2_z -= value; v3_z += value; v4_z += value; v5_z -= value; v6_z -= value; v7_z += value; v8_z += value;

        v1_x += x;
        v2_x += x;
        v3_x += x;
        v4_x += x;
        v5_x += x;
        v6_x += x;
        v7_x += x;
        v8_x += x;
        

        v1 = new Vertice(v1_x, v1_y, v1_z); v2 = new Vertice(v2_x, v2_y, v2_z); v3 = new Vertice(v3_x, v3_y, v3_z);
        v4 = new Vertice(v4_x, v4_y, v4_z); v5 = new Vertice(v5_x, v5_y, v5_z); v6 = new Vertice(v6_x, v6_y, v6_z);
        v7 = new Vertice(v7_x, v7_y, v7_z); v8 = new Vertice(v8_x, v8_y, v8_z);

        this->cara1 = new Cara(v1_x, v1_y, v1_z, v2_x, v2_y, v2_z, v3_x, v3_y, v3_z, v4_x, v4_y, v4_z);
        this->cara2 = new Cara(v5_x, v5_y, v5_z, v6_x, v6_y, v6_z, v7_x, v7_y, v7_z, v8_x, v8_y, v8_z);

        this->cara3 = new Cara(v5_x, v5_y, v5_z, v1_x, v1_y, v1_z, v7_x, v7_y, v7_z, v3_x, v3_y, v3_z);
        this->cara4 = new Cara(v6_x, v6_y, v6_z, v2_x, v2_y, v2_z, v8_x, v8_y, v8_z, v4_x, v4_y, v4_z);

        this->cara5 = new Cara(v1_x, v1_y, v1_z, v2_x, v2_y, v2_z, v5_x, v5_y, v5_z, v6_x, v6_y, v6_z);
        this->cara6 = new Cara(v3_x, v3_y, v3_z, v4_x, v4_y, v4_z, v7_x, v7_y, v7_z, v8_x, v8_y, v8_z);
    }

    // siempre ocupa 288 posiciones
    void add_valores(float* vertices, int ini) {
        add_cara1(vertices, ini + (48 * 0));
        add_cara2(vertices, ini + (48 * 1));
        add_cara3(vertices, ini + (48 * 2));
        add_cara4(vertices, ini + (48 * 3));
        add_cara5(vertices, ini + (48 * 4));
        add_cara6(vertices, ini + (48 * 5));
    }

    // siempre agrega 48
    void add_cara1(float* vertices, int ini) {
        // Caras tienen 2 triangulos - 1 2 3 y 2 3 4
        *(vertices + ini + 0) = cara1->v1->pos_x;
        *(vertices + ini + 1) = cara1->v1->pos_y;
        *(vertices + ini + 2) = cara1->v1->pos_z;
        *(vertices + ini + 3) = cara1->v1->col_x;
        *(vertices + ini + 4) = cara1->v1->col_y;
        *(vertices + ini + 5) = cara1->v1->col_z;
        *(vertices + ini + 6) = cara1->v1->tex_x;
        *(vertices + ini + 7) = cara1->v1->tex_y;

        *(vertices + ini + 8) = cara1->v2->pos_x;
        *(vertices + ini + 9) = cara1->v2->pos_y;
        *(vertices + ini + 10) = cara1->v2->pos_z;
        *(vertices + ini + 11) = cara1->v2->col_x;
        *(vertices + ini + 12) = cara1->v2->col_y;
        *(vertices + ini + 13) = cara1->v2->col_z;
        *(vertices + ini + 14) = cara1->v2->tex_x;
        *(vertices + ini + 15) = cara1->v2->tex_y;

        *(vertices + ini + 16) = cara1->v3->pos_x;
        *(vertices + ini + 17) = cara1->v3->pos_y;
        *(vertices + ini + 18) = cara1->v3->pos_z;
        *(vertices + ini + 19) = cara1->v3->col_x;
        *(vertices + ini + 20) = cara1->v3->col_y;
        *(vertices + ini + 21) = cara1->v3->col_z;
        *(vertices + ini + 22) = cara1->v3->tex_x;
        *(vertices + ini + 23) = cara1->v3->tex_y;

        // 2da cara (vertex 2 3 4)
        *(vertices + ini + 24) = cara1->v2->pos_x;
        *(vertices + ini + 25) = cara1->v2->pos_y;
        *(vertices + ini + 26) = cara1->v2->pos_z;
        *(vertices + ini + 27) = cara1->v2->col_x;
        *(vertices + ini + 28) = cara1->v2->col_y;
        *(vertices + ini + 29) = cara1->v2->col_z;
        *(vertices + ini + 30) = cara1->v2->tex_x;
        *(vertices + ini + 31) = cara1->v2->tex_y;

        *(vertices + ini + 32) = cara1->v3->pos_x;
        *(vertices + ini + 33) = cara1->v3->pos_y;
        *(vertices + ini + 34) = cara1->v3->pos_z;
        *(vertices + ini + 35) = cara1->v3->col_x;
        *(vertices + ini + 36) = cara1->v3->col_y;
        *(vertices + ini + 37) = cara1->v3->col_z;
        *(vertices + ini + 38) = cara1->v3->tex_x;
        *(vertices + ini + 39) = cara1->v3->tex_y;

        *(vertices + ini + 40) = cara1->v4->pos_x;
        *(vertices + ini + 41) = cara1->v4->pos_y;
        *(vertices + ini + 42) = cara1->v4->pos_z;
        *(vertices + ini + 43) = cara1->v4->col_x;
        *(vertices + ini + 44) = cara1->v4->col_y;
        *(vertices + ini + 45) = cara1->v4->col_z;
        *(vertices + ini + 46) = cara1->v4->tex_x;
        *(vertices + ini + 47) = cara1->v4->tex_y;
    }

    void add_cara2(float* vertices, int ini) {
        // Caras tienen 2 triangulos - 1 2 3 y 2 3 4
        *(vertices + ini + 0) = cara2->v1->pos_x;
        *(vertices + ini + 1) = cara2->v1->pos_y;
        *(vertices + ini + 2) = cara2->v1->pos_z;
        *(vertices + ini + 3) = cara2->v1->col_x;
        *(vertices + ini + 4) = cara2->v1->col_y;
        *(vertices + ini + 5) = cara2->v1->col_z;
        *(vertices + ini + 6) = cara2->v1->tex_x;
        *(vertices + ini + 7) = cara2->v1->tex_y;

        *(vertices + ini + 8) = cara2->v2->pos_x;
        *(vertices + ini + 9) = cara2->v2->pos_y;
        *(vertices + ini + 10) = cara2->v2->pos_z;
        *(vertices + ini + 11) = cara2->v2->col_x;
        *(vertices + ini + 12) = cara2->v2->col_y;
        *(vertices + ini + 13) = cara2->v2->col_z;
        *(vertices + ini + 14) = cara2->v2->tex_x;
        *(vertices + ini + 15) = cara2->v2->tex_y;

        *(vertices + ini + 16) = cara2->v3->pos_x;
        *(vertices + ini + 17) = cara2->v3->pos_y;
        *(vertices + ini + 18) = cara2->v3->pos_z;
        *(vertices + ini + 19) = cara2->v3->col_x;
        *(vertices + ini + 20) = cara2->v3->col_y;
        *(vertices + ini + 21) = cara2->v3->col_z;
        *(vertices + ini + 22) = cara2->v3->tex_x;
        *(vertices + ini + 23) = cara2->v3->tex_y;

        // 2da cara (vertex 2 3 4)
        *(vertices + ini + 24) = cara2->v2->pos_x;
        *(vertices + ini + 25) = cara2->v2->pos_y;
        *(vertices + ini + 26) = cara2->v2->pos_z;
        *(vertices + ini + 27) = cara2->v2->col_x;
        *(vertices + ini + 28) = cara2->v2->col_y;
        *(vertices + ini + 29) = cara2->v2->col_z;
        *(vertices + ini + 30) = cara2->v2->tex_x;
        *(vertices + ini + 31) = cara2->v2->tex_y;

        *(vertices + ini + 32) = cara2->v3->pos_x;
        *(vertices + ini + 33) = cara2->v3->pos_y;
        *(vertices + ini + 34) = cara2->v3->pos_z;
        *(vertices + ini + 35) = cara2->v3->col_x;
        *(vertices + ini + 36) = cara2->v3->col_y;
        *(vertices + ini + 37) = cara2->v3->col_z;
        *(vertices + ini + 38) = cara2->v3->tex_x;
        *(vertices + ini + 39) = cara2->v3->tex_y;

        *(vertices + ini + 40) = cara2->v4->pos_x;
        *(vertices + ini + 41) = cara2->v4->pos_y;
        *(vertices + ini + 42) = cara2->v4->pos_z;
        *(vertices + ini + 43) = cara2->v4->col_x;
        *(vertices + ini + 44) = cara2->v4->col_y;
        *(vertices + ini + 45) = cara2->v4->col_z;
        *(vertices + ini + 46) = cara2->v4->tex_x;
        *(vertices + ini + 47) = cara2->v4->tex_y;
    }

    void add_cara3(float* vertices, int ini) {
        // Caras tienen 2 triangulos - 1 2 3 y 2 3 4
        *(vertices + ini + 0) = cara3->v1->pos_x;
        *(vertices + ini + 1) = cara3->v1->pos_y;
        *(vertices + ini + 2) = cara3->v1->pos_z;
        *(vertices + ini + 3) = cara3->v1->col_x;
        *(vertices + ini + 4) = cara3->v1->col_y;
        *(vertices + ini + 5) = cara3->v1->col_z;
        *(vertices + ini + 6) = cara3->v1->tex_x;
        *(vertices + ini + 7) = cara3->v1->tex_y;

        *(vertices + ini + 8) = cara3->v2->pos_x;
        *(vertices + ini + 9) = cara3->v2->pos_y;
        *(vertices + ini + 10) = cara3->v2->pos_z;
        *(vertices + ini + 11) = cara3->v2->col_x;
        *(vertices + ini + 12) = cara3->v2->col_y;
        *(vertices + ini + 13) = cara3->v2->col_z;
        *(vertices + ini + 14) = cara3->v2->tex_x;
        *(vertices + ini + 15) = cara3->v2->tex_y;

        *(vertices + ini + 16) = cara3->v3->pos_x;
        *(vertices + ini + 17) = cara3->v3->pos_y;
        *(vertices + ini + 18) = cara3->v3->pos_z;
        *(vertices + ini + 19) = cara3->v3->col_x;
        *(vertices + ini + 20) = cara3->v3->col_y;
        *(vertices + ini + 21) = cara3->v3->col_z;
        *(vertices + ini + 22) = cara3->v3->tex_x;
        *(vertices + ini + 23) = cara3->v3->tex_y;

        // 2da cara (vertex 2 3 4)
        *(vertices + ini + 24) = cara3->v2->pos_x;
        *(vertices + ini + 25) = cara3->v2->pos_y;
        *(vertices + ini + 26) = cara3->v2->pos_z;
        *(vertices + ini + 27) = cara3->v2->col_x;
        *(vertices + ini + 28) = cara3->v2->col_y;
        *(vertices + ini + 29) = cara3->v2->col_z;
        *(vertices + ini + 30) = cara3->v2->tex_x;
        *(vertices + ini + 31) = cara3->v2->tex_y;

        *(vertices + ini + 32) = cara3->v3->pos_x;
        *(vertices + ini + 33) = cara3->v3->pos_y;
        *(vertices + ini + 34) = cara3->v3->pos_z;
        *(vertices + ini + 35) = cara3->v3->col_x;
        *(vertices + ini + 36) = cara3->v3->col_y;
        *(vertices + ini + 37) = cara3->v3->col_z;
        *(vertices + ini + 38) = cara3->v3->tex_x;
        *(vertices + ini + 39) = cara3->v3->tex_y;

        *(vertices + ini + 40) = cara3->v4->pos_x;
        *(vertices + ini + 41) = cara3->v4->pos_y;
        *(vertices + ini + 42) = cara3->v4->pos_z;
        *(vertices + ini + 43) = cara3->v4->col_x;
        *(vertices + ini + 44) = cara3->v4->col_y;
        *(vertices + ini + 45) = cara3->v4->col_z;
        *(vertices + ini + 46) = cara3->v4->tex_x;
        *(vertices + ini + 47) = cara3->v4->tex_y;
    }

    void add_cara4(float* vertices, int ini) {
        // Caras tienen 2 triangulos - 1 2 3 y 2 3 4
        *(vertices + ini + 0) = cara4->v1->pos_x;
        *(vertices + ini + 1) = cara4->v1->pos_y;
        *(vertices + ini + 2) = cara4->v1->pos_z;
        *(vertices + ini + 3) = cara4->v1->col_x;
        *(vertices + ini + 4) = cara4->v1->col_y;
        *(vertices + ini + 5) = cara4->v1->col_z;
        *(vertices + ini + 6) = cara4->v1->tex_x;
        *(vertices + ini + 7) = cara4->v1->tex_y;

        *(vertices + ini + 8) = cara4->v2->pos_x;
        *(vertices + ini + 9) = cara4->v2->pos_y;
        *(vertices + ini + 10) = cara4->v2->pos_z;
        *(vertices + ini + 11) = cara4->v2->col_x;
        *(vertices + ini + 12) = cara4->v2->col_y;
        *(vertices + ini + 13) = cara4->v2->col_z;
        *(vertices + ini + 14) = cara4->v2->tex_x;
        *(vertices + ini + 15) = cara4->v2->tex_y;

        *(vertices + ini + 16) = cara4->v3->pos_x;
        *(vertices + ini + 17) = cara4->v3->pos_y;
        *(vertices + ini + 18) = cara4->v3->pos_z;
        *(vertices + ini + 19) = cara4->v3->col_x;
        *(vertices + ini + 20) = cara4->v3->col_y;
        *(vertices + ini + 21) = cara4->v3->col_z;
        *(vertices + ini + 22) = cara4->v3->tex_x;
        *(vertices + ini + 23) = cara4->v3->tex_y;

        // 2da cara (vertex 2 3 4)
        *(vertices + ini + 24) = cara4->v2->pos_x;
        *(vertices + ini + 25) = cara4->v2->pos_y;
        *(vertices + ini + 26) = cara4->v2->pos_z;
        *(vertices + ini + 27) = cara4->v2->col_x;
        *(vertices + ini + 28) = cara4->v2->col_y;
        *(vertices + ini + 29) = cara4->v2->col_z;
        *(vertices + ini + 30) = cara4->v2->tex_x;
        *(vertices + ini + 31) = cara4->v2->tex_y;

        *(vertices + ini + 32) = cara4->v3->pos_x;
        *(vertices + ini + 33) = cara4->v3->pos_y;
        *(vertices + ini + 34) = cara4->v3->pos_z;
        *(vertices + ini + 35) = cara4->v3->col_x;
        *(vertices + ini + 36) = cara4->v3->col_y;
        *(vertices + ini + 37) = cara4->v3->col_z;
        *(vertices + ini + 38) = cara4->v3->tex_x;
        *(vertices + ini + 39) = cara4->v3->tex_y;

        *(vertices + ini + 40) = cara4->v4->pos_x;
        *(vertices + ini + 41) = cara4->v4->pos_y;
        *(vertices + ini + 42) = cara4->v4->pos_z;
        *(vertices + ini + 43) = cara4->v4->col_x;
        *(vertices + ini + 44) = cara4->v4->col_y;
        *(vertices + ini + 45) = cara4->v4->col_z;
        *(vertices + ini + 46) = cara4->v4->tex_x;
        *(vertices + ini + 47) = cara4->v4->tex_y;
    }

    void add_cara5(float* vertices, int ini) {
        // Caras tienen 2 triangulos - 1 2 3 y 2 3 4
        *(vertices + ini + 0) = cara5->v1->pos_x;
        *(vertices + ini + 1) = cara5->v1->pos_y;
        *(vertices + ini + 2) = cara5->v1->pos_z;
        *(vertices + ini + 3) = cara5->v1->col_x;
        *(vertices + ini + 4) = cara5->v1->col_y;
        *(vertices + ini + 5) = cara5->v1->col_z;
        *(vertices + ini + 6) = cara5->v1->tex_x;
        *(vertices + ini + 7) = cara5->v1->tex_y;

        *(vertices + ini + 8) = cara5->v2->pos_x;
        *(vertices + ini + 9) = cara5->v2->pos_y;
        *(vertices + ini + 10) = cara5->v2->pos_z;
        *(vertices + ini + 11) = cara5->v2->col_x;
        *(vertices + ini + 12) = cara5->v2->col_y;
        *(vertices + ini + 13) = cara5->v2->col_z;
        *(vertices + ini + 14) = cara5->v2->tex_x;
        *(vertices + ini + 15) = cara5->v2->tex_y;

        *(vertices + ini + 16) = cara5->v3->pos_x;
        *(vertices + ini + 17) = cara5->v3->pos_y;
        *(vertices + ini + 18) = cara5->v3->pos_z;
        *(vertices + ini + 19) = cara5->v3->col_x;
        *(vertices + ini + 20) = cara5->v3->col_y;
        *(vertices + ini + 21) = cara5->v3->col_z;
        *(vertices + ini + 22) = cara5->v3->tex_x;
        *(vertices + ini + 23) = cara5->v3->tex_y;

        // 2da cara (vertex 2 3 4)
        *(vertices + ini + 24) = cara5->v2->pos_x;
        *(vertices + ini + 25) = cara5->v2->pos_y;
        *(vertices + ini + 26) = cara5->v2->pos_z;
        *(vertices + ini + 27) = cara5->v2->col_x;
        *(vertices + ini + 28) = cara5->v2->col_y;
        *(vertices + ini + 29) = cara5->v2->col_z;
        *(vertices + ini + 30) = cara5->v2->tex_x;
        *(vertices + ini + 31) = cara5->v2->tex_y;

        *(vertices + ini + 32) = cara5->v3->pos_x;
        *(vertices + ini + 33) = cara5->v3->pos_y;
        *(vertices + ini + 34) = cara5->v3->pos_z;
        *(vertices + ini + 35) = cara5->v3->col_x;
        *(vertices + ini + 36) = cara5->v3->col_y;
        *(vertices + ini + 37) = cara5->v3->col_z;
        *(vertices + ini + 38) = cara5->v3->tex_x;
        *(vertices + ini + 39) = cara5->v3->tex_y;

        *(vertices + ini + 40) = cara5->v4->pos_x;
        *(vertices + ini + 41) = cara5->v4->pos_y;
        *(vertices + ini + 42) = cara5->v4->pos_z;
        *(vertices + ini + 43) = cara5->v4->col_x;
        *(vertices + ini + 44) = cara5->v4->col_y;
        *(vertices + ini + 45) = cara5->v4->col_z;
        *(vertices + ini + 46) = cara5->v4->tex_x;
        *(vertices + ini + 47) = cara5->v4->tex_y;
    }

    void add_cara6(float* vertices, int ini) {
        // Caras tienen 2 triangulos - 1 2 3 y 2 3 4
        *(vertices + ini + 0) = cara6->v1->pos_x;
        *(vertices + ini + 1) = cara6->v1->pos_y;
        *(vertices + ini + 2) = cara6->v1->pos_z;
        *(vertices + ini + 3) = cara6->v1->col_x;
        *(vertices + ini + 4) = cara6->v1->col_y;
        *(vertices + ini + 5) = cara6->v1->col_z;
        *(vertices + ini + 6) = cara6->v1->tex_x;
        *(vertices + ini + 7) = cara6->v1->tex_y;

        *(vertices + ini + 8) = cara6->v2->pos_x;
        *(vertices + ini + 9) = cara6->v2->pos_y;
        *(vertices + ini + 10) = cara6->v2->pos_z;
        *(vertices + ini + 11) = cara6->v2->col_x;
        *(vertices + ini + 12) = cara6->v2->col_y;
        *(vertices + ini + 13) = cara6->v2->col_z;
        *(vertices + ini + 14) = cara6->v2->tex_x;
        *(vertices + ini + 15) = cara6->v2->tex_y;

        *(vertices + ini + 16) = cara6->v3->pos_x;
        *(vertices + ini + 17) = cara6->v3->pos_y;
        *(vertices + ini + 18) = cara6->v3->pos_z;
        *(vertices + ini + 19) = cara6->v3->col_x;
        *(vertices + ini + 20) = cara6->v3->col_y;
        *(vertices + ini + 21) = cara6->v3->col_z;
        *(vertices + ini + 22) = cara6->v3->tex_x;
        *(vertices + ini + 23) = cara6->v3->tex_y;

        // 2da cara (vertex 2 3 4)
        *(vertices + ini + 24) = cara6->v2->pos_x;
        *(vertices + ini + 25) = cara6->v2->pos_y;
        *(vertices + ini + 26) = cara6->v2->pos_z;
        *(vertices + ini + 27) = cara6->v2->col_x;
        *(vertices + ini + 28) = cara6->v2->col_y;
        *(vertices + ini + 29) = cara6->v2->col_z;
        *(vertices + ini + 30) = cara6->v2->tex_x;
        *(vertices + ini + 31) = cara6->v2->tex_y;

        *(vertices + ini + 32) = cara6->v3->pos_x;
        *(vertices + ini + 33) = cara6->v3->pos_y;
        *(vertices + ini + 34) = cara6->v3->pos_z;
        *(vertices + ini + 35) = cara6->v3->col_x;
        *(vertices + ini + 36) = cara6->v3->col_y;
        *(vertices + ini + 37) = cara6->v3->col_z;
        *(vertices + ini + 38) = cara6->v3->tex_x;
        *(vertices + ini + 39) = cara6->v3->tex_y;

        *(vertices + ini + 40) = cara6->v4->pos_x;
        *(vertices + ini + 41) = cara6->v4->pos_y;
        *(vertices + ini + 42) = cara6->v4->pos_z;
        *(vertices + ini + 43) = cara6->v4->col_x;
        *(vertices + ini + 44) = cara6->v4->col_y;
        *(vertices + ini + 45) = cara6->v4->col_z;
        *(vertices + ini + 46) = cara6->v4->tex_x;
        *(vertices + ini + 47) = cara6->v4->tex_y;
    }

    Cubo* copy_cubo2() {
        Cubo* cub = new Cubo(
            v1->pos_x, v1->pos_y, v1->pos_z,
            v2->pos_x, v2->pos_y, v2->pos_z,
            v3->pos_x, v3->pos_y, v3->pos_z,
            v4->pos_x, v4->pos_y, v4->pos_z,
            v5->pos_x, v5->pos_y, v5->pos_z,
            v6->pos_x, v6->pos_y, v6->pos_z,
            v7->pos_x, v7->pos_y, v7->pos_z,
            v8->pos_x, v8->pos_y, v8->pos_z,
            tipo_cubo, 0
        );

        cub->cara1->v1->col_x = cara1->v1->col_x;
        cub->cara1->v1->col_y = cara1->v1->col_y;
        cub->cara1->v1->col_z = cara1->v1->col_z;
        cub->cara1->v2->col_x = cara1->v2->col_x;
        cub->cara1->v2->col_y = cara1->v2->col_y;
        cub->cara1->v2->col_z = cara1->v2->col_z;
        cub->cara1->v3->col_x = cara1->v3->col_x;
        cub->cara1->v3->col_y = cara1->v3->col_y;
        cub->cara1->v3->col_z = cara1->v3->col_z;
        cub->cara1->v4->col_x = cara1->v4->col_x;
        cub->cara1->v4->col_y = cara1->v4->col_y;
        cub->cara1->v4->col_z = cara1->v4->col_z;

        cub->cara2->v1->col_x = cara2->v1->col_x;
        cub->cara2->v1->col_y = cara2->v1->col_y;
        cub->cara2->v1->col_z = cara2->v1->col_z;
        cub->cara2->v2->col_x = cara2->v2->col_x;
        cub->cara2->v2->col_y = cara2->v2->col_y;
        cub->cara2->v2->col_z = cara2->v2->col_z;
        cub->cara2->v3->col_x = cara2->v3->col_x;
        cub->cara2->v3->col_y = cara2->v3->col_y;
        cub->cara2->v3->col_z = cara2->v3->col_z;
        cub->cara2->v4->col_x = cara2->v4->col_x;
        cub->cara2->v4->col_y = cara2->v4->col_y;
        cub->cara2->v4->col_z = cara2->v4->col_z;

        cub->cara3->v1->col_x = cara3->v1->col_x;
        cub->cara3->v1->col_y = cara3->v1->col_y;
        cub->cara3->v1->col_z = cara3->v1->col_z;
        cub->cara3->v2->col_x = cara3->v2->col_x;
        cub->cara3->v2->col_y = cara3->v2->col_y;
        cub->cara3->v2->col_z = cara3->v2->col_z;
        cub->cara3->v3->col_x = cara3->v3->col_x;
        cub->cara3->v3->col_y = cara3->v3->col_y;
        cub->cara3->v3->col_z = cara3->v3->col_z;
        cub->cara3->v4->col_x = cara3->v4->col_x;
        cub->cara3->v4->col_y = cara3->v4->col_y;
        cub->cara3->v4->col_z = cara3->v4->col_z;

        cub->cara4->v1->col_x = cara4->v1->col_x;
        cub->cara4->v1->col_y = cara4->v1->col_y;
        cub->cara4->v1->col_z = cara4->v1->col_z;
        cub->cara4->v2->col_x = cara4->v2->col_x;
        cub->cara4->v2->col_y = cara4->v2->col_y;
        cub->cara4->v2->col_z = cara4->v2->col_z;
        cub->cara4->v3->col_x = cara4->v3->col_x;
        cub->cara4->v3->col_y = cara4->v3->col_y;
        cub->cara4->v3->col_z = cara4->v3->col_z;
        cub->cara4->v4->col_x = cara4->v4->col_x;
        cub->cara4->v4->col_y = cara4->v4->col_y;
        cub->cara4->v4->col_z = cara4->v4->col_z;

        cub->cara5->v1->col_x = cara5->v1->col_x;
        cub->cara5->v1->col_y = cara5->v1->col_y;
        cub->cara5->v1->col_z = cara5->v1->col_z;
        cub->cara5->v2->col_x = cara5->v2->col_x;
        cub->cara5->v2->col_y = cara5->v2->col_y;
        cub->cara5->v2->col_z = cara5->v2->col_z;
        cub->cara5->v3->col_x = cara5->v3->col_x;
        cub->cara5->v3->col_y = cara5->v3->col_y;
        cub->cara5->v3->col_z = cara5->v3->col_z;
        cub->cara5->v4->col_x = cara5->v4->col_x;
        cub->cara5->v4->col_y = cara5->v4->col_y;
        cub->cara5->v4->col_z = cara5->v4->col_z;

        cub->cara6->v1->col_x = cara6->v1->col_x;
        cub->cara6->v1->col_y = cara6->v1->col_y;
        cub->cara6->v1->col_z = cara6->v1->col_z;
        cub->cara6->v2->col_x = cara6->v2->col_x;
        cub->cara6->v2->col_y = cara6->v2->col_y;
        cub->cara6->v2->col_z = cara6->v2->col_z;
        cub->cara6->v3->col_x = cara6->v3->col_x;
        cub->cara6->v3->col_y = cara6->v3->col_y;
        cub->cara6->v3->col_z = cara6->v3->col_z;
        cub->cara6->v4->col_x = cara6->v4->col_x;
        cub->cara6->v4->col_y = cara6->v4->col_y;
        cub->cara6->v4->col_z = cara6->v4->col_z;

        return cub;
    }
    
    void add_value(Cubo* t) {
        cara1->copy_color_cara(t->cara1);
        cara2->copy_color_cara(t->cara2);
        cara3->copy_color_cara(t->cara3);
        cara4->copy_color_cara(t->cara4);
        cara5->copy_color_cara(t->cara5);
        cara6->copy_color_cara(t->cara6);
    }

    void modificar(float x, float y, float z) {
        cara1->v1->pos_x += x; cara1->v2->pos_x += x; cara1->v3->pos_x += x; cara1->v4->pos_x += x; cara2->v1->pos_x += x;
        cara2->v2->pos_x += x; cara2->v3->pos_x += x; cara2->v4->pos_x += x; cara3->v1->pos_x += x; cara3->v2->pos_x += x;
        cara3->v3->pos_x += x; cara3->v4->pos_x += x; cara4->v1->pos_x += x; cara4->v2->pos_x += x; cara4->v3->pos_x += x;
        cara4->v4->pos_x += x; cara5->v1->pos_x += x; cara5->v2->pos_x += x; cara5->v3->pos_x += x; cara5->v4->pos_x += x;
        cara6->v1->pos_x += x; cara6->v2->pos_x += x; cara6->v3->pos_x += x; cara6->v4->pos_x += x;

        cara1->v1->pos_y += y; cara1->v2->pos_y += y; cara1->v3->pos_y += y; cara1->v4->pos_y += y; cara2->v1->pos_y += y;
        cara2->v2->pos_y += y; cara2->v3->pos_y += y; cara2->v4->pos_y += y; cara3->v1->pos_y += y; cara3->v2->pos_y += y;
        cara3->v3->pos_y += y; cara3->v4->pos_y += y; cara4->v1->pos_y += y; cara4->v2->pos_y += y; cara4->v3->pos_y += y;
        cara4->v4->pos_y += y; cara5->v1->pos_y += y; cara5->v2->pos_y += y; cara5->v3->pos_y += y; cara5->v4->pos_y += y;
        cara6->v1->pos_y += y; cara6->v2->pos_y += y; cara6->v3->pos_y += y; cara6->v4->pos_y += y;

        cara1->v1->pos_z += z; cara1->v2->pos_z += z; cara1->v3->pos_z += z; cara1->v4->pos_z += z; cara2->v1->pos_z += z;
        cara2->v2->pos_z += z; cara2->v3->pos_z += z; cara2->v4->pos_z += z; cara3->v1->pos_z += z; cara3->v2->pos_z += z;
        cara3->v3->pos_z += z; cara3->v4->pos_z += z; cara4->v1->pos_z += z; cara4->v2->pos_z += z; cara4->v3->pos_z += z;
        cara4->v4->pos_z += z; cara5->v1->pos_z += z; cara5->v2->pos_z += z; cara5->v3->pos_z += z; cara5->v4->pos_z += z;
        cara6->v1->pos_z += z; cara6->v2->pos_z += z; cara6->v3->pos_z += z; cara6->v4->pos_z += z;
    }

};

