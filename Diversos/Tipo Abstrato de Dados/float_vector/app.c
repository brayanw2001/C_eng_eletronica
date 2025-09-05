#include"float_vector.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
    FloatVector* vec = create(5);
    
    append(vec, 0.0);
    append(vec, 1.0);
    append(vec, 2.0);
    append(vec, 3.0);
    append(vec, 4.0);
    
    print(vec);
    
    destroy(&vec);
    return 0;
}