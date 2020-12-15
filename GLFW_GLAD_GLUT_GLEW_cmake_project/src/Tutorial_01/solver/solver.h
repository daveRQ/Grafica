#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//----------------------------------------------------------------------

typedef vector<int> vi;

//----------------------------------------------------------------------

int applicableMoves[] = { 0, 262143, 259263, 74943, 74898 };

// TODO: Encode as strings, e.g. for U use "ABCDABCD"

int affectedCubies[][8] = {
  {  0,  1,  2,  3,  0,  1,  2,  3 },   // U
  {  4,  7,  6,  5,  4,  5,  6,  7 },   // D
  {  0,  9,  4,  8,  0,  3,  5,  4 },   // F
  {  2, 10,  6, 11,  2,  1,  7,  6 },   // B
  {  3, 11,  7,  9,  3,  2,  6,  5 },   // L
  {  1,  8,  5, 10,  1,  0,  4,  7 },   // R
};

vi applyMove(int move, vi state) {
    int turns = move % 3 + 1;
    int face = move / 3;
    while (turns--) {
        vi oldState = state;
        for (int i = 0; i < 8; i++) {
            int isCorner = i > 3;
            int target = affectedCubies[face][i] + isCorner * 12;
            int killer = affectedCubies[face][(i & 3) == 3 ? i - 3 : i + 1] + isCorner * 12;;
            int orientationDelta = (i < 4) ? (face > 1 && face < 4) : (face < 2) ? 0 : 2 - (i & 1);
            state[target] = oldState[killer];
            //state[target+20] = (oldState[killer+20] + orientationDelta) % (2 + isCorner);
            state[target + 20] = oldState[killer + 20] + orientationDelta;
            if (!turns)
                state[target + 20] %= 2 + isCorner;
        }
    }
    return state;
}

int inverse(int move) {
    return move + 2 - 2 * (move % 3);
}

//----------------------------------------------------------------------

int phase;

//----------------------------------------------------------------------

vi id(vi state) {

    //--- Phase 1: Edge orientations.
    if (phase < 2)
        return vi(state.begin() + 20, state.begin() + 32);

    //-- Phase 2: Corner orientations, E slice edges.
    if (phase < 3) {
        vi result(state.begin() + 31, state.begin() + 40);
        for (int e = 0; e < 12; e++)
            result[0] |= (state[e] / 8) << e;
        return result;
    }

    //--- Phase 3: Edge slices M and S, corner tetrads, overall parity.
    if (phase < 4) {
        vi result(3);
        for (int e = 0; e < 12; e++)
            result[0] |= ((state[e] > 7) ? 2 : (state[e] & 1)) << (2 * e);
        for (int c = 0; c < 8; c++)
            result[1] |= ((state[c + 12] - 12) & 5) << (3 * c);
        for (int i = 12; i < 20; i++)
            for (int j = i + 1; j < 20; j++)
                result[2] ^= state[i] > state[j];
        return result;
    }

    //--- Phase 4: The rest.
    return state;
}

//----------------------------------------------------------------------

