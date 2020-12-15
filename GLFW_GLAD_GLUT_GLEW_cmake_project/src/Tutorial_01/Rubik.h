#pragma once

#include "clases.h"

class CuboRubik {
public:
    Cubo* cubo1; Cubo* cubo2; Cubo* cubo3;
    Cubo* cubo4; Cubo* cubo5; Cubo* cubo6;
    Cubo* cubo7; Cubo* cubo8; Cubo* cubo9;

    Cubo* cubo10; Cubo* cubo11; Cubo* cubo12;
    Cubo* cubo13; Cubo* cubo14; Cubo* cubo15;
    Cubo* cubo16; Cubo* cubo17; Cubo* cubo18;

    Cubo* cubo19; Cubo* cubo20; Cubo* cubo21;
    Cubo* cubo22; Cubo* cubo23; Cubo* cubo24;
    Cubo* cubo25; Cubo* cubo26; Cubo* cubo27;

    // FOR MOV
    bool mov1, mov2, mov3, mov4, mov5, mov6;
    bool mov7, mov8, mov9, mov10, mov11, mov12;
    bool mov13, mov14, mov15, mov16, mov17, mov18;

    int cont1, cont2, cont3, cont4, cont5, cont6;
    int cont7, cont8, cont9, cont10, cont11, cont12;
    int cont13, cont14, cont15, cont16, cont17, cont18;

    float x;

    CuboRubik(float x) {
        CrearPrimeros9(x);
        CrearSegundos9(x);
        CrearTerceros9(x);

        this->x = x;

        mov1 = false; mov2 = false; mov3 = false; mov4 = false; mov5 = false; mov6 = false;
        mov7 = false; mov8 = false; mov9 = false; mov10 = false; mov11 = false; mov12 = false;

        cont1 = 0; cont2 = 0; cont3 = 0; cont4 = 0; cont5 = 0; cont6 = 0;
        cont7 = 0; cont8 = 0; cont9 = 0; cont10 = 0; cont11 = 0; cont12 = 0;

        /*cubo1->cara1->amarillo();
        cubo1->cara3->naranja();
        cubo1->cara6->rojo();
        cubo2->cara1->amarillo();
        cubo2->cara3->naranja();
        cubo3->cara1->amarillo();
        cubo3->cara3->naranja();
        cubo3->cara5->verde();

        cubo4->cara1->amarillo();
        cubo4->cara6->rojo();
        cubo5->cara1->amarillo();
        cubo6->cara1->amarillo();
        cubo6->cara5->verde();

        cubo7->cara1->amarillo();
        cubo7->cara6->rojo();
        cubo7->cara4->azul();
        cubo8->cara1->amarillo();
        cubo8->cara4->azul();
        cubo9->cara1->amarillo();
        cubo9->cara4->azul();
        cubo9->cara5->verde();



        cubo10->cara3->naranja();
        cubo10->cara6->rojo();
        cubo11->cara3->naranja();
        cubo12->cara3->naranja();
        cubo12->cara5->verde();

        cubo13->cara6->rojo();
        cubo15->cara5->verde();

        cubo16->cara6->rojo();
        cubo16->cara4->azul();
        cubo17->cara4->azul();
        cubo18->cara4->azul();
        cubo18->cara5->verde();



        cubo19->cara6->rojo();
        cubo19->cara3->naranja();
        cubo19->cara2->blanco();
        cubo20->cara2->blanco();
        cubo20->cara3->naranja();
        cubo21->cara2->blanco();
        cubo21->cara3->naranja();
        cubo21->cara5->verde();

        cubo22->cara2->blanco();
        cubo22->cara6->rojo();
        cubo23->cara2->blanco();
        cubo24->cara2->blanco();
        cubo24->cara5->verde();

        cubo25->cara2->blanco();
        cubo25->cara6->rojo();
        cubo25->cara4->azul();
        cubo26->cara2->blanco();
        cubo26->cara4->azul();
        cubo27->cara4->azul();
        cubo27->cara2->blanco();
        cubo27->cara5->verde();*/


        cubo1->cara1->amarillo(); cubo1->cara3->rojo(); cubo1->cara6->verde(); cubo2->cara1->amarillo();
        cubo2->cara3->rojo(); cubo3->cara1->amarillo(); cubo3->cara3->rojo(); cubo3->cara5->azul();

        cubo4->cara1->amarillo(); cubo4->cara6->verde(); cubo5->cara1->amarillo();
        cubo6->cara1->amarillo(); cubo6->cara5->azul();
        cubo7->cara1->amarillo(); cubo7->cara6->verde(); cubo7->cara4->naranja(); cubo8->cara1->amarillo();
        cubo8->cara4->naranja(); cubo9->cara1->amarillo(); cubo9->cara4->naranja(); cubo9->cara5->azul();

        cubo10->cara3->rojo(); cubo10->cara6->verde(); cubo11->cara3->rojo();
        cubo12->cara3->rojo(); cubo12->cara5->azul();
        cubo13->cara6->verde(); cubo15->cara5->azul();
        cubo16->cara6->verde(); cubo16->cara4->naranja(); cubo17->cara4->naranja();
        cubo18->cara4->naranja(); cubo18->cara5->azul();

        cubo19->cara6->verde(); cubo19->cara3->rojo(); cubo19->cara2->blanco(); cubo20->cara2->blanco();
        cubo20->cara3->rojo(); cubo21->cara2->blanco(); cubo21->cara3->rojo(); cubo21->cara5->azul();
        cubo22->cara2->blanco(); cubo22->cara6->verde(); cubo23->cara2->blanco();
        cubo24->cara2->blanco(); cubo24->cara5->azul();
        cubo25->cara2->blanco(); cubo25->cara6->verde(); cubo25->cara4->naranja(); cubo26->cara2->blanco();
        cubo26->cara4->naranja();  cubo27->cara4->naranja(); cubo27->cara2->blanco(); cubo27->cara5->azul();
    }

    // CONSTruCTOR
    void CrearPrimeros9(float x) {
        cubo1 = new Cubo(0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, "DLB", x);
        cubo2 = new Cubo(0, 0, 2, 0, 1, 2, 0, 0, 1, 0, 1, 1, 1, 0, 2, 1, 1, 2, 1, 0, 1, 1, 1, 1, "DL", x);
        cubo3 = new Cubo(0, 0, 3, 0, 1, 3, 0, 0, 2, 0, 1, 2, 1, 0, 3, 1, 1, 3, 1, 0, 2, 1, 1, 2, "DFL", x);

        cubo4 = new Cubo(0, 1, 1, 0, 2, 1, 0, 1, 0, 0, 2, 0, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 2, 0, "BL", x);
        cubo5 = new Cubo(0, 1, 2, 0, 2, 2, 0, 1, 1, 0, 2, 1, 1, 1, 2, 1, 2, 2, 1, 1, 1, 1, 2, 1, "", x);
        cubo6 = new Cubo(0, 1, 3,0, 2, 3, 0, 1, 2, 0, 2, 2, 1, 1, 3, 1, 2, 3, 1, 1, 2, 1, 2, 2, "FL", x);

        cubo7 = new Cubo(0, 2, 1, 0, 3, 1, 0, 2, 0, 0, 3, 0, 1, 2, 1, 1, 3, 1, 1, 2, 0, 1, 3, 0, "UBL", x);
        cubo8 = new Cubo(0, 2, 2, 0, 3, 2, 0, 2, 1, 0, 3, 1, 1, 2, 2, 1, 3, 2, 1, 2, 1, 1, 3, 1, "UL", x);
        cubo9 = new Cubo(0, 2, 3, 0, 3, 3, 0, 2, 2, 0, 3, 2, 1, 2, 3, 1, 3, 3, 1, 2, 2, 1, 3, 2, "ULF", x);
    }
    void CrearSegundos9(float x) {
        cubo10 = new Cubo(1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 2, 0, 1, 2, 1, 1, 2, 0, 0, 2, 1, 0, "DB", x);
        cubo11 = new Cubo(1, 0, 2, 1, 1, 2, 1, 0, 1, 1, 1, 1, 2, 0, 2, 2, 1, 2, 2, 0, 1, 2, 1, 1, "", x);
        cubo12 = new Cubo(1, 0, 3, 1, 1, 3, 1, 0, 2, 1, 1, 2, 2, 0, 3, 2, 1, 3, 2, 0, 2, 2, 1, 2, "DF", x);

        cubo13 = new Cubo(1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 2, 0, 2, 1, 1, 2, 2, 1, 2, 1, 0, 2, 2, 0, "", x);
        cubo14 = new Cubo(1, 1, 2, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, "", x);
        cubo15 = new Cubo(1, 1, 3, 1, 2, 3, 1, 1, 2, 1, 2, 2, 2, 1, 3, 2, 2, 3, 2, 1, 2, 2, 2, 2, "", x);

        cubo16 = new Cubo(1, 2, 1, 1, 3, 1, 1, 2, 0, 1, 3, 0, 2, 2, 1, 2, 3, 1, 2, 2, 0, 2, 3, 0, "UB", x);
        cubo17 = new Cubo(1, 2, 2, 1, 3, 2, 1, 2, 1, 1, 3, 1, 2, 2, 2, 2, 3, 2, 2, 2, 1, 2, 3, 1, "", x);
        cubo18 = new Cubo(1, 2, 3, 1, 3, 3, 1, 2, 2, 1, 3, 2, 2, 2, 3, 2, 3, 3, 2, 2, 2, 2, 3, 2, "UF", x);
    }
    void CrearTerceros9(float x) {
        cubo19 = new Cubo(2, 0, 1, 2, 1, 1, 2, 0, 0, 2, 1, 0, 3, 0, 1, 3, 1, 1, 3, 0, 0, 3, 1, 0, "DBR", x);
        cubo20 = new Cubo(2, 0, 2, 2, 1, 2, 2, 0, 1, 2, 1, 1, 3, 0, 2, 3, 1, 2, 3, 0, 1, 3, 1, 1, "DR", x);
        cubo21 = new Cubo(2, 0, 3, 2, 1, 3, 2, 0, 2, 2, 1, 2, 3, 0, 3, 3, 1, 3, 3, 0, 2, 3, 1, 2, "DRF", x);

        cubo22 = new Cubo(2, 1, 1, 2, 2, 1, 2, 1, 0, 2, 2, 0, 3, 1, 1, 3, 2, 1, 3, 1, 0, 3, 2, 0, "BR", x);
        cubo23 = new Cubo(2, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 1, 3, 1, 2, 3, 2, 2, 3, 1, 1, 3, 2, 1, "", x);
        cubo24 = new Cubo(2, 1, 3, 2, 2, 3, 2, 1, 2, 2, 2, 2, 3, 1, 3, 3, 2, 3, 3, 1, 2, 3, 2, 2, "FR", x);

        cubo25 = new Cubo(2, 2, 1, 2, 3, 1, 2, 2, 0, 2, 3, 0, 3, 2, 1, 3, 3, 1, 3, 2, 0, 3, 3, 0, "URB", x);
        cubo26 = new Cubo(2, 2, 2, 2, 3, 2, 2, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3, 2, 3, 2, 1, 3, 3, 1, "UR", x);
        cubo27 = new Cubo(2, 2, 3, 2, 3, 3, 2, 2, 2, 2, 3, 2, 3, 2, 3, 3, 3, 3, 3, 2, 2, 3, 3, 2, "UFR", x);
    }

