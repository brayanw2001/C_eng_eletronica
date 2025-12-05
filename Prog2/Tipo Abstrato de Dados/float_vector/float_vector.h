typedef struct FloatVector FloatVector;

FloatVector *create(int capacity);
void destroy(FloatVector **vec_ref);
int size(const FloatVector *vec);
int capacity(const FloatVector *vec);
float at(const FloatVector *, int index);
float get(const FloatVector *, int index);
void append(FloatVector *vec, float val);
void set(FloatVector *vec, int index, float val);
void print(const FloatVector *vec);