vector<string> solve(string start[], string goal[]) {

    vector<string> moves;


    //--- Prepare current (start) and goal state.
    vi currentState(40), goalState(40);
    for (int i = 0; i < 20; i++) {

        //--- Goal state.
        goalState[i] = i;

        //--- Current (start) state.
        string cubie = start[i];
        while ((currentState[i] = find(goal, goal + 20, cubie) - goal) == 20) {
            cubie = cubie.substr(1) + cubie[0];
            //cout<<  "cubie: " << cubie<<endl;
            currentState[i + 20]++;
        }
    }


    //--- Dance the funky Thistlethwaite...
    while (++phase < 5) {

        //--- Compute ids for current and goal state, skip phase if equal.
        vi currentId = id(currentState), goalId = id(goalState);
        if (currentId == goalId) {
            //cout<<currentState.size()<<endl;

            continue;
        }

        //--- Initialize the BFS queue.
        queue<vi> q;
        q.push(currentState);
        q.push(goalState);

        //--- Initialize the BFS tables.
        map<vi, vi> predecessor;
        map<vi, int> direction, lastMove;
        direction[currentId] = 1;
        direction[goalId] = 2;

        //--- Dance the funky bidirectional BFS...
        while (1) {

            //--- Obtenga el estado de la cola, calcule su ID y obtenga su direcci�n.
            vi oldState = q.front();
            q.pop();
            vi oldId = id(oldState);
            int& oldDir = direction[oldId];

            //--- Aplique todos los movimientos aplicables y maneje el nuevo estado.
            for (int move = 0; move < 18; move++) {
                if (applicableMoves[phase] & (1 << move)) {

                    //--- Apply the move.
                    vi newState = applyMove(move, oldState);
                    vi newId = id(newState);
                    int& newDir = direction[newId];

                    //--- Have we seen this state (id) from the other direction already?
                    //--- I.e. have we found a connection?
                    if (newDir && newDir != oldDir) {

                        //--- Make oldId represent the forwards and newId the backwards search state.
                        if (oldDir > 1) {
                            swap(newId, oldId);
                            move = inverse(move);
                        }

                        //--- Reconstruct the connecting algorithm.
                        vi algorithm(1, move);
                        while (oldId != currentId) {
                            algorithm.insert(algorithm.begin(), lastMove[oldId]);
                            oldId = predecessor[oldId];
                        }
                        while (newId != goalId) {
                            algorithm.push_back(inverse(lastMove[newId]));
                            newId = predecessor[newId];
                        }


                        //--- Print and apply the algorithm.
                        for (int i = 0; i < (int)algorithm.size(); i++) {
                            string move;
                            move += "UDFBLR"[algorithm[i] / 3];
                            move += to_string(algorithm[i] % 3 + 1);
                            // cout << move << ',';
                            moves.push_back(move);
                            // cout <<"movimiento "<<i+1<<":" << "UDFBLR"[algorithm[i]/3] << algorithm[i]%3+1<<endl;
                            currentState = applyMove(algorithm[i], currentState);
                        }

                        //--- Jump to the next phase.
                        goto nextPhasePlease;
                    }

                    //--- If we've never seen this state (id) before, visit it.
                    if (!newDir) {
                        q.push(newState);
                        newDir = oldDir;
                        lastMove[newId] = move;
                        predecessor[newId] = oldId;
                    }
                }
            }
        }
    nextPhasePlease:
        ;
    }

    phase = 0;
    //cout << "salio: " << endl;
    return moves;

}

/*
int main()
{
    string solucion[] = {
        "UF", "UR", "UB", "UL",
        "DF", "DR", "DB", "DL",
        "FR", "FL",
        "BR", "BL",
        "UFR", "URB", "UBL", "ULF",
        "DRF", "DFL", "DLB", "DBR"
    };
    ///FRONT 1  F1 F2
    string start_FRONT1[] = {
        "LF", "UR", "UB", "UL",
        "RF", "DR", "DB", "DL",
        "FU", "FD",
        "BR", "BL",
        "LFU", "URB", "UBL", "LDF",
        "RUF", "RFD", "DLB", "DBR"
    };
    ///FRONT 2  F2
    string start_FRONT2[] = {
        "DF", "UR", "UB", "UL",
        "UF", "DR", "DB", "DL",
        "FL", "FR",
        "BR", "BL",
        "DFL", "URB", "UBL", "DRF",
        "ULF", "UFR", "DLB", "DBR"
    };
    ///UP 1 U1, U2
    string start_UP[] = {
        "UR", "UB", "UL", "UF",
        "DF", "DR", "DB", "DL",
        "FR", "FL",
        "BR", "BL",
        "URB", "UBL", "ULF", "UFR",
        "DRF", "DFL", "DLB", "DBR"
    };


    vector<string> moves(solve(start_FRONT2, solucion));
    cout <<"MOVIMIENTOS: ";
    for (auto i : moves) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
*/