    // start  dinamic = 2592; static = 5184
    void start(float* dinamic_vertex, float* static_vertex, int movimiento) {
        if (movimiento == 0) {
            add_value(dinamic_vertex, static_vertex);
        }
        else {
            /*float inter = 157;
            float speed = 0.01;*/
            /*float inter = 89;
            float speed = 0.02;*/
            float inter = 44;
            float speed = 0.04;
            /*float inter = 22;
            float speed = 0.08;*/
            if (mov1 && (cont1 < inter)) {
                rotate_x_z(dinamic_vertex, speed, x);
                ++cont1;

                if (cont1 == inter) {
                    cont1 = 0;
                    mov1 = false;
                    colorear_mov1();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov2 && (cont2 < inter)) {
                rotate_x_z(dinamic_vertex, speed,x);
                ++cont2;

                if (cont2 == inter) {
                    cont2 = 0;
                    mov2 = false;
                    colorear_mov2();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov3 && (cont3 < inter)) {
                rotate_x_z(dinamic_vertex, speed, x);
                ++cont3;

                if (cont3 == inter) {
                    cont3 = 0;
                    mov3 = false;
                    colorear_mov3();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov4 && (cont4 < inter)) {
                rotate_x_y(dinamic_vertex, speed, x);
                ++cont4;

                if (cont4 == inter) {
                    cont4 = 0;
                    mov4 = false;
                    colorear_mov4();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov5 && (cont5 < inter)) {
                rotate_x_y(dinamic_vertex, speed, x);
                ++cont5;

                if (cont5 == inter) {
                    cont5 = 0;
                    mov5 = false;
                    colorear_mov5();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov6 && (cont6 < inter)) {
                rotate_x_y(dinamic_vertex, speed, x);
                ++cont6;

                if (cont6 == inter) {
                    cont6 = 0;
                    mov6 = false;
                    colorear_mov6();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov7 && (cont7 < inter)) {
                rotate_y_z(dinamic_vertex, speed, x);
                ++cont7;

                if (cont7 == inter) {
                    cont7 = 0;
                    mov7 = false;
                    colorear_mov7();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov8 && (cont8 < inter)) {
                rotate_y_z(dinamic_vertex, speed, x);
                ++cont8;

                if (cont8 == inter) {
                    cont8 = 0;
                    mov8 = false;
                    colorear_mov8();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov9 && (cont9 < inter)) {
                rotate_y_z(dinamic_vertex, speed, x);
                ++cont9;

                if (cont9 == inter) {
                    cont9 = 0;
                    mov9 = false;
                    colorear_mov9();
                    add_value(dinamic_vertex, static_vertex);
                }
            }

            else if (mov10 && (cont10 < inter)) {
                rotate_x_z(dinamic_vertex, -speed, x);
                ++cont10;

                if (cont10 == inter) {
                    cont10 = 0;
                    mov10 = false;
                    colorear_mov10();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov11 && (cont11 < inter)) {
                rotate_x_z(dinamic_vertex, -speed, x);
                ++cont11;

                if (cont11 == inter) {
                    cont11 = 0;
                    mov11 = false;
                    colorear_mov11();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov12 && (cont12 < inter)) {
                rotate_x_z(dinamic_vertex, -speed ,x );
                ++cont12;

                if (cont12 == inter) {
                    cont12 = 0;
                    mov12 = false;
                    colorear_mov12();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov13 && (cont13 < inter)) {
                rotate_x_y(dinamic_vertex, -speed,x );
                ++cont13;

                if (cont13 == 157) {
                    cont13 = 0;
                    mov13 = false;
                    colorear_mov13();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov14 && (cont14 < inter)) {
                rotate_x_y(dinamic_vertex, -speed, x);
                ++cont14;

                if (cont14 == inter) {
                    cont14 = 0;
                    mov14 = false;
                    colorear_mov14();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov15 && (cont15 < inter)) {
                rotate_x_y(dinamic_vertex, -speed, x);
                ++cont15;

                if (cont15 == inter) {
                    cont15 = 0;
                    mov15 = false;
                    colorear_mov15();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov16 && (cont16 < inter)) {
                rotate_y_z(dinamic_vertex, -speed, x);
                ++cont16;

                if (cont16 == inter) {
                    cont16 = 0;
                    mov16 = false;
                    colorear_mov16();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov17 && (cont17 < inter)) {
                rotate_y_z(dinamic_vertex, -speed, x);
                ++cont17;

                if (cont17 == inter) {
                    cont17 = 0;
                    mov17 = false;
                    colorear_mov17();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
            else if (mov18 && (cont18 < inter)) {
                rotate_y_z(dinamic_vertex, -speed, x);
                ++cont18;

                if (cont18 == inter) {
                    cont18 = 0;
                    mov18 = false;
                    colorear_mov18();
                    add_value(dinamic_vertex, static_vertex);
                }
            }
        }
    }

    // valores para imprimir
    void add_value(float* vertices, float* vertices2) {
        // 3x3 siempre 288
        cubo1->add_valores(vertices, (288 * 0));
        cubo2->add_valores(vertices, (288 * 1));
        cubo3->add_valores(vertices, (288 * 2));
        cubo4->add_valores(vertices, (288 * 3));
        cubo5->add_valores(vertices, (288 * 4));
        cubo6->add_valores(vertices, (288 * 5));
        cubo7->add_valores(vertices, (288 * 6));
        cubo8->add_valores(vertices, (288 * 7));
        cubo9->add_valores(vertices, (288 * 8));

        cubo10->add_valores(vertices2, (288 * 0));
        cubo11->add_valores(vertices2, (288 * 1));
        cubo12->add_valores(vertices2, (288 * 2));
        cubo13->add_valores(vertices2, (288 * 3));
        cubo14->add_valores(vertices2, (288 * 4));
        cubo15->add_valores(vertices2, (288 * 5));
        cubo16->add_valores(vertices2, (288 * 6));
        cubo17->add_valores(vertices2, (288 * 7));
        cubo18->add_valores(vertices2, (288 * 8));

        cubo19->add_valores(vertices2, (288 * 9));
        cubo20->add_valores(vertices2, (288 * 10));
        cubo21->add_valores(vertices2, (288 * 11));
        cubo22->add_valores(vertices2, (288 * 12));
        cubo23->add_valores(vertices2, (288 * 13));
        cubo24->add_valores(vertices2, (288 * 14));
        cubo25->add_valores(vertices2, (288 * 15));
        cubo26->add_valores(vertices2, (288 * 16));
        cubo27->add_valores(vertices2, (288 * 17));
    }


    // VALUES FROM MOVE
    // DOWN
    void move1_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 1 2 3 10 11 12 19 20 21   ----   2592 posiciones
        cubo1->add_valores(mov_cubos, (288 * 0));
        cubo2->add_valores(mov_cubos, (288 * 1));
        cubo3->add_valores(mov_cubos, (288 * 2));
        cubo10->add_valores(mov_cubos, (288 * 3));
        cubo11->add_valores(mov_cubos, (288 * 4));
        cubo12->add_valores(mov_cubos, (288 * 5));
        cubo19->add_valores(mov_cubos, (288 * 6));
        cubo20->add_valores(mov_cubos, (288 * 7));
        cubo21->add_valores(mov_cubos, (288 * 8));

        cubo4->add_valores(sta_cubos, (288 * 0));
        cubo5->add_valores(sta_cubos, (288 * 1));
        cubo6->add_valores(sta_cubos, (288 * 2));
        cubo7->add_valores(sta_cubos, (288 * 3));
        cubo8->add_valores(sta_cubos, (288 * 4));
        cubo9->add_valores(sta_cubos, (288 * 5));
        cubo13->add_valores(sta_cubos, (288 * 6));
        cubo14->add_valores(sta_cubos, (288 * 7));
        cubo15->add_valores(sta_cubos, (288 * 8));
        cubo16->add_valores(sta_cubos, (288 * 9));
        cubo17->add_valores(sta_cubos, (288 * 10));
        cubo18->add_valores(sta_cubos, (288 * 11));
        cubo22->add_valores(sta_cubos, (288 * 12));
        cubo23->add_valores(sta_cubos, (288 * 13));
        cubo24->add_valores(sta_cubos, (288 * 14));
        cubo25->add_valores(sta_cubos, (288 * 15));
        cubo26->add_valores(sta_cubos, (288 * 16));
        cubo27->add_valores(sta_cubos, (288 * 17));
    }
    // CENTER
    void move2_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 4 5 6 13 14 15 22 23 24   ----   2592 posiciones
        cubo4->add_valores(mov_cubos, (288 * 0));
        cubo5->add_valores(mov_cubos, (288 * 1));
        cubo6->add_valores(mov_cubos, (288 * 2));
        cubo13->add_valores(mov_cubos, (288 * 3));
        cubo14->add_valores(mov_cubos, (288 * 4));
        cubo15->add_valores(mov_cubos, (288 * 5));
        cubo22->add_valores(mov_cubos, (288 * 6));
        cubo23->add_valores(mov_cubos, (288 * 7));
        cubo24->add_valores(mov_cubos, (288 * 8));

        cubo1->add_valores(sta_cubos, (288 * 0));
        cubo2->add_valores(sta_cubos, (288 * 1));
        cubo3->add_valores(sta_cubos, (288 * 2));
        cubo7->add_valores(sta_cubos, (288 * 3));
        cubo8->add_valores(sta_cubos, (288 * 4));
        cubo9->add_valores(sta_cubos, (288 * 5));
        cubo10->add_valores(sta_cubos, (288 * 6));
        cubo11->add_valores(sta_cubos, (288 * 7));
        cubo12->add_valores(sta_cubos, (288 * 8));
        cubo16->add_valores(sta_cubos, (288 * 9));
        cubo17->add_valores(sta_cubos, (288 * 10));
        cubo18->add_valores(sta_cubos, (288 * 11));
        cubo19->add_valores(sta_cubos, (288 * 12));
        cubo20->add_valores(sta_cubos, (288 * 13));
        cubo21->add_valores(sta_cubos, (288 * 14));
        cubo25->add_valores(sta_cubos, (288 * 15));
        cubo26->add_valores(sta_cubos, (288 * 16));
        cubo27->add_valores(sta_cubos, (288 * 17));
    }
    // UP
    void move3_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 7 8 9 16 17 18 25 26 27   ----   2592 posiciones
        cubo7->add_valores(mov_cubos, (288 * 0));
        cubo8->add_valores(mov_cubos, (288 * 1));
        cubo9->add_valores(mov_cubos, (288 * 2));
        cubo16->add_valores(mov_cubos, (288 * 3));
        cubo17->add_valores(mov_cubos, (288 * 4));
        cubo18->add_valores(mov_cubos, (288 * 5));
        cubo25->add_valores(mov_cubos, (288 * 6));
        cubo26->add_valores(mov_cubos, (288 * 7));
        cubo27->add_valores(mov_cubos, (288 * 8));

        cubo1->add_valores(sta_cubos, (288 * 0));
        cubo2->add_valores(sta_cubos, (288 * 1));
        cubo3->add_valores(sta_cubos, (288 * 2));
        cubo4->add_valores(sta_cubos, (288 * 3));
        cubo5->add_valores(sta_cubos, (288 * 4));
        cubo6->add_valores(sta_cubos, (288 * 5));
        cubo10->add_valores(sta_cubos, (288 * 6));
        cubo11->add_valores(sta_cubos, (288 * 7));
        cubo12->add_valores(sta_cubos, (288 * 8));
        cubo13->add_valores(sta_cubos, (288 * 9));
        cubo14->add_valores(sta_cubos, (288 * 10));
        cubo15->add_valores(sta_cubos, (288 * 11));
        cubo19->add_valores(sta_cubos, (288 * 12));
        cubo20->add_valores(sta_cubos, (288 * 13));
        cubo21->add_valores(sta_cubos, (288 * 14));
        cubo22->add_valores(sta_cubos, (288 * 15));
        cubo23->add_valores(sta_cubos, (288 * 16));
        cubo24->add_valores(sta_cubos, (288 * 17));
    }

    // BACK
    void move4_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 1 4 7 10 13 16 19 22 25   ----   2592 posiciones
        vector<Cubo*> cubos_a_buscar;
        cubo1->add_valores(mov_cubos, (288 * 0));
        cubo4->add_valores(mov_cubos, (288 * 1));
        cubo7->add_valores(mov_cubos, (288 * 2));
        cubo10->add_valores(mov_cubos, (288 * 3));
        cubo13->add_valores(mov_cubos, (288 * 4));
        cubo16->add_valores(mov_cubos, (288 * 5));
        cubo19->add_valores(mov_cubos, (288 * 6));
        cubo22->add_valores(mov_cubos, (288 * 7));
        cubo25->add_valores(mov_cubos, (288 * 8));

        cubo2->add_valores(sta_cubos, (288 * 0));
        cubo3->add_valores(sta_cubos, (288 * 1));
        cubo5->add_valores(sta_cubos, (288 * 2));
        cubo6->add_valores(sta_cubos, (288 * 3));
        cubo8->add_valores(sta_cubos, (288 * 4));
        cubo9->add_valores(sta_cubos, (288 * 5));
        cubo11->add_valores(sta_cubos, (288 * 6));
        cubo12->add_valores(sta_cubos, (288 * 7));
        cubo14->add_valores(sta_cubos, (288 * 8));
        cubo15->add_valores(sta_cubos, (288 * 9));
        cubo17->add_valores(sta_cubos, (288 * 10));
        cubo18->add_valores(sta_cubos, (288 * 11));
        cubo20->add_valores(sta_cubos, (288 * 12));
        cubo21->add_valores(sta_cubos, (288 * 13));
        cubo23->add_valores(sta_cubos, (288 * 14));
        cubo24->add_valores(sta_cubos, (288 * 15));
        cubo26->add_valores(sta_cubos, (288 * 16));
        cubo27->add_valores(sta_cubos, (288 * 17));
    }
    // CENTER
    void move5_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 2 5 8 11 14 17 20 23 26   ----   2592 posiciones
        cubo2->add_valores(mov_cubos, (288 * 0));
        cubo5->add_valores(mov_cubos, (288 * 1));
        cubo8->add_valores(mov_cubos, (288 * 2));
        cubo11->add_valores(mov_cubos, (288 * 3));
        cubo14->add_valores(mov_cubos, (288 * 4));
        cubo17->add_valores(mov_cubos, (288 * 5));
        cubo20->add_valores(mov_cubos, (288 * 6));
        cubo23->add_valores(mov_cubos, (288 * 7));
        cubo26->add_valores(mov_cubos, (288 * 8));

        cubo1->add_valores(sta_cubos, (288 * 0));
        cubo3->add_valores(sta_cubos, (288 * 1));
        cubo4->add_valores(sta_cubos, (288 * 2));
        cubo6->add_valores(sta_cubos, (288 * 3));
        cubo7->add_valores(sta_cubos, (288 * 4));
        cubo9->add_valores(sta_cubos, (288 * 5));
        cubo10->add_valores(sta_cubos, (288 * 6));
        cubo12->add_valores(sta_cubos, (288 * 7));
        cubo13->add_valores(sta_cubos, (288 * 8));
        cubo15->add_valores(sta_cubos, (288 * 9));
        cubo16->add_valores(sta_cubos, (288 * 10));
        cubo18->add_valores(sta_cubos, (288 * 11));
        cubo19->add_valores(sta_cubos, (288 * 12));
        cubo21->add_valores(sta_cubos, (288 * 13));
        cubo22->add_valores(sta_cubos, (288 * 14));
        cubo24->add_valores(sta_cubos, (288 * 15));
        cubo25->add_valores(sta_cubos, (288 * 16));
        cubo27->add_valores(sta_cubos, (288 * 17));
    }
    // FRONT
    void move6_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 3 6 9 12 15 18 21 24 27   ----   2592 posiciones
        cubo3->add_valores(mov_cubos, (288 * 0));
        cubo6->add_valores(mov_cubos, (288 * 1));
        cubo9->add_valores(mov_cubos, (288 * 2));
        cubo12->add_valores(mov_cubos, (288 * 3));
        cubo15->add_valores(mov_cubos, (288 * 4));
        cubo18->add_valores(mov_cubos, (288 * 5));
        cubo21->add_valores(mov_cubos, (288 * 6));
        cubo24->add_valores(mov_cubos, (288 * 7));
        cubo27->add_valores(mov_cubos, (288 * 8));

        cubo1->add_valores(sta_cubos, (288 * 0));
        cubo2->add_valores(sta_cubos, (288 * 1));
        cubo4->add_valores(sta_cubos, (288 * 2));
        cubo5->add_valores(sta_cubos, (288 * 3));
        cubo7->add_valores(sta_cubos, (288 * 4));
        cubo8->add_valores(sta_cubos, (288 * 5));
        cubo10->add_valores(sta_cubos, (288 * 6));
        cubo11->add_valores(sta_cubos, (288 * 7));
        cubo13->add_valores(sta_cubos, (288 * 8));
        cubo14->add_valores(sta_cubos, (288 * 9));
        cubo16->add_valores(sta_cubos, (288 * 10));
        cubo17->add_valores(sta_cubos, (288 * 11));
        cubo19->add_valores(sta_cubos, (288 * 12));
        cubo20->add_valores(sta_cubos, (288 * 13));
        cubo22->add_valores(sta_cubos, (288 * 14));
        cubo23->add_valores(sta_cubos, (288 * 15));
        cubo25->add_valores(sta_cubos, (288 * 16));
        cubo26->add_valores(sta_cubos, (288 * 17));
    }

    // LEFT
    void move7_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 1 2 3 4 5 6 7 8 9   ----   2592 posiciones
        cubo1->add_valores(mov_cubos, (288 * 0));
        cubo2->add_valores(mov_cubos, (288 * 1));
        cubo3->add_valores(mov_cubos, (288 * 2));
        cubo4->add_valores(mov_cubos, (288 * 3));
        cubo5->add_valores(mov_cubos, (288 * 4));
        cubo6->add_valores(mov_cubos, (288 * 5));
        cubo7->add_valores(mov_cubos, (288 * 6));
        cubo8->add_valores(mov_cubos, (288 * 7));
        cubo9->add_valores(mov_cubos, (288 * 8));

        cubo10->add_valores(sta_cubos, (288 * 0));
        cubo11->add_valores(sta_cubos, (288 * 1));
        cubo12->add_valores(sta_cubos, (288 * 2));
        cubo13->add_valores(sta_cubos, (288 * 3));
        cubo14->add_valores(sta_cubos, (288 * 4));
        cubo15->add_valores(sta_cubos, (288 * 5));
        cubo16->add_valores(sta_cubos, (288 * 6));
        cubo17->add_valores(sta_cubos, (288 * 7));
        cubo18->add_valores(sta_cubos, (288 * 8));
        cubo19->add_valores(sta_cubos, (288 * 9));
        cubo20->add_valores(sta_cubos, (288 * 10));
        cubo21->add_valores(sta_cubos, (288 * 11));
        cubo22->add_valores(sta_cubos, (288 * 12));
        cubo23->add_valores(sta_cubos, (288 * 13));
        cubo24->add_valores(sta_cubos, (288 * 14));
        cubo25->add_valores(sta_cubos, (288 * 15));
        cubo26->add_valores(sta_cubos, (288 * 16));
        cubo27->add_valores(sta_cubos, (288 * 17));
    }
    // CENTER
    void move8_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 10 11 12 13 14 15 16 17 18   ----   2592 posiciones
        cubo10->add_valores(mov_cubos, (288 * 0));
        cubo11->add_valores(mov_cubos, (288 * 1));
        cubo12->add_valores(mov_cubos, (288 * 2));
        cubo13->add_valores(mov_cubos, (288 * 3));
        cubo14->add_valores(mov_cubos, (288 * 4));
        cubo15->add_valores(mov_cubos, (288 * 5));
        cubo16->add_valores(mov_cubos, (288 * 6));
        cubo17->add_valores(mov_cubos, (288 * 7));
        cubo18->add_valores(mov_cubos, (288 * 8));

        cubo1->add_valores(sta_cubos, (288 * 0));
        cubo2->add_valores(sta_cubos, (288 * 1));
        cubo3->add_valores(sta_cubos, (288 * 2));
        cubo4->add_valores(sta_cubos, (288 * 3));
        cubo5->add_valores(sta_cubos, (288 * 4));
        cubo6->add_valores(sta_cubos, (288 * 5));
        cubo7->add_valores(sta_cubos, (288 * 6));
        cubo8->add_valores(sta_cubos, (288 * 7));
        cubo9->add_valores(sta_cubos, (288 * 8));
        cubo19->add_valores(sta_cubos, (288 * 9));
        cubo20->add_valores(sta_cubos, (288 * 10));
        cubo21->add_valores(sta_cubos, (288 * 11));
        cubo22->add_valores(sta_cubos, (288 * 12));
        cubo23->add_valores(sta_cubos, (288 * 13));
        cubo24->add_valores(sta_cubos, (288 * 14));
        cubo25->add_valores(sta_cubos, (288 * 15));
        cubo26->add_valores(sta_cubos, (288 * 16));
        cubo27->add_valores(sta_cubos, (288 * 17));
    }
    // RIGHT
    void move9_data(CuboRubik* ideal, float* mov_cubos, float* sta_cubos) {
        // cubo_ideal 19 20 21 22 23 24 25 26 27   ----   2592 posiciones
        cubo19->add_valores(mov_cubos, (288 * 0));
        cubo20->add_valores(mov_cubos, (288 * 1));
        cubo21->add_valores(mov_cubos, (288 * 2));
        cubo22->add_valores(mov_cubos, (288 * 3));
        cubo23->add_valores(mov_cubos, (288 * 4));
        cubo24->add_valores(mov_cubos, (288 * 5));
        cubo25->add_valores(mov_cubos, (288 * 6));
        cubo26->add_valores(mov_cubos, (288 * 7));
        cubo27->add_valores(mov_cubos, (288 * 8));

        cubo1->add_valores(sta_cubos, (288 * 0));
        cubo2->add_valores(sta_cubos, (288 * 1));
        cubo3->add_valores(sta_cubos, (288 * 2));
        cubo4->add_valores(sta_cubos, (288 * 3));
        cubo5->add_valores(sta_cubos, (288 * 4));
        cubo6->add_valores(sta_cubos, (288 * 5));
        cubo7->add_valores(sta_cubos, (288 * 6));
        cubo8->add_valores(sta_cubos, (288 * 7));
        cubo9->add_valores(sta_cubos, (288 * 8));
        cubo10->add_valores(sta_cubos, (288 * 9));
        cubo11->add_valores(sta_cubos, (288 * 10));
        cubo12->add_valores(sta_cubos, (288 * 11));
        cubo13->add_valores(sta_cubos, (288 * 12));
        cubo14->add_valores(sta_cubos, (288 * 13));
        cubo15->add_valores(sta_cubos, (288 * 14));
        cubo16->add_valores(sta_cubos, (288 * 15));
        cubo17->add_valores(sta_cubos, (288 * 16));
        cubo18->add_valores(sta_cubos, (288 * 17));
    }

    string change_letter(string cad) {
        string result = "";
        result += cad[0];
        for (int i = 1; i < cad.size(); ++i) {
            result += cad[i];
        }
        return result;
    }

    void arreglar(CuboRubik* ideal, float* dinamic_vertex, float* static_vertex) {
        cubo1->add_value(ideal->cubo1);
        cubo2->add_value(ideal->cubo2);
        cubo3->add_value(ideal->cubo3);
        cubo4->add_value(ideal->cubo4);
        cubo5->add_value(ideal->cubo5);
        cubo6->add_value(ideal->cubo6);
        cubo7->add_value(ideal->cubo7);
        cubo8->add_value(ideal->cubo8);
        cubo9->add_value(ideal->cubo9);
        cubo10->add_value(ideal->cubo10);
        cubo11->add_value(ideal->cubo11);
        cubo12->add_value(ideal->cubo12);
        cubo13->add_value(ideal->cubo13);
        cubo14->add_value(ideal->cubo14);
        cubo15->add_value(ideal->cubo15);
        cubo16->add_value(ideal->cubo16);
        cubo17->add_value(ideal->cubo17);
        cubo18->add_value(ideal->cubo18);
        cubo19->add_value(ideal->cubo19);
        cubo20->add_value(ideal->cubo20);
        cubo21->add_value(ideal->cubo21);
        cubo22->add_value(ideal->cubo22);
        cubo23->add_value(ideal->cubo23);
        cubo24->add_value(ideal->cubo24);
        cubo25->add_value(ideal->cubo25);
        cubo26->add_value(ideal->cubo26);
        cubo27->add_value(ideal->cubo27);

        add_value(dinamic_vertex, static_vertex);
    }

    // RELOJ ----------------------------------
    // DOWN
    void colorear_mov1() {
        // cubo_ideal 1 2 3 10 11 12 19 20 21   ----   2592 posiciones
        Cubo* tcubo1 = cubo1->copy_cubo2(); Cubo* tcubo2 = cubo2->copy_cubo2(); Cubo* tcubo3 = cubo3->copy_cubo2();
        Cubo* tcubo10 = cubo10->copy_cubo2(); Cubo* tcubo11 = cubo11->copy_cubo2(); Cubo* tcubo12 = cubo12->copy_cubo2();
        Cubo* tcubo19 = cubo19->copy_cubo2(); Cubo* tcubo20 = cubo20->copy_cubo2(); Cubo* tcubo21 = cubo21->copy_cubo2();

        cubo1->cara1->copy_color_cara(tcubo3->cara5);
        cubo2->cara1->copy_color_cara(tcubo12->cara5);
        cubo3->cara1->copy_color_cara(tcubo21->cara5);

        cubo3->cara5->copy_color_cara(tcubo21->cara2);
        cubo12->cara5->copy_color_cara(tcubo20->cara2);
        cubo21->cara5->copy_color_cara(tcubo19->cara2);

        cubo21->cara2->copy_color_cara(tcubo19->cara6);
        cubo20->cara2->copy_color_cara(tcubo10->cara6);
        cubo19->cara2->copy_color_cara(tcubo1->cara6);

        cubo19->cara6->copy_color_cara(tcubo1->cara1);
        cubo10->cara6->copy_color_cara(tcubo2->cara1);
        cubo1->cara6->copy_color_cara(tcubo3->cara1);



        cubo1->cara3->copy_color_cara(tcubo3->cara3);
        cubo2->cara3->copy_color_cara(tcubo12->cara3);
        cubo3->cara3->copy_color_cara(tcubo21->cara3);
        cubo10->cara3->copy_color_cara(tcubo2->cara3);

        cubo12->cara3->copy_color_cara(tcubo20->cara3);
        cubo19->cara3->copy_color_cara(tcubo1->cara3);
        cubo20->cara3->copy_color_cara(tcubo10->cara3);
        cubo21->cara3->copy_color_cara(tcubo19->cara3);




        cubo1->tipo_cubo = change_letter(tcubo3->tipo_cubo);
        cubo2->tipo_cubo = change_letter(tcubo12->tipo_cubo);
        cubo3->tipo_cubo = change_letter(tcubo21->tipo_cubo);

        cubo3->tipo_cubo = change_letter(tcubo21->tipo_cubo);
        cubo12->tipo_cubo = change_letter(tcubo20->tipo_cubo);
        cubo21->tipo_cubo = change_letter(tcubo19->tipo_cubo);

        cubo21->tipo_cubo = change_letter(tcubo19->tipo_cubo);
        cubo20->tipo_cubo = change_letter(tcubo10->tipo_cubo);
        cubo19->tipo_cubo = change_letter(tcubo1->tipo_cubo);

        cubo19->tipo_cubo = change_letter(tcubo1->tipo_cubo);
        cubo10->tipo_cubo = change_letter(tcubo2->tipo_cubo);
        cubo1->tipo_cubo = change_letter(tcubo3->tipo_cubo);


    }
    // CENTER
    void colorear_mov2() {
        // cubo_ideal 4 5 6 13 14 15 22 23 24   ----   2592 posiciones
        Cubo* tcubo4 = cubo4->copy_cubo2(); Cubo* tcubo5 = cubo5->copy_cubo2(); Cubo* tcubo6 = cubo6->copy_cubo2();
        Cubo* tcubo13 = cubo13->copy_cubo2(); Cubo* tcubo14 = cubo14->copy_cubo2(); Cubo* tcubo15 = cubo15->copy_cubo2();
        Cubo* tcubo22 = cubo22->copy_cubo2(); Cubo* tcubo23 = cubo23->copy_cubo2(); Cubo* tcubo24 = cubo24->copy_cubo2();

        cubo4->cara1->copy_color_cara(tcubo6->cara5);
        cubo5->cara1->copy_color_cara(tcubo15->cara5);
        cubo6->cara1->copy_color_cara(tcubo24->cara5);

        cubo4->cara6->copy_color_cara(tcubo6->cara1);
        cubo13->cara6->copy_color_cara(tcubo5->cara1);
        cubo22->cara6->copy_color_cara(tcubo4->cara1);

        cubo22->cara2->copy_color_cara(tcubo4->cara6);
        cubo23->cara2->copy_color_cara(tcubo13->cara6);
        cubo24->cara2->copy_color_cara(tcubo22->cara6);

        cubo24->cara5->copy_color_cara(tcubo22->cara2);
        cubo15->cara5->copy_color_cara(tcubo23->cara2);
        cubo6->cara5->copy_color_cara(tcubo24->cara2);
    }
    // UP
    void colorear_mov3() {
        Cubo* tcubo7 = cubo7->copy_cubo2(); Cubo* tcubo8 = cubo8->copy_cubo2(); Cubo* tcubo9 = cubo9->copy_cubo2();
        Cubo* tcubo16 = cubo16->copy_cubo2(); Cubo* tcubo17 = cubo17->copy_cubo2(); Cubo* tcubo18 = cubo18->copy_cubo2();
        Cubo* tcubo25 = cubo25->copy_cubo2(); Cubo* tcubo26 = cubo26->copy_cubo2(); Cubo* tcubo27 = cubo27->copy_cubo2();

        cubo7->cara1->copy_color_cara(tcubo9->cara5);
        cubo8->cara1->copy_color_cara(tcubo18->cara5);
        cubo9->cara1->copy_color_cara(tcubo27->cara5);

        cubo9->cara5->copy_color_cara(tcubo27->cara2);
        cubo18->cara5->copy_color_cara(tcubo26->cara2);
        cubo27->cara5->copy_color_cara(tcubo25->cara2);

        cubo27->cara2->copy_color_cara(tcubo25->cara6);
        cubo26->cara2->copy_color_cara(tcubo16->cara6);
        cubo25->cara2->copy_color_cara(tcubo7->cara6);

        cubo25->cara6->copy_color_cara(tcubo7->cara1);
        cubo16->cara6->copy_color_cara(tcubo8->cara1);
        cubo7->cara6->copy_color_cara(tcubo9->cara1);


        cubo7->cara4->copy_color_cara(tcubo9->cara4);
        cubo8->cara4->copy_color_cara(tcubo18->cara4);
        cubo9->cara4->copy_color_cara(tcubo27->cara4);
        cubo16->cara4->copy_color_cara(tcubo8->cara4);

        cubo18->cara4->copy_color_cara(tcubo26->cara4);
        cubo25->cara4->copy_color_cara(tcubo7->cara4);
        cubo26->cara4->copy_color_cara(tcubo16->cara4);
        cubo27->cara4->copy_color_cara(tcubo25->cara4);



        cubo7->tipo_cubo = change_letter(tcubo9->tipo_cubo);
        cubo8->tipo_cubo = change_letter(tcubo18->tipo_cubo);
        cubo9->tipo_cubo = change_letter(tcubo27->tipo_cubo);

        cubo9->tipo_cubo = change_letter(tcubo27->tipo_cubo);
        cubo18->tipo_cubo = change_letter(tcubo26->tipo_cubo);
        cubo27->tipo_cubo = change_letter(tcubo25->tipo_cubo);

        cubo27->tipo_cubo = change_letter(tcubo25->tipo_cubo);
        cubo26->tipo_cubo = change_letter(tcubo16->tipo_cubo);
        cubo25->tipo_cubo = change_letter(tcubo7->tipo_cubo);

        cubo25->tipo_cubo = change_letter(tcubo7->tipo_cubo);
        cubo16->tipo_cubo = change_letter(tcubo8->tipo_cubo);
        cubo7->tipo_cubo = change_letter(tcubo9->tipo_cubo);
    }

    // BACK
    void colorear_mov4() {
        // cubo_ideal 1 4 7 10 13 16 19 22 25   ----   2592 posiciones
        Cubo* tcubo1 = cubo1->copy_cubo2(); Cubo* tcubo4 = cubo4->copy_cubo2(); Cubo* tcubo7 = cubo7->copy_cubo2();
        Cubo* tcubo10 = cubo10->copy_cubo2(); Cubo* tcubo13 = cubo13->copy_cubo2(); Cubo* tcubo16 = cubo16->copy_cubo2();
        Cubo* tcubo19 = cubo19->copy_cubo2(); Cubo* tcubo22 = cubo22->copy_cubo2(); Cubo* tcubo25 = cubo25->copy_cubo2();

        cubo1->cara1->copy_color_cara(tcubo7->cara4);
        cubo4->cara1->copy_color_cara(tcubo16->cara4);
        cubo7->cara1->copy_color_cara(tcubo25->cara4);

        cubo7->cara4->copy_color_cara(tcubo25->cara2);
        cubo16->cara4->copy_color_cara(tcubo22->cara2);
        cubo25->cara4->copy_color_cara(tcubo19->cara2);

        cubo25->cara2->copy_color_cara(tcubo19->cara3);
        cubo22->cara2->copy_color_cara(tcubo10->cara3);
        cubo19->cara2->copy_color_cara(tcubo1->cara3);

        cubo19->cara3->copy_color_cara(tcubo1->cara1);
        cubo10->cara3->copy_color_cara(tcubo4->cara1);
        cubo1->cara3->copy_color_cara(tcubo7->cara1);



        cubo1->cara6->copy_color_cara(tcubo7->cara6);
        cubo4->cara6->copy_color_cara(tcubo16->cara6);
        cubo7->cara6->copy_color_cara(tcubo25->cara6);
        cubo10->cara6->copy_color_cara(tcubo4->cara6);

        cubo16->cara6->copy_color_cara(tcubo22->cara6);
        cubo19->cara6->copy_color_cara(tcubo1->cara6);
        cubo22->cara6->copy_color_cara(tcubo10->cara6);
        cubo25->cara6->copy_color_cara(tcubo19->cara6);



        cubo1->tipo_cubo = change_letter(tcubo7->tipo_cubo);
        cubo4->tipo_cubo = change_letter(tcubo16->tipo_cubo);
        cubo7->tipo_cubo = change_letter(tcubo25->tipo_cubo);

        cubo7->tipo_cubo = change_letter(tcubo25->tipo_cubo);
        cubo16->tipo_cubo = change_letter(tcubo22->tipo_cubo);
        cubo25->tipo_cubo = change_letter(tcubo19->tipo_cubo);

        cubo25->tipo_cubo = change_letter(tcubo19->tipo_cubo);
        cubo22->tipo_cubo = change_letter(tcubo10->tipo_cubo);
        cubo19->tipo_cubo = change_letter(tcubo1->tipo_cubo);

        cubo19->tipo_cubo = change_letter(tcubo1->tipo_cubo);
        cubo10->tipo_cubo = change_letter(tcubo4->tipo_cubo);
        cubo1->tipo_cubo = change_letter(tcubo7->tipo_cubo);
    }
    // CENTER
    void colorear_mov5() {
        // cubo_ideal 2 5 8 11 14 17 20 23 26   ----   2592 posiciones
        Cubo* tcubo2 = cubo2->copy_cubo2(); Cubo* tcubo5 = cubo5->copy_cubo2(); Cubo* tcubo8 = cubo8->copy_cubo2();
        Cubo* tcubo11 = cubo11->copy_cubo2(); Cubo* tcubo14 = cubo14->copy_cubo2(); Cubo* tcubo17 = cubo17->copy_cubo2();
        Cubo* tcubo20 = cubo20->copy_cubo2(); Cubo* tcubo23 = cubo23->copy_cubo2(); Cubo* tcubo26 = cubo26->copy_cubo2();

        cubo2->cara1->copy_color_cara(tcubo8->cara4);
        cubo5->cara1->copy_color_cara(tcubo17->cara4);
        cubo8->cara1->copy_color_cara(tcubo26->cara4);

        cubo8->cara4->copy_color_cara(tcubo26->cara2);
        cubo17->cara4->copy_color_cara(tcubo23->cara2);
        cubo26->cara4->copy_color_cara(tcubo20->cara2);

        cubo26->cara2->copy_color_cara(tcubo20->cara3);
        cubo23->cara2->copy_color_cara(tcubo11->cara3);
        cubo20->cara2->copy_color_cara(tcubo2->cara3);

        cubo20->cara3->copy_color_cara(tcubo2->cara1);
        cubo11->cara3->copy_color_cara(tcubo5->cara1);
        cubo2->cara3->copy_color_cara(tcubo8->cara1);
    }
    // FRONT
    void colorear_mov6() {
        // cubo_ideal 3 6 9 12 15 18 21 24 27   ----   2592 posiciones
        Cubo* tcubo3 = cubo3->copy_cubo2(); Cubo* tcubo6 = cubo6->copy_cubo2(); Cubo* tcubo9 = cubo9->copy_cubo2();
        Cubo* tcubo12 = cubo12->copy_cubo2(); Cubo* tcubo15 = cubo15->copy_cubo2(); Cubo* tcubo18 = cubo18->copy_cubo2();
        Cubo* tcubo21 = cubo21->copy_cubo2(); Cubo* tcubo24 = cubo24->copy_cubo2(); Cubo* tcubo27 = cubo27->copy_cubo2();

        cubo3->cara1->copy_color_cara(tcubo9->cara4);
        cubo6->cara1->copy_color_cara(tcubo18->cara4);
        cubo9->cara1->copy_color_cara(tcubo27->cara4);

        cubo9->cara4->copy_color_cara(tcubo27->cara2);
        cubo18->cara4->copy_color_cara(tcubo24->cara2);
        cubo27->cara4->copy_color_cara(tcubo21->cara2);

        cubo27->cara2->copy_color_cara(tcubo21->cara3);
        cubo24->cara2->copy_color_cara(tcubo12->cara3);
        cubo21->cara2->copy_color_cara(tcubo3->cara3);

        cubo21->cara3->copy_color_cara(tcubo3->cara1);
        cubo12->cara3->copy_color_cara(tcubo6->cara1);
        cubo3->cara3->copy_color_cara(tcubo9->cara1);



        cubo3->cara5->copy_color_cara(tcubo9->cara5);
        cubo6->cara5->copy_color_cara(tcubo18->cara5);
        cubo9->cara5->copy_color_cara(tcubo27->cara5);
        cubo12->cara5->copy_color_cara(tcubo6->cara5);

        cubo18->cara5->copy_color_cara(tcubo24->cara5);
        cubo21->cara5->copy_color_cara(tcubo3->cara5);
        cubo24->cara5->copy_color_cara(tcubo12->cara5);
        cubo27->cara5->copy_color_cara(tcubo21->cara5);



        cubo3->tipo_cubo = change_letter(tcubo9->tipo_cubo);
        cubo6->tipo_cubo = change_letter(tcubo18->tipo_cubo);
        cubo9->tipo_cubo = change_letter(tcubo27->tipo_cubo);

        cubo9->tipo_cubo = change_letter(tcubo27->tipo_cubo);
        cubo18->tipo_cubo = change_letter(tcubo24->tipo_cubo);
        cubo27->tipo_cubo = change_letter(tcubo21->tipo_cubo);

        cubo27->tipo_cubo = change_letter(tcubo21->tipo_cubo);
        cubo24->tipo_cubo = change_letter(tcubo12->tipo_cubo);
        cubo21->tipo_cubo = change_letter(tcubo3->tipo_cubo);

        cubo21->tipo_cubo = change_letter(tcubo3->tipo_cubo);
        cubo12->tipo_cubo = change_letter(tcubo6->tipo_cubo);
        cubo3->tipo_cubo = change_letter(tcubo9->tipo_cubo);
    }

    // LEFT
    void colorear_mov7() {
        // cubo_ideal 1 2 3 4 5 6 7 8 9   ----   2592 posiciones
        Cubo* tcubo1 = cubo1->copy_cubo2(); Cubo* tcubo2 = cubo2->copy_cubo2(); Cubo* tcubo3 = cubo3->copy_cubo2();
        Cubo* tcubo4 = cubo4->copy_cubo2(); Cubo* tcubo5 = cubo5->copy_cubo2(); Cubo* tcubo6 = cubo6->copy_cubo2();
        Cubo* tcubo7 = cubo7->copy_cubo2(); Cubo* tcubo8 = cubo8->copy_cubo2(); Cubo* tcubo9 = cubo9->copy_cubo2();

        cubo3->cara3->copy_color_cara(tcubo9->cara5);
        cubo2->cara3->copy_color_cara(tcubo6->cara5);
        cubo1->cara3->copy_color_cara(tcubo3->cara5);

        cubo9->cara5->copy_color_cara(tcubo7->cara4);
        cubo6->cara5->copy_color_cara(tcubo8->cara4);
        cubo3->cara5->copy_color_cara(tcubo9->cara4);

        cubo7->cara4->copy_color_cara(tcubo1->cara6);
        cubo8->cara4->copy_color_cara(tcubo4->cara6);
        cubo9->cara4->copy_color_cara(tcubo7->cara6);

        cubo1->cara6->copy_color_cara(tcubo3->cara3);
        cubo4->cara6->copy_color_cara(tcubo2->cara3);
        cubo7->cara6->copy_color_cara(tcubo1->cara3);


        cubo1->cara1->copy_color_cara(tcubo3->cara1);
        cubo2->cara1->copy_color_cara(tcubo6->cara1);
        cubo3->cara1->copy_color_cara(tcubo9->cara1);

        cubo4->cara1->copy_color_cara(tcubo2->cara1);
        cubo6->cara1->copy_color_cara(tcubo8->cara1);

        cubo7->cara1->copy_color_cara(tcubo1->cara1);
        cubo8->cara1->copy_color_cara(tcubo4->cara1);
        cubo9->cara1->copy_color_cara(tcubo7->cara1);



        cubo3->tipo_cubo = change_letter(tcubo9->tipo_cubo);
        cubo2->tipo_cubo = change_letter(tcubo6->tipo_cubo);
        cubo1->tipo_cubo = change_letter(tcubo3->tipo_cubo);

        cubo9->tipo_cubo = change_letter(tcubo7->tipo_cubo);
        cubo6->tipo_cubo = change_letter(tcubo8->tipo_cubo);
        cubo3->tipo_cubo = change_letter(tcubo9->tipo_cubo);

        cubo7->tipo_cubo = change_letter(tcubo1->tipo_cubo);
        cubo8->tipo_cubo = change_letter(tcubo4->tipo_cubo);
        cubo9->tipo_cubo = change_letter(tcubo7->tipo_cubo);

        cubo1->tipo_cubo = change_letter(tcubo3->tipo_cubo);
        cubo4->tipo_cubo = change_letter(tcubo2->tipo_cubo);
        cubo7->tipo_cubo = change_letter(tcubo1->tipo_cubo);
    }
    // CENTER
    void colorear_mov8() {
        // cubo_ideal 10 11 12 13 14 15 16 17 18   ----   2592 posiciones
        Cubo* tcubo10 = cubo10->copy_cubo2(); Cubo* tcubo11 = cubo11->copy_cubo2(); Cubo* tcubo12 = cubo12->copy_cubo2();
        Cubo* tcubo13 = cubo13->copy_cubo2(); Cubo* tcubo14 = cubo14->copy_cubo2(); Cubo* tcubo15 = cubo15->copy_cubo2();
        Cubo* tcubo16 = cubo16->copy_cubo2(); Cubo* tcubo17 = cubo17->copy_cubo2(); Cubo* tcubo18 = cubo18->copy_cubo2();

        cubo12->cara3->copy_color_cara(tcubo18->cara5);
        cubo11->cara3->copy_color_cara(tcubo15->cara5);
        cubo10->cara3->copy_color_cara(tcubo12->cara5);

        cubo18->cara5->copy_color_cara(tcubo16->cara4);
        cubo15->cara5->copy_color_cara(tcubo17->cara4);
        cubo12->cara5->copy_color_cara(tcubo18->cara4);

        cubo16->cara4->copy_color_cara(tcubo10->cara6);
        cubo17->cara4->copy_color_cara(tcubo13->cara6);
        cubo18->cara4->copy_color_cara(tcubo16->cara6);

        cubo10->cara6->copy_color_cara(tcubo12->cara3);
        cubo13->cara6->copy_color_cara(tcubo11->cara3);
        cubo16->cara6->copy_color_cara(tcubo10->cara3);
    }
    // RIGHT
    void colorear_mov9() {
        // cubo_ideal 19 20 21 22 23 24 25 26 27   ----   2592 posiciones
        Cubo* tcubo19 = cubo19->copy_cubo2(); Cubo* tcubo20 = cubo20->copy_cubo2(); Cubo* tcubo21 = cubo21->copy_cubo2();
        Cubo* tcubo22 = cubo22->copy_cubo2(); Cubo* tcubo23 = cubo23->copy_cubo2(); Cubo* tcubo24 = cubo24->copy_cubo2();
        Cubo* tcubo25 = cubo25->copy_cubo2(); Cubo* tcubo26 = cubo26->copy_cubo2(); Cubo* tcubo27 = cubo27->copy_cubo2();

        cubo21->cara3->copy_color_cara(tcubo27->cara5);
        cubo20->cara3->copy_color_cara(tcubo24->cara5);
        cubo19->cara3->copy_color_cara(tcubo21->cara5);

        cubo27->cara5->copy_color_cara(tcubo25->cara4);
        cubo24->cara5->copy_color_cara(tcubo26->cara4);
        cubo21->cara5->copy_color_cara(tcubo27->cara4);

        cubo25->cara4->copy_color_cara(tcubo19->cara6);
        cubo26->cara4->copy_color_cara(tcubo22->cara6);
        cubo27->cara4->copy_color_cara(tcubo25->cara6);

        cubo19->cara6->copy_color_cara(tcubo21->cara3);
        cubo22->cara6->copy_color_cara(tcubo20->cara3);
        cubo25->cara6->copy_color_cara(tcubo19->cara3);



        cubo19->cara2->copy_color_cara(tcubo21->cara2);
        cubo20->cara2->copy_color_cara(tcubo24->cara2);
        cubo21->cara2->copy_color_cara(tcubo27->cara2);

        cubo22->cara2->copy_color_cara(tcubo20->cara2);
        cubo24->cara2->copy_color_cara(tcubo26->cara2);

        cubo25->cara2->copy_color_cara(tcubo19->cara2);
        cubo26->cara2->copy_color_cara(tcubo22->cara2);
        cubo27->cara2->copy_color_cara(tcubo25->cara2);



        cubo21->tipo_cubo = change_letter(tcubo27->tipo_cubo);
        cubo20->tipo_cubo = change_letter(tcubo24->tipo_cubo);
        cubo19->tipo_cubo = change_letter(tcubo21->tipo_cubo);

        cubo27->tipo_cubo = change_letter(tcubo25->tipo_cubo);
        cubo24->tipo_cubo = change_letter(tcubo26->tipo_cubo);
        cubo21->tipo_cubo = change_letter(tcubo27->tipo_cubo);

        cubo25->tipo_cubo = change_letter(tcubo19->tipo_cubo);
        cubo26->tipo_cubo = change_letter(tcubo22->tipo_cubo);
        cubo27->tipo_cubo = change_letter(tcubo25->tipo_cubo);

        cubo19->tipo_cubo = change_letter(tcubo21->tipo_cubo);
        cubo22->tipo_cubo = change_letter(tcubo20->tipo_cubo);
        cubo25->tipo_cubo = change_letter(tcubo19->tipo_cubo);
    }



    // CONTRARELOJ ---------------------------------- REVERSE
    // DOWN
    void colorear_mov10() {
        // cubo_ideal 1 2 3 10 11 12 19 20 21   ----   2592 posiciones
        Cubo* tcubo1 = cubo1->copy_cubo2(); Cubo* tcubo2 = cubo2->copy_cubo2(); Cubo* tcubo3 = cubo3->copy_cubo2();
        Cubo* tcubo10 = cubo10->copy_cubo2(); Cubo* tcubo11 = cubo11->copy_cubo2(); Cubo* tcubo12 = cubo12->copy_cubo2();
        Cubo* tcubo19 = cubo19->copy_cubo2(); Cubo* tcubo20 = cubo20->copy_cubo2(); Cubo* tcubo21 = cubo21->copy_cubo2();

        cubo1->cara1->copy_color_cara(tcubo19->cara6);
        cubo2->cara1->copy_color_cara(tcubo10->cara6);
        cubo3->cara1->copy_color_cara(tcubo1->cara6);

        cubo19->cara6->copy_color_cara(tcubo21->cara2);
        cubo10->cara6->copy_color_cara(tcubo20->cara2);
        cubo1->cara6->copy_color_cara(tcubo19->cara2);

        cubo21->cara2->copy_color_cara(tcubo3->cara5);
        cubo20->cara2->copy_color_cara(tcubo12->cara5);
        cubo19->cara2->copy_color_cara(tcubo21->cara5);

        cubo3->cara5->copy_color_cara(tcubo1->cara1);
        cubo12->cara5->copy_color_cara(tcubo2->cara1);
        cubo21->cara5->copy_color_cara(tcubo3->cara1);



        cubo1->cara3->copy_color_cara(tcubo19->cara3);
        cubo2->cara3->copy_color_cara(tcubo10->cara3);
        cubo3->cara3->copy_color_cara(tcubo1->cara3);
        cubo10->cara3->copy_color_cara(tcubo20->cara3);

        cubo12->cara3->copy_color_cara(tcubo2->cara3);
        cubo19->cara3->copy_color_cara(tcubo21->cara3);
        cubo20->cara3->copy_color_cara(tcubo12->cara3);
        cubo21->cara3->copy_color_cara(tcubo3->cara3);



        cubo1->tipo_cubo = tcubo19->tipo_cubo;
        cubo2->tipo_cubo = tcubo10->tipo_cubo;
        cubo3->tipo_cubo = tcubo1->tipo_cubo;

        cubo19->tipo_cubo = tcubo21->tipo_cubo;
        cubo10->tipo_cubo = tcubo20->tipo_cubo;
        cubo1->tipo_cubo = tcubo19->tipo_cubo;

        cubo21->tipo_cubo = tcubo3->tipo_cubo;
        cubo20->tipo_cubo = tcubo12->tipo_cubo;
        cubo19->tipo_cubo = tcubo21->tipo_cubo;

        cubo3->tipo_cubo = tcubo1->tipo_cubo;
        cubo12->tipo_cubo = tcubo2->tipo_cubo;
        cubo21->tipo_cubo = tcubo3->tipo_cubo;
    }
    // CENTER
    void colorear_mov11() {
        // cubo_ideal 4 5 6 13 14 15 22 23 24   ----   2592 posiciones
        Cubo* tcubo4 = cubo4->copy_cubo2(); Cubo* tcubo5 = cubo5->copy_cubo2(); Cubo* tcubo6 = cubo6->copy_cubo2();
        Cubo* tcubo13 = cubo13->copy_cubo2(); Cubo* tcubo14 = cubo14->copy_cubo2(); Cubo* tcubo15 = cubo15->copy_cubo2();
        Cubo* tcubo22 = cubo22->copy_cubo2(); Cubo* tcubo23 = cubo23->copy_cubo2(); Cubo* tcubo24 = cubo24->copy_cubo2();

        cubo4->cara1->copy_color_cara(tcubo22->cara6);
        cubo5->cara1->copy_color_cara(tcubo13->cara6);
        cubo6->cara1->copy_color_cara(tcubo4->cara6);

        cubo22->cara6->copy_color_cara(tcubo24->cara2);
        cubo13->cara6->copy_color_cara(tcubo23->cara2);
        cubo4->cara6->copy_color_cara(tcubo22->cara2);

        cubo24->cara2->copy_color_cara(tcubo6->cara5);
        cubo23->cara2->copy_color_cara(tcubo15->cara5);
        cubo22->cara2->copy_color_cara(tcubo24->cara5);

        cubo6->cara5->copy_color_cara(tcubo4->cara1);
        cubo15->cara5->copy_color_cara(tcubo5->cara1);
        cubo24->cara5->copy_color_cara(tcubo6->cara1);
    }
    // UP
    void colorear_mov12() {
        Cubo* tcubo7 = cubo7->copy_cubo2(); Cubo* tcubo8 = cubo8->copy_cubo2(); Cubo* tcubo9 = cubo9->copy_cubo2();
        Cubo* tcubo16 = cubo16->copy_cubo2(); Cubo* tcubo17 = cubo17->copy_cubo2(); Cubo* tcubo18 = cubo18->copy_cubo2();
        Cubo* tcubo25 = cubo25->copy_cubo2(); Cubo* tcubo26 = cubo26->copy_cubo2(); Cubo* tcubo27 = cubo27->copy_cubo2();

        cubo7->cara1->copy_color_cara(tcubo25->cara6);
        cubo8->cara1->copy_color_cara(tcubo16->cara6);
        cubo9->cara1->copy_color_cara(tcubo7->cara6);

        cubo25->cara6->copy_color_cara(tcubo27->cara2);
        cubo16->cara6->copy_color_cara(tcubo26->cara2);
        cubo7->cara6->copy_color_cara(tcubo25->cara2);

        cubo27->cara2->copy_color_cara(tcubo9->cara5);
        cubo26->cara2->copy_color_cara(tcubo18->cara5);
        cubo25->cara2->copy_color_cara(tcubo27->cara5);

        cubo9->cara5->copy_color_cara(tcubo7->cara1);
        cubo18->cara5->copy_color_cara(tcubo8->cara1);
        cubo27->cara5->copy_color_cara(tcubo9->cara1);



        cubo7->cara4->copy_color_cara(tcubo25->cara4);
        cubo8->cara4->copy_color_cara(tcubo16->cara4);
        cubo9->cara4->copy_color_cara(tcubo7->cara4);
        cubo16->cara4->copy_color_cara(tcubo26->cara4);

        cubo18->cara4->copy_color_cara(tcubo8->cara4);
        cubo25->cara4->copy_color_cara(tcubo27->cara4);
        cubo26->cara4->copy_color_cara(tcubo18->cara4);
        cubo27->cara4->copy_color_cara(tcubo9->cara4);




        cubo7->tipo_cubo = tcubo25->tipo_cubo;
        cubo8->tipo_cubo = tcubo16->tipo_cubo;
        cubo9->tipo_cubo = tcubo7->tipo_cubo;

        cubo25->tipo_cubo = tcubo27->tipo_cubo;
        cubo16->tipo_cubo = tcubo26->tipo_cubo;
        cubo7->tipo_cubo = tcubo25->tipo_cubo;

        cubo27->tipo_cubo = tcubo9->tipo_cubo;
        cubo26->tipo_cubo = tcubo18->tipo_cubo;
        cubo25->tipo_cubo = tcubo27->tipo_cubo;

        cubo9->tipo_cubo = tcubo7->tipo_cubo;
        cubo18->tipo_cubo = tcubo8->tipo_cubo;
        cubo27->tipo_cubo = tcubo9->tipo_cubo;
    }

    // BACK
    void colorear_mov13() {
        // cubo_ideal 1 4 7 10 13 16 19 22 25   ----   2592 posiciones
        Cubo* tcubo1 = cubo1->copy_cubo2(); Cubo* tcubo4 = cubo4->copy_cubo2(); Cubo* tcubo7 = cubo7->copy_cubo2();
        Cubo* tcubo10 = cubo10->copy_cubo2(); Cubo* tcubo13 = cubo13->copy_cubo2(); Cubo* tcubo16 = cubo16->copy_cubo2();
        Cubo* tcubo19 = cubo19->copy_cubo2(); Cubo* tcubo22 = cubo22->copy_cubo2(); Cubo* tcubo25 = cubo25->copy_cubo2();

        cubo1->cara1->copy_color_cara(tcubo19->cara3);
        cubo4->cara1->copy_color_cara(tcubo10->cara3);
        cubo7->cara1->copy_color_cara(tcubo1->cara3);

        cubo19->cara3->copy_color_cara(tcubo25->cara2);
        cubo10->cara3->copy_color_cara(tcubo22->cara2);
        cubo1->cara3->copy_color_cara(tcubo19->cara2);

        cubo25->cara2->copy_color_cara(tcubo7->cara4);
        cubo22->cara2->copy_color_cara(tcubo16->cara4);
        cubo19->cara2->copy_color_cara(tcubo25->cara4);

        cubo7->cara4->copy_color_cara(tcubo1->cara1);
        cubo16->cara4->copy_color_cara(tcubo4->cara1);
        cubo25->cara4->copy_color_cara(tcubo7->cara1);




        cubo1->cara6->copy_color_cara(tcubo19->cara6);
        cubo4->cara6->copy_color_cara(tcubo10->cara6);
        cubo7->cara6->copy_color_cara(tcubo1->cara6);
        cubo10->cara6->copy_color_cara(tcubo22->cara6);

        cubo16->cara6->copy_color_cara(tcubo4->cara6);
        cubo19->cara6->copy_color_cara(tcubo25->cara6);
        cubo22->cara6->copy_color_cara(tcubo16->cara6);
        cubo25->cara6->copy_color_cara(tcubo7->cara6);





        cubo1->tipo_cubo = tcubo19->tipo_cubo;
        cubo4->tipo_cubo = tcubo10->tipo_cubo;
        cubo7->tipo_cubo = tcubo1->tipo_cubo;

        cubo19->tipo_cubo = tcubo25->tipo_cubo;
        cubo10->tipo_cubo = tcubo22->tipo_cubo;
        cubo1->tipo_cubo = tcubo19->tipo_cubo;

        cubo25->tipo_cubo = tcubo7->tipo_cubo;
        cubo22->tipo_cubo = tcubo16->tipo_cubo;
        cubo19->tipo_cubo = tcubo25->tipo_cubo;

        cubo7->tipo_cubo = tcubo1->tipo_cubo;
        cubo16->tipo_cubo = tcubo4->tipo_cubo;
        cubo25->tipo_cubo = tcubo7->tipo_cubo;
    }
    // CENTER
    void colorear_mov14() {
        // cubo_ideal 2 5 8 11 14 17 20 23 26   ----   2592 posiciones
        Cubo* tcubo2 = cubo2->copy_cubo2(); Cubo* tcubo5 = cubo5->copy_cubo2(); Cubo* tcubo8 = cubo8->copy_cubo2();
        Cubo* tcubo11 = cubo11->copy_cubo2(); Cubo* tcubo14 = cubo14->copy_cubo2(); Cubo* tcubo17 = cubo17->copy_cubo2();
        Cubo* tcubo20 = cubo20->copy_cubo2(); Cubo* tcubo23 = cubo23->copy_cubo2(); Cubo* tcubo26 = cubo26->copy_cubo2();

        cubo2->cara1->copy_color_cara(tcubo20->cara3);
        cubo5->cara1->copy_color_cara(tcubo11->cara3);
        cubo8->cara1->copy_color_cara(tcubo2->cara3);

        cubo20->cara3->copy_color_cara(tcubo26->cara2);
        cubo11->cara3->copy_color_cara(tcubo23->cara2);
        cubo2->cara3->copy_color_cara(tcubo20->cara2);

        cubo26->cara2->copy_color_cara(tcubo8->cara4);
        cubo23->cara2->copy_color_cara(tcubo17->cara4);
        cubo20->cara2->copy_color_cara(tcubo26->cara4);

        cubo8->cara4->copy_color_cara(tcubo2->cara1);
        cubo17->cara4->copy_color_cara(tcubo5->cara1);
        cubo26->cara4->copy_color_cara(tcubo8->cara1);
    }
    // FRONT
    void colorear_mov15() {
        // cubo_ideal 3 6 9 12 15 18 21 24 27   ----   2592 posiciones
        Cubo* tcubo3 = cubo3->copy_cubo2(); Cubo* tcubo6 = cubo6->copy_cubo2(); Cubo* tcubo9 = cubo9->copy_cubo2();
        Cubo* tcubo12 = cubo12->copy_cubo2(); Cubo* tcubo15 = cubo15->copy_cubo2(); Cubo* tcubo18 = cubo18->copy_cubo2();
        Cubo* tcubo21 = cubo21->copy_cubo2(); Cubo* tcubo24 = cubo24->copy_cubo2(); Cubo* tcubo27 = cubo27->copy_cubo2();

        cubo3->cara1->copy_color_cara(tcubo21->cara3);
        cubo6->cara1->copy_color_cara(tcubo12->cara3);
        cubo9->cara1->copy_color_cara(tcubo3->cara3);

        cubo21->cara3->copy_color_cara(tcubo27->cara2);
        cubo12->cara3->copy_color_cara(tcubo24->cara2);
        cubo3->cara3->copy_color_cara(tcubo21->cara2);

        cubo27->cara2->copy_color_cara(tcubo9->cara4);
        cubo24->cara2->copy_color_cara(tcubo18->cara4);
        cubo21->cara2->copy_color_cara(tcubo27->cara4);

        cubo9->cara4->copy_color_cara(tcubo3->cara1);
        cubo18->cara4->copy_color_cara(tcubo6->cara1);
        cubo27->cara4->copy_color_cara(tcubo9->cara1);




        cubo3->cara5->copy_color_cara(tcubo21->cara5);
        cubo6->cara5->copy_color_cara(tcubo12->cara5);
        cubo9->cara5->copy_color_cara(tcubo3->cara5);
        cubo12->cara5->copy_color_cara(tcubo24->cara5);

        cubo18->cara5->copy_color_cara(tcubo6->cara5);
        cubo21->cara5->copy_color_cara(tcubo27->cara5);
        cubo24->cara5->copy_color_cara(tcubo18->cara5);
        cubo27->cara5->copy_color_cara(tcubo9->cara5);




        cubo3->tipo_cubo = tcubo21->tipo_cubo;
        cubo6->tipo_cubo = tcubo12->tipo_cubo;
        cubo9->tipo_cubo = tcubo3->tipo_cubo;

        cubo21->tipo_cubo = tcubo27->tipo_cubo;
        cubo12->tipo_cubo = tcubo24->tipo_cubo;
        cubo3->tipo_cubo = tcubo21->tipo_cubo;

        cubo27->tipo_cubo = tcubo9->tipo_cubo;
        cubo24->tipo_cubo = tcubo18->tipo_cubo;
        cubo21->tipo_cubo = tcubo27->tipo_cubo;

        cubo9->tipo_cubo = tcubo3->tipo_cubo;
        cubo18->tipo_cubo = tcubo6->tipo_cubo;
        cubo27->tipo_cubo = tcubo9->tipo_cubo;
    }

    // LEFT
    void colorear_mov16() {
        // cubo_ideal 1 2 3 4 5 6 7 8 9   ----   2592 posiciones
        Cubo* tcubo1 = cubo1->copy_cubo2(); Cubo* tcubo2 = cubo2->copy_cubo2(); Cubo* tcubo3 = cubo3->copy_cubo2();
        Cubo* tcubo4 = cubo4->copy_cubo2(); Cubo* tcubo5 = cubo5->copy_cubo2(); Cubo* tcubo6 = cubo6->copy_cubo2();
        Cubo* tcubo7 = cubo7->copy_cubo2(); Cubo* tcubo8 = cubo8->copy_cubo2(); Cubo* tcubo9 = cubo9->copy_cubo2();

        cubo1->cara3->copy_color_cara(tcubo7->cara6);
        cubo2->cara3->copy_color_cara(tcubo4->cara6);
        cubo3->cara3->copy_color_cara(tcubo1->cara6);

        cubo7->cara6->copy_color_cara(tcubo9->cara4);
        cubo4->cara6->copy_color_cara(tcubo8->cara4);
        cubo1->cara6->copy_color_cara(tcubo7->cara4);

        cubo9->cara4->copy_color_cara(tcubo3->cara5);
        cubo8->cara4->copy_color_cara(tcubo6->cara5);
        cubo7->cara4->copy_color_cara(tcubo9->cara5);

        cubo3->cara5->copy_color_cara(tcubo1->cara3);
        cubo6->cara5->copy_color_cara(tcubo2->cara3);
        cubo9->cara5->copy_color_cara(tcubo3->cara3);




        cubo1->cara1->copy_color_cara(tcubo7->cara1);
        cubo2->cara1->copy_color_cara(tcubo4->cara1);
        cubo3->cara1->copy_color_cara(tcubo1->cara1);

        cubo4->cara1->copy_color_cara(tcubo8->cara1);
        cubo6->cara1->copy_color_cara(tcubo2->cara1);

        cubo7->cara1->copy_color_cara(tcubo9->cara1);
        cubo8->cara1->copy_color_cara(tcubo6->cara1);
        cubo9->cara1->copy_color_cara(tcubo3->cara1);




        cubo1->tipo_cubo = tcubo7->tipo_cubo;
        cubo2->tipo_cubo = tcubo4->tipo_cubo;
        cubo3->tipo_cubo = tcubo1->tipo_cubo;

        cubo7->tipo_cubo = tcubo9->tipo_cubo;
        cubo4->tipo_cubo = tcubo8->tipo_cubo;
        cubo1->tipo_cubo = tcubo7->tipo_cubo;

        cubo9->tipo_cubo = tcubo3->tipo_cubo;
        cubo8->tipo_cubo = tcubo6->tipo_cubo;
        cubo7->tipo_cubo = tcubo9->tipo_cubo;

        cubo3->tipo_cubo = tcubo1->tipo_cubo;
        cubo6->tipo_cubo = tcubo2->tipo_cubo;
        cubo9->tipo_cubo = tcubo3->tipo_cubo;
    }
    // CENTER
    void colorear_mov17() {
        // cubo_ideal 10 11 12 13 14 15 16 17 18   ----   2592 posiciones
        Cubo* tcubo10 = cubo10->copy_cubo2(); Cubo* tcubo11 = cubo11->copy_cubo2(); Cubo* tcubo12 = cubo12->copy_cubo2();
        Cubo* tcubo13 = cubo13->copy_cubo2(); Cubo* tcubo14 = cubo14->copy_cubo2(); Cubo* tcubo15 = cubo15->copy_cubo2();
        Cubo* tcubo16 = cubo16->copy_cubo2(); Cubo* tcubo17 = cubo17->copy_cubo2(); Cubo* tcubo18 = cubo18->copy_cubo2();

        cubo10->cara3->copy_color_cara(tcubo16->cara6);
        cubo11->cara3->copy_color_cara(tcubo13->cara6);
        cubo12->cara3->copy_color_cara(tcubo10->cara6);

        cubo16->cara6->copy_color_cara(tcubo18->cara4);
        cubo13->cara6->copy_color_cara(tcubo17->cara4);
        cubo10->cara6->copy_color_cara(tcubo16->cara4);

        cubo18->cara4->copy_color_cara(tcubo12->cara5);
        cubo17->cara4->copy_color_cara(tcubo15->cara5);
        cubo16->cara4->copy_color_cara(tcubo18->cara5);

        cubo12->cara5->copy_color_cara(tcubo10->cara3);
        cubo15->cara5->copy_color_cara(tcubo11->cara3);
        cubo18->cara5->copy_color_cara(tcubo12->cara3);
    }
    // RIGHT
    void colorear_mov18() {
        // cubo_ideal 19 20 21 22 23 24 25 26 27   ----   2592 posiciones
        Cubo* tcubo19 = cubo19->copy_cubo2(); Cubo* tcubo20 = cubo20->copy_cubo2(); Cubo* tcubo21 = cubo21->copy_cubo2();
        Cubo* tcubo22 = cubo22->copy_cubo2(); Cubo* tcubo23 = cubo23->copy_cubo2(); Cubo* tcubo24 = cubo24->copy_cubo2();
        Cubo* tcubo25 = cubo25->copy_cubo2(); Cubo* tcubo26 = cubo26->copy_cubo2(); Cubo* tcubo27 = cubo27->copy_cubo2();

        cubo19->cara3->copy_color_cara(tcubo25->cara6);
        cubo20->cara3->copy_color_cara(tcubo22->cara6);
        cubo21->cara3->copy_color_cara(tcubo19->cara6);

        cubo25->cara6->copy_color_cara(tcubo27->cara4);
        cubo22->cara6->copy_color_cara(tcubo26->cara4);
        cubo19->cara6->copy_color_cara(tcubo25->cara4);

        cubo27->cara4->copy_color_cara(tcubo21->cara5);
        cubo26->cara4->copy_color_cara(tcubo24->cara5);
        cubo25->cara4->copy_color_cara(tcubo27->cara5);

        cubo21->cara5->copy_color_cara(tcubo19->cara3);
        cubo24->cara5->copy_color_cara(tcubo20->cara3);
        cubo27->cara5->copy_color_cara(tcubo21->cara3);



        cubo19->cara2->copy_color_cara(tcubo25->cara2);
        cubo20->cara2->copy_color_cara(tcubo22->cara2);
        cubo21->cara2->copy_color_cara(tcubo19->cara2);

        cubo22->cara2->copy_color_cara(tcubo26->cara2);
        cubo24->cara2->copy_color_cara(tcubo20->cara2);

        cubo25->cara2->copy_color_cara(tcubo27->cara2);
        cubo26->cara2->copy_color_cara(tcubo24->cara2);
        cubo27->cara2->copy_color_cara(tcubo21->cara2);



        cubo19->tipo_cubo = tcubo25->tipo_cubo;
        cubo20->tipo_cubo = tcubo22->tipo_cubo;
        cubo21->tipo_cubo = tcubo19->tipo_cubo;

        cubo25->tipo_cubo = tcubo27->tipo_cubo;
        cubo22->tipo_cubo = tcubo26->tipo_cubo;
        cubo19->tipo_cubo = tcubo25->tipo_cubo;

        cubo27->tipo_cubo = tcubo21->tipo_cubo;
        cubo26->tipo_cubo = tcubo24->tipo_cubo;
        cubo25->tipo_cubo = tcubo27->tipo_cubo;

        cubo21->tipo_cubo = tcubo19->tipo_cubo;
        cubo24->tipo_cubo = tcubo20->tipo_cubo;
        cubo27->tipo_cubo = tcubo21->tipo_cubo;
    }


    void animar1(float* dinamic_vertex, float* static_vertex) {
        float velocidad = 0.02;
        
        cubo1->modificar(-velocidad, -velocidad, -velocidad);
        cubo2->modificar(-velocidad, -velocidad, 0);
        cubo3->modificar(-velocidad, -velocidad, velocidad);

        cubo4->modificar(-velocidad, 0, -velocidad);
        cubo5->modificar(-velocidad, 0, 0);
        cubo6->modificar(-velocidad, 0, velocidad);

        cubo7->modificar(-velocidad, velocidad, -velocidad);
        cubo8->modificar(-velocidad, velocidad, 0);
        cubo9->modificar(-velocidad, velocidad, velocidad);


        cubo10->modificar(0, -velocidad, -velocidad);
        cubo11->modificar(0, -velocidad, 0);
        cubo12->modificar(0, -velocidad, velocidad);

        cubo13->modificar(0, 0, -velocidad);
        cubo14->modificar(0, 0, 0);
        cubo15->modificar(0, 0, velocidad);

        cubo16->modificar(0, velocidad, -velocidad);
        cubo17->modificar(0, velocidad, 0);
        cubo18->modificar(0, velocidad, velocidad);


        cubo19->modificar(velocidad, -velocidad, -velocidad);
        cubo20->modificar(velocidad, -velocidad, 0);
        cubo21->modificar(velocidad, -velocidad, velocidad);

        cubo22->modificar(velocidad, 0, -velocidad);
        cubo23->modificar(velocidad, 0, 0);
        cubo24->modificar(velocidad, 0, velocidad);

        cubo25->modificar(velocidad, velocidad, -velocidad);
        cubo26->modificar(velocidad, velocidad, 0);
        cubo27->modificar(velocidad, velocidad, velocidad);

        add_value(dinamic_vertex, static_vertex);
    }

    void animar2(float* dinamic_vertex, float* static_vertex) {
        float velocidad = -0.02;

        cubo1->modificar(-velocidad, -velocidad, -velocidad);
        cubo2->modificar(-velocidad, -velocidad, 0);
        cubo3->modificar(-velocidad, -velocidad, velocidad);

        cubo4->modificar(-velocidad, 0, -velocidad);
        cubo5->modificar(-velocidad, 0, 0);
        cubo6->modificar(-velocidad, 0, velocidad);

        cubo7->modificar(-velocidad, velocidad, -velocidad);
        cubo8->modificar(-velocidad, velocidad, 0);
        cubo9->modificar(-velocidad, velocidad, velocidad);


        cubo10->modificar(0, -velocidad, -velocidad);
        cubo11->modificar(0, -velocidad, 0);
        cubo12->modificar(0, -velocidad, velocidad);

        cubo13->modificar(0, 0, -velocidad);
        cubo14->modificar(0, 0, 0);
        cubo15->modificar(0, 0, velocidad);

        cubo16->modificar(0, velocidad, -velocidad);
        cubo17->modificar(0, velocidad, 0);
        cubo18->modificar(0, velocidad, velocidad);


        cubo19->modificar(velocidad, -velocidad, -velocidad);
        cubo20->modificar(velocidad, -velocidad, 0);
        cubo21->modificar(velocidad, -velocidad, velocidad);

        cubo22->modificar(velocidad, 0, -velocidad);
        cubo23->modificar(velocidad, 0, 0);
        cubo24->modificar(velocidad, 0, velocidad);

        cubo25->modificar(velocidad, velocidad, -velocidad);
        cubo26->modificar(velocidad, velocidad, 0);
        cubo27->modificar(velocidad, velocidad, velocidad);

        add_value(dinamic_vertex, static_vertex);
    }

    void animar3(float* dinamic_vertex, float* static_vertex) {
        float velocidad = -0.02;
        cubo1->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo2->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo3->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo4->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo5->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo6->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo7->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo8->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
        cubo9->cara1->modificar(velocidad, 0, 0); velocidad -= 0.002;
                                                  
        cubo19->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo20->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo21->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo22->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo23->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo24->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo25->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo26->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;
        cubo27->cara2->modificar(-velocidad, 0, 0); velocidad -= 0.002;

        cubo1->cara6->modificar(0, 0, velocidad);   velocidad -= 0.002;
        cubo4->cara6->modificar(0, 0, velocidad);   velocidad -= 0.002;
        cubo7->cara6->modificar(0, 0, velocidad);   velocidad -= 0.002;
        cubo10->cara6->modificar(0, 0, velocidad);  velocidad -= 0.002;
        cubo13->cara6->modificar(0, 0, velocidad);  velocidad -= 0.002;
        cubo16->cara6->modificar(0, 0, velocidad);  velocidad -= 0.002;
        cubo19->cara6->modificar(0, 0, velocidad);  velocidad -= 0.002;
        cubo22->cara6->modificar(0, 0, velocidad);  velocidad -= 0.002;
        cubo25->cara6->modificar(0, 0, velocidad);  velocidad -= 0.002;

        cubo3->cara5->modificar(0, 0, -velocidad);  velocidad -= 0.002;
        cubo6->cara5->modificar(0, 0, -velocidad);  velocidad -= 0.002;
        cubo9->cara5->modificar(0, 0, -velocidad);  velocidad -= 0.002;
        cubo12->cara5->modificar(0, 0, -velocidad); velocidad -= 0.002;
        cubo15->cara5->modificar(0, 0, -velocidad); velocidad -= 0.002;
        cubo18->cara5->modificar(0, 0, -velocidad); velocidad -= 0.002;
        cubo21->cara5->modificar(0, 0, -velocidad); velocidad -= 0.002;
        cubo24->cara5->modificar(0, 0, -velocidad); velocidad -= 0.002;
        cubo27->cara5->modificar(0, 0, -velocidad); velocidad -= 0.002;

        add_value(dinamic_vertex, static_vertex);
    }

    void animar4(float* dinamic_vertex, float* static_vertex) {
        float velocidad = 0.02;
        cubo1->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo2->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo3->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo4->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo5->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo6->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo7->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo8->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;
        cubo9->cara1->modificar(velocidad, 0, 0);   velocidad += 0.002;

        cubo19->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo20->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo21->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo22->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo23->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo24->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo25->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo26->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;
        cubo27->cara2->modificar(-velocidad, 0, 0); velocidad += 0.002;

        cubo1->cara6->modificar(0, 0, velocidad);   velocidad += 0.002;
        cubo4->cara6->modificar(0, 0, velocidad);   velocidad += 0.002;
        cubo7->cara6->modificar(0, 0, velocidad);   velocidad += 0.002;
        cubo10->cara6->modificar(0, 0, velocidad);  velocidad += 0.002;
        cubo13->cara6->modificar(0, 0, velocidad);  velocidad += 0.002;
        cubo16->cara6->modificar(0, 0, velocidad);  velocidad += 0.002;
        cubo19->cara6->modificar(0, 0, velocidad);  velocidad += 0.002;
        cubo22->cara6->modificar(0, 0, velocidad);  velocidad += 0.002;
        cubo25->cara6->modificar(0, 0, velocidad);  velocidad += 0.002;

        cubo3->cara5->modificar(0, 0, -velocidad);  velocidad += 0.002;
        cubo6->cara5->modificar(0, 0, -velocidad);  velocidad += 0.002;
        cubo9->cara5->modificar(0, 0, -velocidad);  velocidad += 0.002;
        cubo12->cara5->modificar(0, 0, -velocidad); velocidad += 0.002;
        cubo15->cara5->modificar(0, 0, -velocidad); velocidad += 0.002;
        cubo18->cara5->modificar(0, 0, -velocidad); velocidad += 0.002;
        cubo21->cara5->modificar(0, 0, -velocidad); velocidad += 0.002;
        cubo24->cara5->modificar(0, 0, -velocidad); velocidad += 0.002;
        cubo27->cara5->modificar(0, 0, -velocidad); velocidad += 0.002;

        add_value(dinamic_vertex, static_vertex);
    }
};
