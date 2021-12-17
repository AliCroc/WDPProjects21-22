// by AC, 11.2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _RADIUS 9
#define _EXIT_COORDINATE_X 0
#define _EXIT_COORDINATE_Y 0
#define _NUMBER_OF_AREAS 10

typedef enum { false, true } bool; // for compatibility
typedef enum { False = 0, True = 1, NA = 2 } CheckupMedium; 

// NA is short for non-applicable, this means that this information is irrevelent for described area;
// for example area A exists on both sides of OY axis, so if previous data matches required conditions,
// the is_to_right_of_or_on_yo_axis has no purpose here. To keep the code DRY I introduced NA so we could
// with less "if" statements still get the correct area

typedef struct {
    int x, y;
} Point;

typedef struct {
    char name;
    CheckupMedium is_above_square_function; // y > x^2 - 3
    CheckupMedium is_below_square_function; // y < x^2 - 3
    CheckupMedium is_above_sinus_function; // y > sin(x)
    CheckupMedium is_below_sinus_function; // y < sin(x)
    CheckupMedium is_above_or_on_xo_axis; // y >= 0
    CheckupMedium is_to_right_of_or_on_yo_axis; // x >= 0
} Area;

// function declarations
void savePointInput(Point *_point);
int checkIfExitCoorinatesWereUsed(Point *_point);
Area getPointsLocationArea(Point temp_point);
char getMatchingAreaSymbol(Area temp_area, Area areas[_NUMBER_OF_AREAS]);
void saveAreas();

bool checkIfIsInCircleRange(Point _point);
bool isPointAboveSquareFunction(Point _point);
bool isPointBelowSquareFunction(Point _point);
bool isPointAboveSinusFunction(Point _point);
bool isPointBelowSinusFunction(Point _point);
bool isPointAboveOrOnXAxis(Point _point);
bool isPointOnOrToTheRightOfYAxis(Point _point);
//

int main()
{
    printf("\n\tWitaj w moim programie!\n");
    Point temp_point;
    Area areas[_NUMBER_OF_AREAS] = {
         { 'A', True, False, True, False, True, NA },
         { 'B', False, True, True, False, True, True },
         { 'C', False, True, True, False, NA, False },
         { 'D', True, False, True, False, False, False },
         { 'E', True, False, False, True, True, True },
         { 'F', False, True, False, True, False, False },
         { 'G', True, False, False, True, False, False },
         { 'H', True, False, False, True, False, True },
         { 'I', False, True, False, True, True, True },
         { 'J', False, True, False, True, False, True },
     }; 
    Area final_area;
    char area_name = 'X';

    while(true) {
        savePointInput(&temp_point);
        if(checkIfIsInCircleRange(temp_point) == false) {
            printf("Punkt znajduje sie poza obszarami");
            continue;
        }

        if(checkIfExitCoorinatesWereUsed(&temp_point) == -1)
            break;

        final_area = getPointsLocationArea(temp_point);
        area_name = getMatchingAreaSymbol(final_area, areas);

        if(area_name == 'H' && temp_point.y < -2)
            printf("Punkt znajduje sie poza obszarami");

        else if (area_name != 'X')
            printf("\nPunkt o wspolrzednych %d, %d znajduje sie w obszarze %c\n", temp_point.x, temp_point.y, area_name);
            
        else 
            printf("Punkt znajduje sie na krzywej");
    }
    printf("Dziekuje za skorzystanie z mojego programu!");
}

void savePointInput(Point *_point) {
    int tx, ty;
    printf("\nPodaj prosze koordynaty swojego punktu (x, y)\n\t\t");
    scanf("%d %d", &tx, &ty);
    _point->x = tx;
    _point->y = ty;
    // printf("\nwsporzedne punktu: %d %d\n"); //debug
}

int checkIfExitCoorinatesWereUsed(Point *_point) {
    if(_point->x == _EXIT_COORDINATE_X && _point->y == _EXIT_COORDINATE_Y)
        return -1;
    return 1;
}

bool checkIfIsInCircleRange(Point _point) {
    if(_point.y > _RADIUS || _point.x > _RADIUS) 
        return false;
    return true;
}


Area getPointsLocationArea(Point temp_point) {
    Area temp_area;
    temp_area.is_above_square_function = isPointAboveSquareFunction(temp_point);
    temp_area.is_below_square_function = isPointBelowSquareFunction(temp_point);
    temp_area.is_above_sinus_function = isPointAboveSinusFunction(temp_point);
    temp_area.is_below_sinus_function = isPointBelowSinusFunction(temp_point);
    temp_area.is_above_or_on_xo_axis = isPointAboveOrOnXAxis(temp_point);
    temp_area.is_to_right_of_or_on_yo_axis = isPointOnOrToTheRightOfYAxis(temp_point);
    // printf("\ndane obszaru: %d %d %d %d %d %d  \n\n", temp_area.is_above_square_function,temp_area.is_below_square_function,temp_area.is_above_sinus_function, temp_area.is_below_sinus_function, temp_area.is_above_or_on_xo_axis, temp_area.is_to_right_of_or_on_yo_axis );  //debug
    return temp_area;
}

char getMatchingAreaSymbol(Area temp_area, Area areas[_NUMBER_OF_AREAS]) {
    int i;
    for(i = 0; i < _NUMBER_OF_AREAS; i++) {
            // printf("\nSPRAWDZANA STREFA: %c, warunki:\n %d %d %d %d %d %d \n",  areas[i].name, areas[i].is_above_square_function,areas[i].is_below_square_function,areas[i].is_above_sinus_function, areas[i].is_below_sinus_function, areas[i].is_above_or_on_xo_axis, areas[i].is_to_right_of_or_on_yo_axis );  //debug

        if(
            (temp_area.is_above_square_function == areas[i].is_above_square_function || areas[i].is_above_square_function == NA) &&
            (temp_area.is_below_square_function == areas[i].is_below_square_function || areas[i].is_below_square_function == NA) &&
            (temp_area.is_above_sinus_function == areas[i].is_above_sinus_function || areas[i].is_above_sinus_function == NA) &&
            (temp_area.is_below_sinus_function == areas[i].is_below_sinus_function || areas[i].is_below_sinus_function == NA) &&
            (temp_area.is_above_or_on_xo_axis == areas[i].is_above_or_on_xo_axis || areas[i].is_above_or_on_xo_axis == NA) &&
            (temp_area.is_to_right_of_or_on_yo_axis == areas[i].is_to_right_of_or_on_yo_axis || areas[i].is_to_right_of_or_on_yo_axis == NA)
          )
            return areas[i].name;
    }
    return 'X';
}

bool isPointAboveSquareFunction(Point _point) {
    if(_point.y > pow(_point.x, 2) - 3)
        return true;
    return false;
}

bool isPointBelowSquareFunction(Point _point) {
    if(_point.y < pow(_point.x, 2) - 3)
        return true;
    return false;
}

bool isPointAboveSinusFunction(Point _point) {
    if(_point.y > sin(_point.x))
        return true;
    return false;
}

bool isPointBelowSinusFunction(Point _point) {
    if(_point.y < sin(_point.x))
        return true;
    return false;
}

bool isPointAboveOrOnXAxis(Point _point) {
    if(_point.y >= 0)
        return true;
    return false;
}

bool isPointOnOrToTheRightOfYAxis(Point _point) {
    if(_point.x >= 0)
        return true;
    return false;
}
